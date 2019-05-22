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

#ifndef __RTOS_OS_FRONTEND_API_PERF_H__
#define __RTOS_OS_FRONTEND_API_PERF_H__

/**        
 * @ingroup groupCluster       
 */

/**        
 * @defgroup Perf Performance counters
 *
 * This API gives access to the core performance counters. Each core has a few performance counters which can be configured 
 * to count one event out of several available. An event is a cycle, an instruction, a cache miss and so on. The number of counters
 * limits the number of events which can be monitored at the same time and depends on the architecture and the platform.
 *
 * In addition, this API uses a few other HW mechanisms useful for monitoring performance such as timers.
 *
 * To use the API, a structure of type pi_perf_t must be allocated and passed to most of the calls. This structure
 * contains the desired configuration and is used to save the values of the performance counters.
 * It can be used by one core or several (if concurrent accesses are protected).
 * The idea is that the hardware counters can be reset, started and stopped in order to get the event values for
 * a specific period and this can then be cumulated to the performance structure.
 */

/**        
 * @addtogroup Perf
 * @{        
 */


/** \brief Configure performance counters.
 *
 * The set of events which can be activated at the same time depends on the architecture and the platform. On real chips (rather than with
 * the simulator), there is always only one counter. It is advisable to always use only one to be compatible with simulator and chip.
 *
 * At least PI_PERF_CYCLES and another event can be monitored at the same time as the first one is using the timer.
 *
 * \param perf  A pointer to the performance structure.
 * \param events A mask containing the events to activate. This is a bitfield, so events identifier must be used like 1 << PI_PERF_CYCLES.
 */
static inline void pi_perf_conf(unsigned events);



/** \brief Reset all hardware performance counters.
 *
 * All hardware performance counters are set to 0.
 * Note that this does not modify the value of the counters in the specified structure,
 * this must be done by calling pi_perf_init.
 *
 * \param perf  A pointer to the performance structure.
 */
static inline void pi_perf_reset();



/** \brief Start monitoring configured events.
 *
 * This function is useful for finely controlling the point where performance events start being monitored.
 * The counter retains its value between stop and start so it is possible to easily sum events for several
 * portions of code.
 *
 * \param perf  A pointer to the performance structure.
 */
static inline void pi_perf_start();



/** \brief Stop monitoring configured events.
 *
 * \param perf  A pointer to the performance structure.
 */
static inline void pi_perf_stop();




/** \brief Read a performance counter
 *
 * This does a direct read to the specified performance counter. Calling this functions is useful for getting
 * the performance counter with very low overhead (just few instructions).
 * 
 * \param id    The performance event identifier to read.
 * \return      The performance counter value.
 */
static inline unsigned int pi_perf_read(int id);

//!@}

#endif