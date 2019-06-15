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

#ifndef __PMSIS__DATA__DATA_H__
#define __PMSIS__DATA__DATA_H__

#include <zephyr.h>

struct pi_cluster_task_implem
{
  int pending;
  int core_mask;
};

struct pi_task_implem
{
  int kpoll;
  union {
  	struct k_work workitem;
  	struct k_delayed_work delayed_workitem;
  };
  struct k_poll_event event;
  struct k_poll_signal signal;
  struct pi_task *next;
  unsigned int data[6];
};

#define CLUSTER_TASK_IMPLEM struct pi_cluster_task_implem implem
#define PI_TASK_IMPLEM struct pi_task_implem implem
#define PMSIS_NO_INLINE_INCLUDE

#include "pmsis/data/udma.h"
#include "pmsis/data/cpi.h"
#include "pmsis/data/spi.h"
#include "pmsis/data/i2c.h"

#endif

