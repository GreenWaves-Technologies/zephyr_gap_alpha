/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __SOC_RISCV32_PULP_COMMON_PULPRT_WRAPPER_H__
#define __SOC_RISCV32_PULP_COMMON_PULPRT_WRAPPER_H__

#include "soc.h"
#include "alloc.h"

static inline void __rt_udma_register_channel_callback(int channel, void (*callback)(void *))
{
  pulp_soc_eu_register_udma_callback(channel, callback, NULL);
}

static inline void __rt_task_init(pi_task_t *task)
{
  task->done = 0;
}

static inline void __rt_task_create(pi_task_t *task)
{
  task_init(task);
}

static inline void __rt_task_init_from_cluster(pi_task_t *task)
{
  task->implem.kpoll = 0;
}

static inline int rt_irq_disable()
{
  return irq_lock();
}

static inline void rt_irq_restore(int state)
{
  irq_unlock(state);
}

static inline void rt_compiler_barrier() {
  __asm__ __volatile__ ("" : : : "memory");
}

static inline int __rt_cluster_lock(rt_fc_cluster_data_t *cluster)
{
  k_mutex_lock(&cluster->mutex, K_FOREVER);
  return 0;
}

static inline void __rt_cluster_unlock(rt_fc_cluster_data_t *cluster, int lock)
{
  k_mutex_unlock(&cluster->mutex);
}



#endif