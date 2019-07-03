/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <hal/pulp.h>
#include <zephyr.h>
#include <device.h>
#include <init.h>
#include <pmsis.h>
#include "alloc.h"
#include "implem/implem.h"

static inline void *cluster_tiny_addr(int cid, void *data)
{
  // TODO due to a compiler bug, we have to cast the tiny data to avoid the propagation of the tiny attribute
  return (void *)(ARCHI_CLUSTER_GLOBAL_ADDR(cid) + ((int)data & 0xFFF));
}

struct cluster_config {
};

struct cluster_data {
};

rt_fc_cluster_data_t clusters[NB_CLUSTERS];
pi_task_t *__rt_fc_cluster_data[NB_CLUSTERS];
L1_TINY_DATA rt_cluster_call_pool_t __rt_cluster_pool;
L1_TINY_DATA int __rt_cluster_nb_active_pe;

extern void __cluster_start();


static inline int rt_nb_pe()
{
  return ARCHI_CLUSTER_NB_PE;
}


static int cluster_init(struct device *device)
{
  ARG_UNUSED(device);

  IRQ_CONNECT(RT_FC_ENQUEUE_EVENT, 0,
        cluster_irq_handler, NULL, 0);
  irq_enable(RT_FC_ENQUEUE_EVENT);

  for (int cid=0; cid<NB_CLUSTERS; cid++)
  {
    rt_fc_cluster_data_t *cluster = &clusters[cid];
    cluster->cid = cid;
    cluster->enable_count = 0;
    k_mutex_init(&cluster->mutex);

    __rt_fc_cluster_data[cid] = NULL;
  }

  return 0;
}


int pi_cluster_open(struct pi_device *cluster_dev)
{
  struct cluster_driver_conf *conf = (struct cluster_driver_conf *)cluster_dev->config;

  rt_fc_cluster_data_t *cluster = &clusters[conf->id];
  cluster_dev->data = cluster;

  k_mutex_lock(&cluster->mutex, K_FOREVER);

  int cid = cluster->cid;
  cluster->enable_count++;
  cluster->stacks = NULL;

  if (cluster->enable_count == 1)
  {
    cluster_power_up();

    rt_cluster_call_pool_t *cluster_data = (rt_cluster_call_pool_t *)cluster_tiny_addr(cid, &__rt_cluster_pool);

    cluster->pool = cluster_data;
    cluster_data->first_call_fc = NULL;
    cluster_data->last_call_fc = NULL;
    cluster_data->first_call_fc_for_cl = NULL;

    // Initialize now the L1 allocator for this cluster as the metadata
    // are stored there and could not be accessed before.
    l1_alloc_init(cid);

    __asm__ __volatile__ ("" : : : "memory");

    for (int i=0; i<ARCHI_CLUSTER_NB_PE; i++)
    {
      plp_ctrl_core_bootaddr_set_remote(cid, i, ((int)__cluster_start) & 0xffffff00);
    }

    eoc_fetch_enable_remote(cid, (1<<ARCHI_CLUSTER_NB_PE) - 1);
  }

  k_mutex_unlock(&cluster->mutex);

  return 0;
}

void task_init(pi_task_t *task)
{
  task->done = 0;
  task->implem.kpoll = 1;
  k_poll_signal_init(&task->implem.signal);

  k_poll_event_init(&task->implem.event, K_POLL_TYPE_SIGNAL, K_POLL_MODE_NOTIFY_ONLY, &task->implem.signal);
}


int pi_cluster_close(struct pi_device *cluster_dev)
{
  return 0;
}


void pi_task_wait_on(struct pi_task *task)
{
  while(!task->done)
  {
    k_poll(&task->implem.event, 1, K_FOREVER);
  }
}


struct pi_task *pi_task_callback(struct pi_task *task, void (*callback)(void*), void *arg)
{
  __rt_task_create(task);
  task->id = PI_TASK_CALLBACK_ID;
  task->arg[0] = (uint32_t)callback;
  task->arg[1] = (uint32_t)arg;
  return task;
}



void pi_cluster_conf_init(struct cluster_driver_conf *conf)
{
  conf->id = 0;
}



void pi_open_from_conf(struct pi_device *device, void *conf)
{
  device->config = conf;
}

static inline void apb_soc_status_set(unsigned int value) {
  pulp_write32(ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_CORESTATUS_OFFSET, value | (1<<APB_SOC_STATUS_EOC_BIT));
}

void __platform_exit(int err)
{
  apb_soc_status_set(err);
}


void __rt_cluster_push_fc_event(struct pi_task *event)
{
  eu_mutex_lock(eu_mutex_addr(0));

  // First wait until the slot to post events is free
  while(__rt_fc_cluster_data[pi_cluster_id()] != NULL)
  {
    eu_evt_maskWaitAndClr(1<<RT_CLUSTER_CALL_EVT);
  }

  // Push the event and notify the FC with a HW evet in case it
  // is sleeping
  __rt_fc_cluster_data[pi_cluster_id()] = event;
#ifdef ITC_VERSION
  hal_itc_status_set(1<<RT_CLUSTER_CALL_EVT);
#else
  eu_evt_trig(eu_evt_trig_fc_addr(RT_CLUSTER_CALL_EVT), 0);
#endif

  eu_mutex_unlock(eu_mutex_addr(0));
}



static const struct cluster_config cluster_cfg = {
};

static struct cluster_data cluster_data = {
};

DEVICE_INIT(cluster, "cluster", &cluster_init,
    &cluster_data, &cluster_cfg,
    PRE_KERNEL_2, CONFIG_KERNEL_INIT_PRIORITY_DEVICE);



