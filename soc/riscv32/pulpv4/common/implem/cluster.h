/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna and GreenWaves Technologies
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __RT_IMPLEM_CLUSTER_H__
#define __RT_IMPLEM_CLUSTER_H__

#include "hal/eu/eu_v3.h"
#include "pmsis/cluster/cl_malloc.h"

static inline void *rt_alloc_cluster_wait(pi_cl_alloc_req_t *req)
{
  while((*(volatile char *)&req->done) == 0)
  {
    eu_evt_maskWaitAndClr(1<<RT_CLUSTER_CALL_EVT);
  }
  return req->result;
}

static inline void rt_free_cluster_wait(pi_cl_free_req_t *req)
{
  while((*(volatile char *)&req->done) == 0)
  {
    eu_evt_maskWaitAndClr(1<<RT_CLUSTER_CALL_EVT);
  }
}

static inline void *pi_cl_l2_malloc_wait(pi_cl_alloc_req_t *req)
{
  return rt_alloc_cluster_wait((pi_cl_alloc_req_t *)req);
}

static inline void pi_cl_l2_free_wait(pi_cl_free_req_t *req)
{
  rt_free_cluster_wait((pi_cl_free_req_t *)req);
}

static inline int pi_cl_team_nb_cores()
{
  return __FL1(pulp_read32(eu_bar_addr(0) + EU_HW_BARR_TRIGGER_MASK) + 1);
}

static inline void __cl_team_barrier() {
  eu_bar_trig_wait_clr(eu_bar_addr(0));
}

static inline void pi_cl_team_barrier() {
#ifdef __RT_USE_PROFILE
  int trace = __rt_pe_trace[pi_core_id()];
  gv_vcd_dump_trace(trace, 2);
#endif
  __cl_team_barrier();
#ifdef __RT_USE_PROFILE
  gv_vcd_dump_trace(trace, 1);
#endif
}

static inline void __cl_team_barrier_config(unsigned int core_mask)
{
#ifdef ARCHI_HAS_NO_BARRIER
  __rt_barrier_wait_mask = core_mask;
#else
  eu_bar_setup(eu_bar_addr(0), core_mask);
#endif
}

static inline void __cl_team_config(int nb_cores) {
  unsigned int core_mask = (1<<nb_cores) - 1;
  eu_dispatch_team_config(core_mask);
  __cl_team_barrier_config(core_mask);
}

#if !defined(ARCHI_HAS_CC)

static inline void pi_cl_team_fork(int nb_cores, void (*entry)(void *), void *arg)
{
#ifdef __RT_USE_PROFILE
  int trace = __rt_pe_trace[pi_core_id()];
  gv_vcd_dump_trace(trace, 1);
#endif

  if (nb_cores) __cl_team_config(nb_cores);
  eu_dispatch_push((int)entry);
  eu_dispatch_push((int)arg);
  entry(arg);

  __cl_team_barrier();

#ifdef __RT_USE_PROFILE
  gv_vcd_dump_trace(trace, 0);
#endif
}

#else

static inline void pi_cl_team_fork(int nb_cores, void (*entry)(void *), void *arg) {
  rt_team_offload(nb_cores, entry, arg);

  if (nb_cores == 0)
    nb_cores = rt_team_nb_cores();

  if (nb_cores == ARCHI_CLUSTER_NB_PE + 1)
    entry(arg);

  rt_team_offload_wait();
}

#endif

static inline void pi_cl_team_critical_enter()
{
#ifdef __RT_USE_PROFILE
  int trace = __rt_pe_trace[pi_core_id()];
  gv_vcd_dump_trace(trace, 3);
#endif

  eu_mutex_lock(eu_mutex_addr(0));
}

static inline void pi_cl_team_critical_exit()
{
#ifdef __RT_USE_PROFILE
  int trace = __rt_pe_trace[pi_core_id()];
  gv_vcd_dump_trace(trace, 1);
#endif

  eu_mutex_unlock(eu_mutex_addr(0));
}


#endif