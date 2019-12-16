/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __SOC_RISCV32_PULP_COMMON_PULPRT_WRAPPER_H__
#define __SOC_RISCV32_PULP_COMMON_PULPRT_WRAPPER_H__

#include "soc.h"
#include "alloc.h"
#include "cluster.h"

static inline void __rt_udma_register_channel_callback(int channel, void (*callback)(int event, void *), void *arg)
{
  pulp_soc_eu_register_udma_callback(channel, callback, arg);
}

static inline void __rt_udma_register_extra_callback(unsigned int event, void (*callback)(int event, void *), void *arg)
{
  pulp_soc_eu_register_udma_extra_callback(event, callback, arg);
}

static inline void __rt_udma_channel_reg_data(int channel_id, void *data)
{
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

static inline unsigned int __rt_freq_periph_get()
{
  return 50000000;
}



#endif