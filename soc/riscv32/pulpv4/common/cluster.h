/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __SOC_RISCV32_PULP_COMMON_CLUSTER_H__
#define __SOC_RISCV32_PULP_COMMON_CLUSTER_H__

void __rt_cluster_push_fc_event(struct pi_task *event);

void handle_end_of_task(pi_task_t *task);

void task_init(pi_task_t *task);

static inline void __rt_cluster_notif_req_done(int cid)
{
  eu_evt_trig(eu_evt_trig_cluster_addr(cid, RT_CLUSTER_CALL_EVT), 0);
}

#endif
