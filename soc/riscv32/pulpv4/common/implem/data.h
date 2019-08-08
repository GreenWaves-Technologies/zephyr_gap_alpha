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

#ifndef __RT_IMPLEM_DATA_H__
#define __RT_IMPLEM_DATA_H__

#include "pmsis/task.h"

/// @cond IMPLEM

struct pi_cl_alloc_req_s {
  void *result;
  int flags;
  int size;
  pi_task_t event;
  char done;
  char cid;
};

struct pi_cl_free_req_s {
  void *result;
  int flags;
  int size;
  void *chunk;
  pi_task_t event;
  char done;
  char cid;
};

struct pi_cl_hyper_req_s {
  struct pi_device *device;
  void *addr;
  uint32_t hyper_addr;
  uint32_t size;
  int32_t stride;
  uint32_t length;
  pi_task_t event;
  struct pi_cl_hyper_req_s *next;
  int done;
  unsigned char cid;
  unsigned char is_write;
  unsigned char is_2d;
};

struct pi_cl_hyperram_alloc_req_s {
  struct pi_device *device;
  uint32_t result;
  uint32_t  size;
  pi_task_t event;
  char done;
  char cid;
};

struct pi_cl_hyperram_free_req_s {
  struct pi_device *device;
  uint32_t result;
  uint32_t size;
  uint32_t chunk;
  pi_task_t event;
  char done;
  char cid;
};

#define L1_DATA __attribute__((section(".l1_ram")))
#define L1_TINY_DATA __attribute__ ((tiny)) __attribute__((section(".l1_tiny_ram")))
#define L2_DATA __attribute__((section(".l2_ram")))
#define PI_L2 L2_DATA
// Tiny data are not used on Zephyr, this would need to modify the linker script to support it
#define RT_FC_TINY_DATA

#endif
