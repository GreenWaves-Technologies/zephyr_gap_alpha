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

#ifndef __PMSIS__H__
#define __PMSIS__H__

#include <zephyr.h>

struct pi_cluster_task_implem
{
  int pending;
  int core_mask;
};

struct pi_task_implem
{
  int kpoll;
  struct k_work workitem;
  struct k_poll_event event;
  struct k_poll_signal signal;
  struct pi_task *next;
  unsigned int data[6];
};


#define CLUSTER_TASK_IMPLEM struct pi_cluster_task_implem implem
#define PI_TAsK_IMPLEM struct pi_task_implem implem
#define PMSIS_NO_INLINE_INCLUDE

#include "pmsis.h"

#include "pmsis_cluster/cluster_sync/fc_to_cl_delegate.h"
#include "pmsis_cluster/cl_malloc.h"
#include "rtos/pmsis_driver_core_api/pmsis_driver_core_api.h"
#include "rtos/event_kernel/event_kernel.h"
#include "rtos/os_frontend_api/pmsis_task.h"
#include "rtos/malloc/pmsis_malloc.h"
#include "rtos/malloc/pmsis_l1_malloc.h"
#include "rtos/malloc/pmsis_l2_malloc.h"
#include "hyperbus/hyperram.h"

#include "implem/implem.h"

extern int pmsis_exit_value;

static inline int pmsis_kickoff(void *arg)
{
  ((void (*)())arg)();
  return 0;
}

void __platform_exit(int err);

static inline void pmsis_exit(int err)
{
  __platform_exit(err);
}


#endif

