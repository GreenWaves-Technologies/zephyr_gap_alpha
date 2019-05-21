/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __SOC_RISCV32_PULP_COMMON_CLUSTER_H__
#define __SOC_RISCV32_PULP_COMMON_CLUSTER_H__

typedef struct
{
  struct pi_cluster_task *first_call_fc_for_cl;
  struct pi_cluster_task *first_call_fc;
  struct pi_cluster_task *last_call_fc;
} rt_cluster_call_pool_t;

typedef struct {
  int cid;
  struct k_mutex mutex;
  int enable_count;
  rt_cluster_call_pool_t *pool;
  void *stacks;
  int stacks_size;
} rt_fc_cluster_data_t;

extern pi_task_t *__rt_fc_cluster_data[NB_CLUSTERS];
extern rt_fc_cluster_data_t clusters[NB_CLUSTERS];

void __rt_cluster_push_fc_event(struct pi_task *event);

void handle_end_of_task(pi_task_t *task);

void task_init(pi_task_t *task);

static inline void __rt_cluster_notif_req_done(int cid)
{
  eu_evt_trig(eu_evt_trig_cluster_addr(cid, RT_CLUSTER_CALL_EVT), 0);
}


void cluster_irq_handler(void *arg);

#endif
