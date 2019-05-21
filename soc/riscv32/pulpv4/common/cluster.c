/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <drivers/pulp/cluster.h>
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

typedef struct
{
  struct pi_cluster_task *first_call_fc_for_cl;
  struct pi_cluster_task *first_call_fc;
  struct pi_cluster_task *last_call_fc;
} cl_cluster_data_t;

typedef struct {
  int cid;
  struct k_mutex mutex;
  int enable_count;
  cl_cluster_data_t *cl_data;
  void *stacks;
  int stacks_size;
} cluster_data_t;

static cluster_data_t clusters[NB_CLUSTERS];
pi_task_t *cluster_tasks[NB_CLUSTERS];
L1_TINY_DATA cl_cluster_data_t cl_cluster_data;
L1_TINY_DATA int cluster_nb_active_pe;

extern void __cluster_start();


static inline int rt_nb_pe()
{
  return ARCHI_CLUSTER_NB_PE;
}

static inline void rt_compiler_barrier() {
  __asm__ __volatile__ ("" : : : "memory");
}


static void end_of_task_handler(struct k_work *work)
{
  pi_task_t *task = (pi_task_t *)((intptr_t)work - (intptr_t)&(((pi_task_t *)NULL)->implem.workitem));
  ((void (*)(void *))task->arg[0])((void *)task->arg[1]);
}

void handle_end_of_task(pi_task_t *task)
{
  task->done = 1;
  if (task->implem.kpoll)
  {
    k_poll_signal_raise(&task->implem.signal, 0);
  }

  if (task->id == FC_TASK_CALLBACK_ID)
  {
    k_work_init(&task->implem.workitem, end_of_task_handler);
    k_work_submit(&task->implem.workitem);
  }
}

static void cluster_irq_handler(struct device *device)
{
  for (int cid=0; cid<NB_CLUSTERS; cid++)
  {
    pi_task_t *task = cluster_tasks[cid];
    if (task != NULL)
    {
      // Everytime a task is finished, first check if we can update the queue head
      // as it is not updated by cluster side to avoid race conditions.
      // At least this task won't be there anymore after we update, and maybe even
      // more tasks, which is not an issue, as we compare against the head.
      cluster_data_t *cluster = &clusters[cid];
      cl_cluster_data_t *cl_cluster = cluster->cl_data;

      struct pi_cluster_task *current = cl_cluster->first_call_fc;
      while (current && current->implem.pending == 0)
      {
        current = current->next;
      }

      if (current == NULL)
      {
        cl_cluster->first_call_fc = NULL;
        cl_cluster->last_call_fc = NULL;
      }
      else
      {
        cl_cluster->first_call_fc = current->next;
      }

      cluster_tasks[cid] = NULL;

      handle_end_of_task(task);
    }
  }
}

static int cluster_init(struct device *device)
{
  ARG_UNUSED(device);

  IRQ_CONNECT(FC_TASK_END, 0,
        cluster_irq_handler, NULL, 0);
  irq_enable(FC_TASK_END);

  for (int cid=0; cid<NB_CLUSTERS; cid++)
  {
    cluster_data_t *cluster = &clusters[cid];
    cluster->cid = cid;
    cluster->enable_count = 0;
    k_mutex_init(&cluster->mutex);

    cluster_tasks[cid] = NULL;
  }

  return 0;
}


int pi_cluster_open(struct pi_device *cluster_dev)
{
  struct cluster_driver_conf *conf = (struct cluster_driver_conf *)cluster_dev->config;

  cluster_data_t *cluster = &clusters[conf->id];
  cluster_dev->data = cluster;

  k_mutex_lock(&cluster->mutex, K_FOREVER);

  int cid = cluster->cid;
  cluster->enable_count++;
  cluster->stacks = NULL;

  if (cluster->enable_count == 1)
  {
    cluster_power_up();

    cl_cluster_data_t *cluster_data = (cl_cluster_data_t *)cluster_tiny_addr(cid, &cl_cluster_data);

    cluster->cl_data = cluster_data;
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

int pi_cluster_send_task_to_cl_async(struct pi_device *device, struct pi_cluster_task *task, pi_task_t *async_task)
{
  cluster_data_t *cluster = device->data;

  task_init(async_task);

  k_mutex_lock(&cluster->mutex, K_FOREVER);

  cluster_data_t *data = (cluster_data_t *)device->data;
  cl_cluster_data_t *cl_data = data->cl_data;

  if (task->nb_cores == 0)
    task->nb_cores = rt_nb_pe();

  if (task->stacks == NULL)
  {
    if (task->stack_size == 0)
    {
      task->stack_size = 0x400;
      task->slave_stack_size = 0x400;
    }

    if (task->slave_stack_size == 0)
      task->slave_stack_size = task->stack_size;

    int stacks_size = task->stack_size + task->slave_stack_size * (task->nb_cores - 1);

    if (data->stacks == NULL || stacks_size != data->stacks_size)
    {
      if (data->stacks)
        rt_free(&alloc_l1[cluster->cid], data->stacks, data->stacks_size);

      data->stacks_size = stacks_size;
      data->stacks = rt_alloc(&alloc_l1[cluster->cid], stacks_size);
      if (data->stacks == NULL)
        goto error;
    }

    task->stacks = data->stacks;
  }

  async_task->done = 0;

  task->completion_callback = async_task;
#ifdef ARCHI_HAS_CC
  task->implem.core_mask = (1<<(task->nb_cores-1)) - 1;
#else
  task->implem.core_mask = (1<<task->nb_cores) - 1;
#endif

  task->next = NULL;

  rt_compiler_barrier();

  if (cl_data->last_call_fc)
  {
    cl_data->last_call_fc->next = task;
  }
  else
  {
    cl_data->first_call_fc = task;
  }

  cl_data->last_call_fc = task;

  rt_compiler_barrier();
  
  if (cl_data->first_call_fc_for_cl == NULL)
    cl_data->first_call_fc_for_cl = task;

  rt_compiler_barrier();
  eu_evt_trig(eu_evt_trig_cluster_addr(data->cid, RT_CLUSTER_CALL_EVT), 0);

  k_mutex_unlock(&cluster->mutex);

  return 0;

error:
  k_mutex_unlock(&cluster->mutex);
  return -1;
}


int pi_cluster_send_task_to_cl(struct pi_device *device, struct pi_cluster_task *task)
{
  pi_task_t fc_task;

  pi_task(&fc_task);
  task_init(&fc_task);

  if (pi_cluster_send_task_to_cl_async(device, task, &fc_task))
  {
    return -1;
  }

  pi_wait_on_task(&fc_task);

  return 0;
}



int pi_cluster_close(struct pi_device *cluster_dev)
{
  return 0;
}


void pi_wait_on_task(struct pi_task *task)
{
  while(!task->done)
  {
    k_poll(&task->implem.event, 1, K_FOREVER);
  }
}


struct pi_task *pi_task_callback(struct pi_task *task, void (*callback)(void*), void *arg)
{
  task->id = FC_TASK_CALLBACK_ID;
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
  while(cluster_tasks[pi_cluster_id()] != NULL)
  {
    eu_evt_maskWaitAndClr(1<<RT_CLUSTER_CALL_EVT);
  }

  // Push the event and notify the FC with a HW evet in case it
  // is sleeping
  cluster_tasks[pi_cluster_id()] = event;
#ifdef ITC_VERSION
  hal_itc_status_set(1<<RT_CLUSTER_CALL_EVT);
#else
  eu_evt_trig(eu_evt_trig_fc_addr(RT_CLUSTER_CALL_EVT), 0);
#endif

  eu_mutex_unlock(eu_mutex_addr(0));
}

void pi_yield()
{
  k_yield();
}



static const struct cluster_config cluster_cfg = {
};

static struct cluster_data cluster_data = {
};

DEVICE_INIT(cluster, "cluster", &cluster_init,
    &cluster_data, &cluster_cfg,
    PRE_KERNEL_2, CONFIG_KERNEL_INIT_PRIORITY_DEVICE);



