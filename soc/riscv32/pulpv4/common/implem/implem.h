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



//#include "rt/implem/utils.h"
#include "implem/hyperram.h"
//#include "rt/implem/dma.h"
#include "implem/cluster.h"

/// @endcond

#endif
