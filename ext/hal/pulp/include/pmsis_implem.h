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

#ifndef __PMSIS_IMPLEM_H__
#define __PMSIS_IMPLEM_H__

#include "implem/implem.h"
#include "pmsis/implem/implem.h"

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

