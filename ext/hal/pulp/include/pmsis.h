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


#include "pmsis/data/data.h"

#include "pmsis_cluster/cluster_sync/fc_to_cl_delegate.h"
#include "pmsis_cluster/cl_malloc.h"
#include "rtos/pmsis_driver_core_api/pmsis_driver_core_api.h"
#include "rtos/event_kernel/event_kernel.h"
#include "rtos/os_frontend_api/pmsis_task.h"
#include "rtos/malloc/pmsis_malloc.h"
#include "rtos/malloc/pmsis_l1_malloc.h"
#include "rtos/malloc/pmsis_l2_malloc.h"
#include "drivers/perf.h"
#include "chips/gap8/drivers/gap8_perf.h"
#include "drivers/hyperbus.h"
#include "drivers/cpi.h"
#include "drivers/i2c.h"
#include "drivers/spi.h"

#include "pmsis/implem/implem.h"

#endif

