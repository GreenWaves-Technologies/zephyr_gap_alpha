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

#ifndef __RT_DATA_SPIM_H__
#define __RT_DATA_SPIM_H__

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  pi_task_t *pending_copy;
  pi_task_t *waiting_first;
  pi_task_t *waiting_last;
  unsigned int udma_cmd[4];
  int open_count;
  int id;
} pi_spim_t;

#endif

#define PI_SPIM_T_PENDING_COPY      0
#define PI_SPIM_T_WAITING_FIRST     4
#define PI_SPIM_T_WAITING_LAST      8

#endif
