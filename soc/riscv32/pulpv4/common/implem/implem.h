/*
 * Copyright (C) 2018 ETH Zurich and University of Bologna and
 * GreenWaves Technologies
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

#ifndef __RT_IMPLEM_IMPLEM_H__
#define __RT_IMPLEM_IMPLEM_H__

/// @cond IMPLEM

#include "implem/data.h"

#include "hal/riscv/riscv_v4.h"


static inline uint32_t pi_core_id()
{
  return hal_core_id();
}

static inline uint32_t pi_cluster_id()
{
  return hal_cluster_id();
}

static inline uint32_t pi_nb_cluster_cores()
{
  return ARCHI_CLUSTER_NB_PE;
}

static inline uint32_t pi_is_fc()
{
  return pi_cluster_id() == ARCHI_FC_CID;
}

void __rt_event_handle_end_of_task(pi_task_t *task);


#include "hal/udma/udma_v2.h"
#include "hal/soc_eu/soc_eu_v1.h"
#include "hal/eu/eu_v3.h"
#include "hal/udma/hyper/udma_hyper_v1.h"

#include "extern_alloc.h"

#include "../cluster.h"

#include "pulprt_wrapper.h"

//#include "rt/implem/utils.h"
#include "implem/hyperram.h"
//#include "rt/implem/dma.h"
#include "implem/cluster.h"

static inline struct pi_task *pi_task(struct pi_task *task)
{
  __rt_task_create(task);
  task->id = FC_TASK_NONE_ID;
  task->arg[0] = (uint32_t)0;
  return task;
}

/// @endcond

#endif
