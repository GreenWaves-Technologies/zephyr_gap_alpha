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

#define NB_CLUSTERS 1

#define DEFAULT_MASTER_STACK_SIZE 2048
#define DEFAULT_SLAVE_STACK_SIZE 512
#define DEFAULT_STACKS_SIZE (DEFAULT_MASTER_STACK_SIZE + (ARCHI_CLUSTER_NB_PE-1)*DEFAULT_SLAVE_STACK_SIZE)

struct cluster_config {
};

struct cluster_data_t {
};

static struct cluster clusters[NB_CLUSTERS];

static void *default_stacks;

extern void __cluster_start();

__attribute__ ((tiny)) __attribute__((section(".l1_tiny_ram"))) struct cluster_task *cluster_first_task_cl;

static struct cluster_task *cluster_first_task;
static struct cluster_task *cluster_last_task;


struct cluster *cluster_get(struct device *device, int cid)
{
  if (cid >= NB_CLUSTERS)
    return NULL;

  return &clusters[cid];
}

static inline u32_t cluster_tiny_to_global(int cid, u32_t data)
{
  // TODO due to a compiler bug, we have to cast the tiny data to avoid the propagation of the tiny attribute
  return ARCHI_CLUSTER_GLOBAL_ADDR(cid) + (data & 0xFFF);
}

int cluster_enable(struct cluster *cluster)
{
  k_mutex_lock(&cluster->mutex, K_FOREVER);

  int cid = cluster->cid;
  cluster->enable_count++;

  if (cluster->enable_count == 1)
  {
    cluster_power_up();

    struct cluster_task **cluster_first_task_cl_g = (struct cluster_task **)(cluster_tiny_to_global(cid, (u32_t)&cluster_first_task_cl));

    *cluster_first_task_cl_g = NULL;
    cluster_first_task = NULL;

    // Initialize now the L1 allocator for this cluster as the metadata
    // are stored there and could not be accessed before.
    cluster_alloc_init();

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

int cluster_send_task_async(struct cluster *cluster, struct cluster_task *cl_task, struct k_poll_signal *signal)
{
  unsigned int key;
  int cid = cluster->cid;

  struct cluster_task **cluster_first_task_cl_g = (struct cluster_task **)(cluster_tiny_to_global(cid, (u32_t)&cluster_first_task_cl));

  cl_task->cid = cid;
  cl_task->next = NULL;
  cl_task->signal = signal;
  cl_task->pending = 1;

  if (cl_task->nb_cores == 0)
    cl_task->nb_cores = ARCHI_CLUSTER_NB_PE;

  // Give default stacks to the task if no stack is specified
  if (cl_task->stacks == NULL)
  {
    // Allocate the stacks if they are not yet allocated
    if (default_stacks == NULL)
    {
      default_stacks = cluster_alloc(cluster, DEFAULT_STACKS_SIZE);
      if (default_stacks == NULL)
        return -1;
    }

    cl_task->master_stack_size = DEFAULT_MASTER_STACK_SIZE;
    cl_task->slave_stack_size = DEFAULT_SLAVE_STACK_SIZE;

    cl_task->stacks = default_stacks;
  }

  key = irq_lock();

  if (*cluster_first_task_cl_g == NULL)
  {
    *cluster_first_task_cl_g = cl_task;
  }

  if (cluster_first_task == NULL)
  {
    cluster_first_task = cl_task;
  }
  else
  {
    cluster_last_task->next = cl_task;
  }

  cluster_last_task = cl_task;

  irq_unlock(key);

  // Trigger an event on cluster side in case it is sleeping
  eu_evt_trig(eu_evt_trig_cluster_addr(cid, CLUSTER_CALL_EVT), 0);

  return 0;
}

int cluster_send_task(struct cluster *cluster, struct cluster_task *cl_task)
{
  struct k_poll_signal async_sig = K_POLL_SIGNAL_INITIALIZER(async_sig);
  struct k_poll_event async_evt =
        K_POLL_EVENT_INITIALIZER(K_POLL_TYPE_SIGNAL,
                                 K_POLL_MODE_NOTIFY_ONLY,
                                 &async_sig);

  if (cluster_send_task_async(cluster, cl_task, &async_sig) != 0)
    return -1;

  k_poll(&async_evt, 1, K_FOREVER);

  return 0;
}

int cluster_disable(struct cluster *cluster)
{
  return 0;
}

void cluster_entry_stub(struct cluster_task *cl_task)
{
  cl_task->entry(cl_task);
}

static void cluster_irq_handler(struct device *device)
{
  struct cluster_task *task = cluster_first_task;

  while (task && !task->pending)
  {                        
    k_poll_signal_raise(task->signal, 0);

    cluster_first_task = task->next;
    task = cluster_first_task;
  }
}

static int cluster_init(struct device *device)
{
  ARG_UNUSED(device);

  default_stacks = NULL;

  IRQ_CONNECT(FC_TASK_END, 0,
        cluster_irq_handler, NULL, 0);
  irq_enable(FC_TASK_END);

  for (int cid=0; cid<NB_CLUSTERS; cid++)
  {
    struct cluster *cluster = &clusters[cid];
    cluster->cid = cid;
    cluster->enable_count = 0;
    k_mutex_init(&cluster->mutex);
  }

  return 0;
}

static const struct cluster_config cluster_cfg = {
};

static struct cluster_data_t cluster_data = {
};

DEVICE_INIT(cluster, "cluster", &cluster_init,
    &cluster_data, &cluster_cfg,
    PRE_KERNEL_2, CONFIG_KERNEL_INIT_PRIORITY_DEVICE);
