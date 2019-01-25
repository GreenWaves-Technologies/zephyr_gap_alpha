
/* THIS FILE HAS BEEN GENERATED, DO NOT MODIFY IT.
 */

/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna
 * and GreenWaves Technologies
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

#ifndef __INCLUDE_ARCHI_EU_EU_V3_NEW_H__
#define __INCLUDE_ARCHI_EU_EU_V3_NEW_H__

#ifndef LANGUAGE_ASSEMBLY

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// Input event mask configuration register.
#define EU_EVT_MASK_OFFSET                       0x0

// Input event mask update command register with bitwise AND operation.
#define EU_EVT_MASK_AND_OFFSET                   0x4

// Input event mask update command register with bitwise OR operation.
#define EU_EVT_MASK_OR_OFFSET                    0x8

// Interrupt request mask configuration register.
#define EU_IRQ_MASK_OFFSET                       0xc

// Interrupt request mask update command register with bitwise AND operation.
#define EU_IRQ_MASK_AND_OFFSET                   0x10

// Interrupt request mask update command register with bitwise OR operation.
#define EU_IRQ_MASK_OR_OFFSET                    0x14

// Cluster cores clock status register.
#define EU_CLOCK_STATUS_OFFSET                   0x18

// Pending input events status register.
#define EU_EVENT_BUFFER_OFFSET                   0x1c

// Pending input events status register with EVT_MASK applied.
#define EU_EVENT_BUFFER_MASKED_OFFSET            0x20

// Pending input events status register with IRQ_MASK applied.
#define EU_EVENT_BUFFER_IRQ_MASKED_OFFSET        0x24

// Pending input events status clear command register.
#define EU_EVENT_BUFFER_CLEAR_OFFSET             0x28

// Software events cluster cores destination mask configuration register.
#define EU_SW_EVENT_MASK_OFFSET                  0x2c

// Software events cluster cores destination mask update command register with bitwise AND operation.
#define EU_SW_EVENT_MASK_AND_OFFSET              0x30

// Software events cluster cores destination mask update command register with bitwise OR operation.
#define EU_SW_EVENT_MASK_OR_OFFSET               0x34

// Input event wait command register.
#define EU_EVENT_WAIT_OFFSET                     0x38

// Input event wait and clear command register.
#define EU_EVENT_WAIT_CLEAR_OFFSET               0x3c

// Hardware task dispatcher push command register.
#define EU_HW_DISPATCH_PUSH_TASK_OFFSET          0x0

// Hardware task dispatcher pop command register.
#define EU_HW_DISPATCH_POP_TASK_OFFSET           0x0

// Hardware task dispatcher cluster core team configuration register.
#define EU_HW_DISPATCH_PUSH_TEAM_CONFIG_OFFSET   0x4

// Hardware mutex 0 non-blocking put command register.
#define EU_HW_MUTEX_0_MSG_PUT_OFFSET             0x0

// Hardware mutex 0 blocking get command register.
#define EU_HW_MUTEX_0_MSG_GET_OFFSET             0x0

// Hardware mutex 1 non-blocking put command register.
#define EU_HW_MUTEX_1_MSG_PUT_OFFSET             0x4

// Hardware mutex 1 blocking get command register.
#define EU_HW_MUTEX_1_MSG_GET_OFFSET             0x4

// Cluster Software event 0 trigger command register.
#define EU_SW_EVENT_0_TRIG_OFFSET                0x0

// Cluster Software event 1 trigger command register.
#define EU_SW_EVENT_1_TRIG_OFFSET                0x4

// Cluster Software event 2 trigger command register.
#define EU_SW_EVENT_2_TRIG_OFFSET                0x8

// Cluster Software event 3 trigger command register.
#define EU_SW_EVENT_3_TRIG_OFFSET                0xc

// Cluster Software event 4 trigger command register.
#define EU_SW_EVENT_4_TRIG_OFFSET                0x10

// Cluster Software event 5 trigger command register.
#define EU_SW_EVENT_5_TRIG_OFFSET                0x14

// Cluster Software event 6 trigger command register.
#define EU_SW_EVENT_6_TRIG_OFFSET                0x18

// Cluster Software event 7 trigger command register.
#define EU_SW_EVENT_7_TRIG_OFFSET                0x1c

// Cluster Software event 0 trigger and wait command register.
#define EU_SW_EVENT_0_TRIG_WAIT_OFFSET           0x0

// Cluster Software event 1 trigger and wait command register.
#define EU_SW_EVENT_1_TRIG_WAIT_OFFSET           0x4

// Cluster Software event 2 trigger and wait command register.
#define EU_SW_EVENT_2_TRIG_WAIT_OFFSET           0x8

// Cluster Software event 3 trigger and wait command register.
#define EU_SW_EVENT_3_TRIG_WAIT_OFFSET           0xc

// Cluster Software event 4 trigger and wait command register.
#define EU_SW_EVENT_4_TRIG_WAIT_OFFSET           0x10

// Cluster Software event 5 trigger and wait command register.
#define EU_SW_EVENT_5_TRIG_WAIT_OFFSET           0x14

// Cluster Software event 6 trigger and wait command register.
#define EU_SW_EVENT_6_TRIG_WAIT_OFFSET           0x18

// Cluster Software event 7 trigger and wait command register.
#define EU_SW_EVENT_7_TRIG_WAIT_OFFSET           0x1c

// Cluster Software event 0 trigger, wait and clear command register.
#define EU_SW_EVENT_0_TRIG_WAIT_CLEAR_OFFSET     0x0

// Cluster Software event 1 trigger, wait and clear command register.
#define EU_SW_EVENT_1_TRIG_WAIT_CLEAR_OFFSET     0x4

// Cluster Software event 2 trigger, wait and clear command register.
#define EU_SW_EVENT_2_TRIG_WAIT_CLEAR_OFFSET     0x8

// Cluster Software event 3 trigger, wait and clear command register.
#define EU_SW_EVENT_3_TRIG_WAIT_CLEAR_OFFSET     0xc

// Cluster Software event 4 trigger, wait and clear command register.
#define EU_SW_EVENT_4_TRIG_WAIT_CLEAR_OFFSET     0x10

// Cluster Software event 5 trigger, wait and clear command register.
#define EU_SW_EVENT_5_TRIG_WAIT_CLEAR_OFFSET     0x14

// Cluster Software event 6 trigger, wait and clear command register.
#define EU_SW_EVENT_6_TRIG_WAIT_CLEAR_OFFSET     0x18

// Cluster Software event 7 trigger, wait and clear command register.
#define EU_SW_EVENT_7_TRIG_WAIT_CLEAR_OFFSET     0x1c

// Cluster SoC peripheral event ID status register.
#define EU_SOC_PERIPH_EVENT_ID_OFFSET            0x0

// Cluster hardware barrier 0 trigger mask configuration register.
#define EU_HW_BARRIER_0_TRIG_MASK_OFFSET         0x0

// Cluster hardware barrier 1 trigger mask configuration register.
#define EU_HW_BARRIER_1_TRIG_MASK_OFFSET         0x20

// Cluster hardware barrier 2 trigger mask configuration register.
#define EU_HW_BARRIER_2_TRIG_MASK_OFFSET         0x40

// Cluster hardware barrier 3 trigger mask configuration register.
#define EU_HW_BARRIER_3_TRIG_MASK_OFFSET         0x60

// Cluster hardware barrier 4 trigger mask configuration register.
#define EU_HW_BARRIER_4_TRIG_MASK_OFFSET         0x80

// Cluster hardware barrier 5 trigger mask configuration register.
#define EU_HW_BARRIER_5_TRIG_MASK_OFFSET         0xa0

// Cluster hardware barrier 6 trigger mask configuration register.
#define EU_HW_BARRIER_6_TRIG_MASK_OFFSET         0xc0

// Cluster hardware barrier 7 trigger mask configuration register.
#define EU_HW_BARRIER_7_TRIG_MASK_OFFSET         0xe0

// Cluster hardware barrier 0 status register.
#define EU_HW_BARRIER_0_STATUS_OFFSET            0x4

// Cluster hardware barrier 1 status register.
#define EU_HW_BARRIER_1_STATUS_OFFSET            0x24

// Cluster hardware barrier 2 status register.
#define EU_HW_BARRIER_2_STATUS_OFFSET            0x44

// Cluster hardware barrier 3 status register.
#define EU_HW_BARRIER_3_STATUS_OFFSET            0x64

// Cluster hardware barrier 4 status register.
#define EU_HW_BARRIER_4_STATUS_OFFSET            0x84

// Cluster hardware barrier 5 status register.
#define EU_HW_BARRIER_5_STATUS_OFFSET            0xa4

// Cluster hardware barrier 6 status register.
#define EU_HW_BARRIER_6_STATUS_OFFSET            0xc4

// Cluster hardware barrier 7 status register.
#define EU_HW_BARRIER_7_STATUS_OFFSET            0xe4

// Cluster hardware barrier summary status register.
#define EU_HW_BARRIER_0_STATUS_SUM_OFFSET        0x8

// Cluster hardware barrier summary status register.
#define EU_HW_BARRIER_1_STATUS_SUM_OFFSET        0x28

// Cluster hardware barrier summary status register.
#define EU_HW_BARRIER_2_STATUS_SUM_OFFSET        0x48

// Cluster hardware barrier summary status register.
#define EU_HW_BARRIER_3_STATUS_SUM_OFFSET        0x68

// Cluster hardware barrier summary status register.
#define EU_HW_BARRIER_4_STATUS_SUM_OFFSET        0x88

// Cluster hardware barrier summary status register.
#define EU_HW_BARRIER_5_STATUS_SUM_OFFSET        0xa8

// Cluster hardware barrier summary status register.
#define EU_HW_BARRIER_6_STATUS_SUM_OFFSET        0xc8

// Cluster hardware barrier summary status register.
#define EU_HW_BARRIER_7_STATUS_SUM_OFFSET        0xe8

// Cluster hardware barrier 0 target mask configuration register.
#define EU_HW_BARRIER_0_TARGET_MASK_OFFSET       0xc

// Cluster hardware barrier 1 target mask configuration register.
#define EU_HW_BARRIER_1_TARGET_MASK_OFFSET       0x2c

// Cluster hardware barrier 2 target mask configuration register.
#define EU_HW_BARRIER_2_TARGET_MASK_OFFSET       0x4c

// Cluster hardware barrier 3 target mask configuration register.
#define EU_HW_BARRIER_3_TARGET_MASK_OFFSET       0x6c

// Cluster hardware barrier 4 target mask configuration register.
#define EU_HW_BARRIER_4_TARGET_MASK_OFFSET       0x8c

// Cluster hardware barrier 5 target mask configuration register.
#define EU_HW_BARRIER_5_TARGET_MASK_OFFSET       0xac

// Cluster hardware barrier 6 target mask configuration register.
#define EU_HW_BARRIER_6_TARGET_MASK_OFFSET       0xcc

// Cluster hardware barrier 7 target mask configuration register.
#define EU_HW_BARRIER_7_TARGET_MASK_OFFSET       0xec

// Cluster hardware barrier 0 trigger command register.
#define EU_HW_BARRIER_0_TRIG_OFFSET              0x10

// Cluster hardware barrier 1 trigger command register.
#define EU_HW_BARRIER_1_TRIG_OFFSET              0x30

// Cluster hardware barrier 2 trigger command register.
#define EU_HW_BARRIER_2_TRIG_OFFSET              0x50

// Cluster hardware barrier 3 trigger command register.
#define EU_HW_BARRIER_3_TRIG_OFFSET              0x70

// Cluster hardware barrier 4 trigger command register.
#define EU_HW_BARRIER_4_TRIG_OFFSET              0x90

// Cluster hardware barrier 5 trigger command register.
#define EU_HW_BARRIER_5_TRIG_OFFSET              0xb0

// Cluster hardware barrier 6 trigger command register.
#define EU_HW_BARRIER_6_TRIG_OFFSET              0xd0

// Cluster hardware barrier 7 trigger command register.
#define EU_HW_BARRIER_7_TRIG_OFFSET              0xf0

// Cluster hardware barrier 0 self trigger command register.
#define EU_HW_BARRIER_0_SELF_TRIG_OFFSET         0x14

// Cluster hardware barrier 1 self trigger command register.
#define EU_HW_BARRIER_1_SELF_TRIG_OFFSET         0x34

// Cluster hardware barrier 2 self trigger command register.
#define EU_HW_BARRIER_2_SELF_TRIG_OFFSET         0x54

// Cluster hardware barrier 3 self trigger command register.
#define EU_HW_BARRIER_3_SELF_TRIG_OFFSET         0x74

// Cluster hardware barrier 4 self trigger command register.
#define EU_HW_BARRIER_4_SELF_TRIG_OFFSET         0x94

// Cluster hardware barrier 5 self trigger command register.
#define EU_HW_BARRIER_5_SELF_TRIG_OFFSET         0xb4

// Cluster hardware barrier 6 self trigger command register.
#define EU_HW_BARRIER_6_SELF_TRIG_OFFSET         0xd4

// Cluster hardware barrier 7 self trigger command register.
#define EU_HW_BARRIER_7_SELF_TRIG_OFFSET         0xf4

// Cluster hardware barrier 0 trigger and wait command register.
#define EU_HW_BARRIER_0_TRIG_WAIT_OFFSET         0x18

// Cluster hardware barrier 1 trigger and wait command register.
#define EU_HW_BARRIER_1_TRIG_WAIT_OFFSET         0x38

// Cluster hardware barrier 2 trigger and wait command register.
#define EU_HW_BARRIER_2_TRIG_WAIT_OFFSET         0x58

// Cluster hardware barrier 3 trigger and wait command register.
#define EU_HW_BARRIER_3_TRIG_WAIT_OFFSET         0x78

// Cluster hardware barrier 4 trigger and wait command register.
#define EU_HW_BARRIER_4_TRIG_WAIT_OFFSET         0x98

// Cluster hardware barrier 5 trigger and wait command register.
#define EU_HW_BARRIER_5_TRIG_WAIT_OFFSET         0xb8

// Cluster hardware barrier 6 trigger and wait command register.
#define EU_HW_BARRIER_6_TRIG_WAIT_OFFSET         0xd8

// Cluster hardware barrier 7 trigger and wait command register.
#define EU_HW_BARRIER_7_TRIG_WAIT_OFFSET         0xf8

// Cluster hardware barrier 0 trigger, wait and clear command register.
#define EU_HW_BARRIER_0_TRIG_WAIT_CLEAR_OFFSET   0x1c

// Cluster hardware barrier 1 trigger, wait and clear command register.
#define EU_HW_BARRIER_1_TRIG_WAIT_CLEAR_OFFSET   0x3c

// Cluster hardware barrier 2 trigger, wait and clear command register.
#define EU_HW_BARRIER_2_TRIG_WAIT_CLEAR_OFFSET   0x5c

// Cluster hardware barrier 3 trigger, wait and clear command register.
#define EU_HW_BARRIER_3_TRIG_WAIT_CLEAR_OFFSET   0x7c

// Cluster hardware barrier 4 trigger, wait and clear command register.
#define EU_HW_BARRIER_4_TRIG_WAIT_CLEAR_OFFSET   0x9c

// Cluster hardware barrier 5 trigger, wait and clear command register.
#define EU_HW_BARRIER_5_TRIG_WAIT_CLEAR_OFFSET   0xbc

// Cluster hardware barrier 6 trigger, wait and clear command register.
#define EU_HW_BARRIER_6_TRIG_WAIT_CLEAR_OFFSET   0xdc

// Cluster hardware barrier 7 trigger, wait and clear command register.
#define EU_HW_BARRIER_7_TRIG_WAIT_CLEAR_OFFSET   0xfc



//
// REGISTERS FIELDS
//

// Soc peripheral input event mask configuration bitfield: - EMSOC[i]=1'b0: Input event request i is masked - EMSOC[i]=1'b1: Input event request i is not masked (access: R/W)
#define EU_EVT_MASK_EMSOC_BIT                                        31
#define EU_EVT_MASK_EMSOC_WIDTH                                      1
#define EU_EVT_MASK_EMSOC_MASK                                       0x80000000

// Inter-cluster input event mask configuration bitfield: - EMINTCL[i]=1'b0: Input event request i is masked - EMINTCL[i]=1'b1: Input event request i is not masked (access: R/W)
#define EU_EVT_MASK_EMINTCL_BIT                                      30
#define EU_EVT_MASK_EMINTCL_WIDTH                                    1
#define EU_EVT_MASK_EMINTCL_MASK                                     0x40000000

// Cluster internal input event mask configuration bitfield: - EMCL[i]=1'b0: Input event request i is masked - EMCL[i]=1'b1: Input event request i is not masked (access: R/W)
#define EU_EVT_MASK_EMCL_BIT                                         0
#define EU_EVT_MASK_EMCL_WIDTH                                       30
#define EU_EVT_MASK_EMCL_MASK                                        0x3fffffff

// Input event mask configuration bitfield update with bitwise AND operation. It allows clearing EMCL[i], EMINTCL[i] or EMSOC[i] if EMA[i]=1'b1. (access: W)
#define EU_EVT_MASK_AND_EMA_BIT                                      0
#define EU_EVT_MASK_AND_EMA_WIDTH                                    32
#define EU_EVT_MASK_AND_EMA_MASK                                     0xffffffff

// Input event mask configuration bitfield update with bitwise OR operation. It allows setting EMCL[i], EMINTCL[i] or EMSOC[i] if EMO[i]=1'b1. (access: W)
#define EU_EVT_MASK_OR_EMO_BIT                                       0
#define EU_EVT_MASK_OR_EMO_WIDTH                                     32
#define EU_EVT_MASK_OR_EMO_MASK                                      0xffffffff

// Soc peripheral interrupt request mask configuration bitfield: - bit[i]=1'b0: Interrupt request i is masked - bit[i]=1'b1: Interrupt request i is not masked (access: R/W)
#define EU_IRQ_MASK_IMSOC_BIT                                        31
#define EU_IRQ_MASK_IMSOC_WIDTH                                      1
#define EU_IRQ_MASK_IMSOC_MASK                                       0x80000000

// Inter-cluster interrupt request mask configuration bitfield: - bit[i]=1'b0: Interrupt request i is masked - bit[i]=1'b1: Interrupt request i is not masked (access: R/W)
#define EU_IRQ_MASK_IMINTCL_BIT                                      30
#define EU_IRQ_MASK_IMINTCL_WIDTH                                    1
#define EU_IRQ_MASK_IMINTCL_MASK                                     0x40000000

// Cluster internal interrupt request mask configuration bitfield: - bit[i]=1'b0: Interrupt request i is masked - bit[i]=1'b1: Interrupt request i is not masked (access: R/W)
#define EU_IRQ_MASK_IMCL_BIT                                         0
#define EU_IRQ_MASK_IMCL_WIDTH                                       30
#define EU_IRQ_MASK_IMCL_MASK                                        0x3fffffff

// Interrupt request mask configuration bitfield update with bitwise AND operation. It allows clearing IMCL[i], IMINTCL[i] or IMSOC[i] if IMA[i]=1'b1. (access: W)
#define EU_IRQ_MASK_AND_IMA_BIT                                      0
#define EU_IRQ_MASK_AND_IMA_WIDTH                                    32
#define EU_IRQ_MASK_AND_IMA_MASK                                     0xffffffff

// Interrupt request mask configuration bitfield update with bitwise OR operation. It allows setting IMCL[i], IMINTCL[i] or IMSOC[i] if IMO[i]=1'b1. (access: W)
#define EU_IRQ_MASK_OR_IMO_BIT                                       0
#define EU_IRQ_MASK_OR_IMO_WIDTH                                     32
#define EU_IRQ_MASK_OR_IMO_MASK                                      0xffffffff

// Cluster core clock status bitfield: - 1'b0: Cluster core clocked is gated - 1'b1: Cluster core clocked is running (access: R)
#define EU_CLOCK_STATUS_CS_BIT                                       0
#define EU_CLOCK_STATUS_CS_WIDTH                                     1
#define EU_CLOCK_STATUS_CS_MASK                                      0x1

// Pending input events status bitfield. EB[i]=1'b1: one or more input event i request are pending. (access: R)
#define EU_EVENT_BUFFER_EB_BIT                                       0
#define EU_EVENT_BUFFER_EB_WIDTH                                     32
#define EU_EVENT_BUFFER_EB_MASK                                      0xffffffff

// Pending input events status bitfield with EVT_MASK applied. EBM[i]=1'b1: one or more input event i request are pending. (access: R)
#define EU_EVENT_BUFFER_MASKED_EBM_BIT                               0
#define EU_EVENT_BUFFER_MASKED_EBM_WIDTH                             32
#define EU_EVENT_BUFFER_MASKED_EBM_MASK                              0xffffffff

// Pending input events status bitfield with IRQ_MASK applied. IBM[i]=1'b1:  one or more input events i are pending. (access: R)
#define EU_EVENT_BUFFER_IRQ_MASKED_IBM_BIT                           0
#define EU_EVENT_BUFFER_IRQ_MASKED_IBM_WIDTH                         32
#define EU_EVENT_BUFFER_IRQ_MASKED_IBM_MASK                          0xffffffff

// Pending input events status clear command bitfield. It allows clearing EB[i] if EBC[i]=1'b1. (access: W)
#define EU_EVENT_BUFFER_CLEAR_EBC_BIT                                0
#define EU_EVENT_BUFFER_CLEAR_EBC_WIDTH                              32
#define EU_EVENT_BUFFER_CLEAR_EBC_MASK                               0xffffffff

// Software events mask configuration bitfield: - bit[i]=1'b0: software events are masked for CL_CORE[i] - bit[i]=1'b1: software events are not masked for CL_CORE[i] (access: R/W)
#define EU_SW_EVENT_MASK_SWEM_BIT                                    0
#define EU_SW_EVENT_MASK_SWEM_WIDTH                                  8
#define EU_SW_EVENT_MASK_SWEM_MASK                                   0xff

// Software event mask configuration bitfield update with bitwise AND operation. It allows clearing SWEM[i] if SWEMA[i]=1'b1. (access: W)
#define EU_SW_EVENT_MASK_AND_SWEMA_BIT                               0
#define EU_SW_EVENT_MASK_AND_SWEMA_WIDTH                             8
#define EU_SW_EVENT_MASK_AND_SWEMA_MASK                              0xff

// Software event mask configuration bitfield update with bitwise OR operation. It allows setting SWEM[i] if SWEMO[i]=1'b1. (access: W)
#define EU_SW_EVENT_MASK_OR_SWEMO_BIT                                0
#define EU_SW_EVENT_MASK_OR_SWEMO_WIDTH                              8
#define EU_SW_EVENT_MASK_OR_SWEMO_MASK                               0xff

// Reading this register will gate the Cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_EVENT_WAIT_EBM_BIT                                        0
#define EU_EVENT_WAIT_EBM_WIDTH                                      32
#define EU_EVENT_WAIT_EBM_MASK                                       0xffffffff

// Reading this register has the same effect as reading EVENT_WAIT.EBM. In addition, EVENT_BUFFER.EB[i] bits are cleared if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_EVENT_WAIT_CLEAR_EBM_BIT                                  0
#define EU_EVENT_WAIT_CLEAR_EBM_WIDTH                                32
#define EU_EVENT_WAIT_CLEAR_EBM_MASK                                 0xffffffff

// Message to dispatch to all cluster cores selected in HW_DISPATCH_PUSH_TEAM_CONFIG.CT configuration bitfield. (access: W)
#define EU_HW_DISPATCH_PUSH_TASK_MSG_BIT                             0
#define EU_HW_DISPATCH_PUSH_TASK_MSG_WIDTH                           32
#define EU_HW_DISPATCH_PUSH_TASK_MSG_MASK                            0xffffffff

// Message dispatched using HW_DISPATCH_PUSH_TASK command and popped by cluster core who issued HW_DISPATCH_POP_TASK command. (access: R)
#define EU_HW_DISPATCH_POP_TASK_MSG_BIT                              0
#define EU_HW_DISPATCH_POP_TASK_MSG_WIDTH                            32
#define EU_HW_DISPATCH_POP_TASK_MSG_MASK                             0xffffffff

// Cluster cores team selection configuration bitfield. It allows to transmit HW_DISPATCH_PUSH_TASK.MSG to cluster core i if CT[i]=1'b1. (access: R/W)
#define EU_HW_DISPATCH_PUSH_TEAM_CONFIG_CT_BIT                       0
#define EU_HW_DISPATCH_PUSH_TEAM_CONFIG_CT_WIDTH                     8
#define EU_HW_DISPATCH_PUSH_TEAM_CONFIG_CT_MASK                      0xff

// Message pushed when releasing hardware mutex 0 configuration bitfiled. It is a non-blocking access. (access: W)
#define EU_HW_MUTEX_0_MSG_PUT_MSG_BIT                                0
#define EU_HW_MUTEX_0_MSG_PUT_MSG_WIDTH                              32
#define EU_HW_MUTEX_0_MSG_PUT_MSG_MASK                               0xffffffff

// Message popped when taking hardware mutex 0 data bitfiled. It is a blocking access. (access: R)
#define EU_HW_MUTEX_0_MSG_GET_MSG_BIT                                0
#define EU_HW_MUTEX_0_MSG_GET_MSG_WIDTH                              32
#define EU_HW_MUTEX_0_MSG_GET_MSG_MASK                               0xffffffff

// Message pushed when releasing hardware mutex 1 configuration bitfiled. It is a non-blocking access. (access: W)
#define EU_HW_MUTEX_1_MSG_PUT_MSG_BIT                                0
#define EU_HW_MUTEX_1_MSG_PUT_MSG_WIDTH                              32
#define EU_HW_MUTEX_1_MSG_PUT_MSG_MASK                               0xffffffff

// Message popped when taking hardware mutex 1 data bitfiled. It is a blocking access. (access: R)
#define EU_HW_MUTEX_1_MSG_GET_MSG_BIT                                0
#define EU_HW_MUTEX_1_MSG_GET_MSG_WIDTH                              32
#define EU_HW_MUTEX_1_MSG_GET_MSG_MASK                               0xffffffff

// Triggers software event 0 for cluster core i if SW0T[i]=1'b1. (access: W)
#define EU_SW_EVENT_0_TRIG_SW0T_BIT                                  0
#define EU_SW_EVENT_0_TRIG_SW0T_WIDTH                                8
#define EU_SW_EVENT_0_TRIG_SW0T_MASK                                 0xff

// Triggers software event 1 for cluster core i if SW1T[i]=1'b1. (access: W)
#define EU_SW_EVENT_1_TRIG_SW1T_BIT                                  0
#define EU_SW_EVENT_1_TRIG_SW1T_WIDTH                                8
#define EU_SW_EVENT_1_TRIG_SW1T_MASK                                 0xff

// Triggers software event 2 for cluster core i if SW2T[i]=1'b1. (access: W)
#define EU_SW_EVENT_2_TRIG_SW2T_BIT                                  0
#define EU_SW_EVENT_2_TRIG_SW2T_WIDTH                                8
#define EU_SW_EVENT_2_TRIG_SW2T_MASK                                 0xff

// Triggers software event 3 for cluster core i if SW3T[i]=1'b1. (access: W)
#define EU_SW_EVENT_3_TRIG_SW3T_BIT                                  0
#define EU_SW_EVENT_3_TRIG_SW3T_WIDTH                                8
#define EU_SW_EVENT_3_TRIG_SW3T_MASK                                 0xff

// Triggers software event 4 for cluster core i if SW4T[i]=1'b1. (access: W)
#define EU_SW_EVENT_4_TRIG_SW4T_BIT                                  0
#define EU_SW_EVENT_4_TRIG_SW4T_WIDTH                                8
#define EU_SW_EVENT_4_TRIG_SW4T_MASK                                 0xff

// Triggers software event 5 for cluster core i if SW5T[i]=1'b1. (access: W)
#define EU_SW_EVENT_5_TRIG_SW5T_BIT                                  0
#define EU_SW_EVENT_5_TRIG_SW5T_WIDTH                                8
#define EU_SW_EVENT_5_TRIG_SW5T_MASK                                 0xff

// Triggers software event 6 for cluster core i if SW6T[i]=1'b1. (access: W)
#define EU_SW_EVENT_6_TRIG_SW6T_BIT                                  0
#define EU_SW_EVENT_6_TRIG_SW6T_WIDTH                                8
#define EU_SW_EVENT_6_TRIG_SW6T_MASK                                 0xff

// Triggers software event 7 for cluster core i if SW7T[i]=1'b1. (access: W)
#define EU_SW_EVENT_7_TRIG_SW7T_BIT                                  0
#define EU_SW_EVENT_7_TRIG_SW7T_WIDTH                                8
#define EU_SW_EVENT_7_TRIG_SW7T_MASK                                 0xff

// Triggers software event 0 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_0_TRIG_WAIT_EBM_BIT                              0
#define EU_SW_EVENT_0_TRIG_WAIT_EBM_WIDTH                            32
#define EU_SW_EVENT_0_TRIG_WAIT_EBM_MASK                             0xffffffff

// Triggers software event 1 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_1_TRIG_WAIT_EBM_BIT                              0
#define EU_SW_EVENT_1_TRIG_WAIT_EBM_WIDTH                            32
#define EU_SW_EVENT_1_TRIG_WAIT_EBM_MASK                             0xffffffff

// Triggers software event 2 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_2_TRIG_WAIT_EBM_BIT                              0
#define EU_SW_EVENT_2_TRIG_WAIT_EBM_WIDTH                            32
#define EU_SW_EVENT_2_TRIG_WAIT_EBM_MASK                             0xffffffff

// Triggers software event 3 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_3_TRIG_WAIT_EBM_BIT                              0
#define EU_SW_EVENT_3_TRIG_WAIT_EBM_WIDTH                            32
#define EU_SW_EVENT_3_TRIG_WAIT_EBM_MASK                             0xffffffff

// Triggers software event 4 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_4_TRIG_WAIT_EBM_BIT                              0
#define EU_SW_EVENT_4_TRIG_WAIT_EBM_WIDTH                            32
#define EU_SW_EVENT_4_TRIG_WAIT_EBM_MASK                             0xffffffff

// Triggers software event 5 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_5_TRIG_WAIT_EBM_BIT                              0
#define EU_SW_EVENT_5_TRIG_WAIT_EBM_WIDTH                            32
#define EU_SW_EVENT_5_TRIG_WAIT_EBM_MASK                             0xffffffff

// Triggers software event 6 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_6_TRIG_WAIT_EBM_BIT                              0
#define EU_SW_EVENT_6_TRIG_WAIT_EBM_WIDTH                            32
#define EU_SW_EVENT_6_TRIG_WAIT_EBM_MASK                             0xffffffff

// Triggers software event 7 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_7_TRIG_WAIT_EBM_BIT                              0
#define EU_SW_EVENT_7_TRIG_WAIT_EBM_WIDTH                            32
#define EU_SW_EVENT_7_TRIG_WAIT_EBM_MASK                             0xffffffff

// Triggers software event 0 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_0_TRIG_WAIT_CLEAR_EBM_BIT                        0
#define EU_SW_EVENT_0_TRIG_WAIT_CLEAR_EBM_WIDTH                      32
#define EU_SW_EVENT_0_TRIG_WAIT_CLEAR_EBM_MASK                       0xffffffff

// Triggers software event 1 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_1_TRIG_WAIT_CLEAR_EBM_BIT                        0
#define EU_SW_EVENT_1_TRIG_WAIT_CLEAR_EBM_WIDTH                      32
#define EU_SW_EVENT_1_TRIG_WAIT_CLEAR_EBM_MASK                       0xffffffff

// Triggers software event 2 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_2_TRIG_WAIT_CLEAR_EBM_BIT                        0
#define EU_SW_EVENT_2_TRIG_WAIT_CLEAR_EBM_WIDTH                      32
#define EU_SW_EVENT_2_TRIG_WAIT_CLEAR_EBM_MASK                       0xffffffff

// Triggers software event 3 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_3_TRIG_WAIT_CLEAR_EBM_BIT                        0
#define EU_SW_EVENT_3_TRIG_WAIT_CLEAR_EBM_WIDTH                      32
#define EU_SW_EVENT_3_TRIG_WAIT_CLEAR_EBM_MASK                       0xffffffff

// Triggers software event 4 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_4_TRIG_WAIT_CLEAR_EBM_BIT                        0
#define EU_SW_EVENT_4_TRIG_WAIT_CLEAR_EBM_WIDTH                      32
#define EU_SW_EVENT_4_TRIG_WAIT_CLEAR_EBM_MASK                       0xffffffff

// Triggers software event 5 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_5_TRIG_WAIT_CLEAR_EBM_BIT                        0
#define EU_SW_EVENT_5_TRIG_WAIT_CLEAR_EBM_WIDTH                      32
#define EU_SW_EVENT_5_TRIG_WAIT_CLEAR_EBM_MASK                       0xffffffff

// Triggers software event 6 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_6_TRIG_WAIT_CLEAR_EBM_BIT                        0
#define EU_SW_EVENT_6_TRIG_WAIT_CLEAR_EBM_WIDTH                      32
#define EU_SW_EVENT_6_TRIG_WAIT_CLEAR_EBM_MASK                       0xffffffff

// Triggers software event 7 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_SW_EVENT_7_TRIG_WAIT_CLEAR_EBM_BIT                        0
#define EU_SW_EVENT_7_TRIG_WAIT_CLEAR_EBM_WIDTH                      32
#define EU_SW_EVENT_7_TRIG_WAIT_CLEAR_EBM_MASK                       0xffffffff

// Oldest SoC peripheral event ID status bitfield. (access: R)
#define EU_SOC_PERIPH_EVENT_ID_ID_BIT                                0
#define EU_SOC_PERIPH_EVENT_ID_ID_WIDTH                              8
#define EU_SOC_PERIPH_EVENT_ID_ID_MASK                               0xff

// Validity bit of SOC_PERIPH_EVENT_ID.ID bitfield. (access: R)
#define EU_SOC_PERIPH_EVENT_ID_VALID_BIT                             31
#define EU_SOC_PERIPH_EVENT_ID_VALID_WIDTH                           1
#define EU_SOC_PERIPH_EVENT_ID_VALID_MASK                            0x80000000

// Trigger mask for hardware barrier 0 bitfield. Hardware barrier 0 will be triggered only if for all HB0TM[i] = 1'b1,  HW_BARRIER_0_STATUS.HB0S[i]=1'b1. HB0TM=0 means that hardware barrier 0 is disabled. (access: R/W)
#define EU_HW_BARRIER_0_TRIG_MASK_HB0TM_BIT                          0
#define EU_HW_BARRIER_0_TRIG_MASK_HB0TM_WIDTH                        8
#define EU_HW_BARRIER_0_TRIG_MASK_HB0TM_MASK                         0xff

// Trigger mask for hardware barrier 1 bitfield. Hardware barrier 1 will be triggered only if for all HB1TM[i] = 1'b1,  HW_BARRIER_1_STATUS.HB1S[i]=1'b1. HB1TM=0 means that hardware barrier 1 is disabled. (access: R/W)
#define EU_HW_BARRIER_1_TRIG_MASK_HB1TM_BIT                          0
#define EU_HW_BARRIER_1_TRIG_MASK_HB1TM_WIDTH                        8
#define EU_HW_BARRIER_1_TRIG_MASK_HB1TM_MASK                         0xff

// Trigger mask for hardware barrier 2 bitfield. Hardware barrier 2 will be triggered only if for all HB2TM[i] = 1'b1,  HW_BARRIER_2_STATUS.HB2S[i]=1'b1. HB2TM=0 means that hardware barrier 2 is disabled. (access: R/W)
#define EU_HW_BARRIER_2_TRIG_MASK_HB2TM_BIT                          0
#define EU_HW_BARRIER_2_TRIG_MASK_HB2TM_WIDTH                        8
#define EU_HW_BARRIER_2_TRIG_MASK_HB2TM_MASK                         0xff

// Trigger mask for hardware barrier 3 bitfield. Hardware barrier 3 will be triggered only if for all HB3TM[i] = 1'b1,  HW_BARRIER_3_STATUS.HB3S[i]=1'b1. HB3TM=0 means that hardware barrier 3 is disabled. (access: R/W)
#define EU_HW_BARRIER_3_TRIG_MASK_HB3TM_BIT                          0
#define EU_HW_BARRIER_3_TRIG_MASK_HB3TM_WIDTH                        8
#define EU_HW_BARRIER_3_TRIG_MASK_HB3TM_MASK                         0xff

// Trigger mask for hardware barrier 4 bitfield. Hardware barrier 4 will be triggered only if for all HB4TM[i] = 1'b1,  HW_BARRIER_4_STATUS.HB4S[i]=1'b1. HB4TM=0 means that hardware barrier 4 is disabled. (access: R/W)
#define EU_HW_BARRIER_4_TRIG_MASK_HB4TM_BIT                          0
#define EU_HW_BARRIER_4_TRIG_MASK_HB4TM_WIDTH                        8
#define EU_HW_BARRIER_4_TRIG_MASK_HB4TM_MASK                         0xff

// Trigger mask for hardware barrier 5 bitfield. Hardware barrier 5 will be triggered only if for all HB5TM[i] = 1'b1,  HW_BARRIER_5_STATUS.HB5S[i]=1'b1. HB5TM=0 means that hardware barrier 5 is disabled. (access: R/W)
#define EU_HW_BARRIER_5_TRIG_MASK_HB5TM_BIT                          0
#define EU_HW_BARRIER_5_TRIG_MASK_HB5TM_WIDTH                        8
#define EU_HW_BARRIER_5_TRIG_MASK_HB5TM_MASK                         0xff

// Trigger mask for hardware barrier 6 bitfield. Hardware barrier 6 will be triggered only if for all HB6TM[i] = 1'b1,  HW_BARRIER_6_STATUS.HB6S[i]=1'b1. HB6TM=0 means that hardware barrier 6 is disabled. (access: R/W)
#define EU_HW_BARRIER_6_TRIG_MASK_HB6TM_BIT                          0
#define EU_HW_BARRIER_6_TRIG_MASK_HB6TM_WIDTH                        8
#define EU_HW_BARRIER_6_TRIG_MASK_HB6TM_MASK                         0xff

// Trigger mask for hardware barrier 7 bitfield. Hardware barrier 7 will be triggered only if for all HB7TM[i] = 1'b1,  HW_BARRIER_7_STATUS.HB7S[i]=1'b1. HB7TM=0 means that hardware barrier 7 is disabled. (access: R/W)
#define EU_HW_BARRIER_7_TRIG_MASK_HB7TM_BIT                          0
#define EU_HW_BARRIER_7_TRIG_MASK_HB7TM_WIDTH                        8
#define EU_HW_BARRIER_7_TRIG_MASK_HB7TM_MASK                         0xff

// Current status of hardware barrier 0 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 0. It is cleared when HBS matches HW_BARRIER_0_TRIG_MASK.HB0TM. (access: R)
#define EU_HW_BARRIER_0_STATUS_HBS_BIT                               0
#define EU_HW_BARRIER_0_STATUS_HBS_WIDTH                             8
#define EU_HW_BARRIER_0_STATUS_HBS_MASK                              0xff

// Current status of hardware barrier 1 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 1. It is cleared when HBS matches HW_BARRIER_1_TRIG_MASK.HB1TM. (access: R)
#define EU_HW_BARRIER_1_STATUS_HBS_BIT                               0
#define EU_HW_BARRIER_1_STATUS_HBS_WIDTH                             8
#define EU_HW_BARRIER_1_STATUS_HBS_MASK                              0xff

// Current status of hardware barrier 2 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 2. It is cleared when HBS matches HW_BARRIER_2_TRIG_MASK.HB2TM. (access: R)
#define EU_HW_BARRIER_2_STATUS_HBS_BIT                               0
#define EU_HW_BARRIER_2_STATUS_HBS_WIDTH                             8
#define EU_HW_BARRIER_2_STATUS_HBS_MASK                              0xff

// Current status of hardware barrier 3 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 3. It is cleared when HBS matches HW_BARRIER_3_TRIG_MASK.HB3TM. (access: R)
#define EU_HW_BARRIER_3_STATUS_HBS_BIT                               0
#define EU_HW_BARRIER_3_STATUS_HBS_WIDTH                             8
#define EU_HW_BARRIER_3_STATUS_HBS_MASK                              0xff

// Current status of hardware barrier 4 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 4. It is cleared when HBS matches HW_BARRIER_4_TRIG_MASK.HB4TM. (access: R)
#define EU_HW_BARRIER_4_STATUS_HBS_BIT                               0
#define EU_HW_BARRIER_4_STATUS_HBS_WIDTH                             8
#define EU_HW_BARRIER_4_STATUS_HBS_MASK                              0xff

// Current status of hardware barrier 5 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 5. It is cleared when HBS matches HW_BARRIER_5_TRIG_MASK.HB5TM. (access: R)
#define EU_HW_BARRIER_5_STATUS_HBS_BIT                               0
#define EU_HW_BARRIER_5_STATUS_HBS_WIDTH                             8
#define EU_HW_BARRIER_5_STATUS_HBS_MASK                              0xff

// Current status of hardware barrier 6 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 6. It is cleared when HBS matches HW_BARRIER_6_TRIG_MASK.HB6TM. (access: R)
#define EU_HW_BARRIER_6_STATUS_HBS_BIT                               0
#define EU_HW_BARRIER_6_STATUS_HBS_WIDTH                             8
#define EU_HW_BARRIER_6_STATUS_HBS_MASK                              0xff

// Current status of hardware barrier 7 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 7. It is cleared when HBS matches HW_BARRIER_7_TRIG_MASK.HB7TM. (access: R)
#define EU_HW_BARRIER_7_STATUS_HBS_BIT                               0
#define EU_HW_BARRIER_7_STATUS_HBS_WIDTH                             8
#define EU_HW_BARRIER_7_STATUS_HBS_MASK                              0xff

// Current status of hardware barrier 0. HBSS[i] represents a summary of the barrier status for core i. (access: R)
#define EU_HW_BARRIER_0_STATUS_SUM_HBSS_BIT                          0
#define EU_HW_BARRIER_0_STATUS_SUM_HBSS_WIDTH                        8
#define EU_HW_BARRIER_0_STATUS_SUM_HBSS_MASK                         0xff

// Current status of hardware barrier 1. HBSS[i] represents a summary of the barrier status for core i. (access: R)
#define EU_HW_BARRIER_1_STATUS_SUM_HBSS_BIT                          0
#define EU_HW_BARRIER_1_STATUS_SUM_HBSS_WIDTH                        8
#define EU_HW_BARRIER_1_STATUS_SUM_HBSS_MASK                         0xff

// Current status of hardware barrier 2. HBSS[i] represents a summary of the barrier status for core i. (access: R)
#define EU_HW_BARRIER_2_STATUS_SUM_HBSS_BIT                          0
#define EU_HW_BARRIER_2_STATUS_SUM_HBSS_WIDTH                        8
#define EU_HW_BARRIER_2_STATUS_SUM_HBSS_MASK                         0xff

// Current status of hardware barrier 3. HBSS[i] represents a summary of the barrier status for core i. (access: R)
#define EU_HW_BARRIER_3_STATUS_SUM_HBSS_BIT                          0
#define EU_HW_BARRIER_3_STATUS_SUM_HBSS_WIDTH                        8
#define EU_HW_BARRIER_3_STATUS_SUM_HBSS_MASK                         0xff

// Current status of hardware barrier 4. HBSS[i] represents a summary of the barrier status for core i. (access: R)
#define EU_HW_BARRIER_4_STATUS_SUM_HBSS_BIT                          0
#define EU_HW_BARRIER_4_STATUS_SUM_HBSS_WIDTH                        8
#define EU_HW_BARRIER_4_STATUS_SUM_HBSS_MASK                         0xff

// Current status of hardware barrier 5. HBSS[i] represents a summary of the barrier status for core i. (access: R)
#define EU_HW_BARRIER_5_STATUS_SUM_HBSS_BIT                          0
#define EU_HW_BARRIER_5_STATUS_SUM_HBSS_WIDTH                        8
#define EU_HW_BARRIER_5_STATUS_SUM_HBSS_MASK                         0xff

// Current status of hardware barrier 6. HBSS[i] represents a summary of the barrier status for core i. (access: R)
#define EU_HW_BARRIER_6_STATUS_SUM_HBSS_BIT                          0
#define EU_HW_BARRIER_6_STATUS_SUM_HBSS_WIDTH                        8
#define EU_HW_BARRIER_6_STATUS_SUM_HBSS_MASK                         0xff

// Current status of hardware barrier 7. HBSS[i] represents a summary of the barrier status for core i. (access: R)
#define EU_HW_BARRIER_7_STATUS_SUM_HBSS_BIT                          0
#define EU_HW_BARRIER_7_STATUS_SUM_HBSS_WIDTH                        8
#define EU_HW_BARRIER_7_STATUS_SUM_HBSS_MASK                         0xff

// Cluster hardware barrier 0 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 0 event when HW_BARRIER_0_STATUS will match HW_BARRIER_0_TRIG_MASK. (access: R/W)
#define EU_HW_BARRIER_0_TARGET_MASK_HBTAM_BIT                        0
#define EU_HW_BARRIER_0_TARGET_MASK_HBTAM_WIDTH                      8
#define EU_HW_BARRIER_0_TARGET_MASK_HBTAM_MASK                       0xff

// Cluster hardware barrier 1 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 1 event when HW_BARRIER_1_STATUS will match HW_BARRIER_1_TRIG_MASK. (access: R/W)
#define EU_HW_BARRIER_1_TARGET_MASK_HBTAM_BIT                        0
#define EU_HW_BARRIER_1_TARGET_MASK_HBTAM_WIDTH                      8
#define EU_HW_BARRIER_1_TARGET_MASK_HBTAM_MASK                       0xff

// Cluster hardware barrier 2 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 2 event when HW_BARRIER_2_STATUS will match HW_BARRIER_2_TRIG_MASK. (access: R/W)
#define EU_HW_BARRIER_2_TARGET_MASK_HBTAM_BIT                        0
#define EU_HW_BARRIER_2_TARGET_MASK_HBTAM_WIDTH                      8
#define EU_HW_BARRIER_2_TARGET_MASK_HBTAM_MASK                       0xff

// Cluster hardware barrier 3 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 3 event when HW_BARRIER_3_STATUS will match HW_BARRIER_3_TRIG_MASK. (access: R/W)
#define EU_HW_BARRIER_3_TARGET_MASK_HBTAM_BIT                        0
#define EU_HW_BARRIER_3_TARGET_MASK_HBTAM_WIDTH                      8
#define EU_HW_BARRIER_3_TARGET_MASK_HBTAM_MASK                       0xff

// Cluster hardware barrier 4 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 4 event when HW_BARRIER_4_STATUS will match HW_BARRIER_4_TRIG_MASK. (access: R/W)
#define EU_HW_BARRIER_4_TARGET_MASK_HBTAM_BIT                        0
#define EU_HW_BARRIER_4_TARGET_MASK_HBTAM_WIDTH                      8
#define EU_HW_BARRIER_4_TARGET_MASK_HBTAM_MASK                       0xff

// Cluster hardware barrier 5 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 5 event when HW_BARRIER_5_STATUS will match HW_BARRIER_5_TRIG_MASK. (access: R/W)
#define EU_HW_BARRIER_5_TARGET_MASK_HBTAM_BIT                        0
#define EU_HW_BARRIER_5_TARGET_MASK_HBTAM_WIDTH                      8
#define EU_HW_BARRIER_5_TARGET_MASK_HBTAM_MASK                       0xff

// Cluster hardware barrier 6 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 6 event when HW_BARRIER_6_STATUS will match HW_BARRIER_6_TRIG_MASK. (access: R/W)
#define EU_HW_BARRIER_6_TARGET_MASK_HBTAM_BIT                        0
#define EU_HW_BARRIER_6_TARGET_MASK_HBTAM_WIDTH                      8
#define EU_HW_BARRIER_6_TARGET_MASK_HBTAM_MASK                       0xff

// Cluster hardware barrier 7 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 7 event when HW_BARRIER_7_STATUS will match HW_BARRIER_7_TRIG_MASK. (access: R/W)
#define EU_HW_BARRIER_7_TARGET_MASK_HBTAM_BIT                        0
#define EU_HW_BARRIER_7_TARGET_MASK_HBTAM_WIDTH                      8
#define EU_HW_BARRIER_7_TARGET_MASK_HBTAM_MASK                       0xff

// Sets HW_BARRIER_0_STATUS.HBS[i] to 1'b1 when T[i]=1'b1. (access: W)
#define EU_HW_BARRIER_0_TRIG_T_BIT                                   0
#define EU_HW_BARRIER_0_TRIG_T_WIDTH                                 8
#define EU_HW_BARRIER_0_TRIG_T_MASK                                  0xff

// Sets HW_BARRIER_1_STATUS.HBS[i] to 1'b1 when T[i]=1'b1. (access: W)
#define EU_HW_BARRIER_1_TRIG_T_BIT                                   0
#define EU_HW_BARRIER_1_TRIG_T_WIDTH                                 8
#define EU_HW_BARRIER_1_TRIG_T_MASK                                  0xff

// Sets HW_BARRIER_2_STATUS.HBS[i] to 1'b1 when T[i]=1'b1. (access: W)
#define EU_HW_BARRIER_2_TRIG_T_BIT                                   0
#define EU_HW_BARRIER_2_TRIG_T_WIDTH                                 8
#define EU_HW_BARRIER_2_TRIG_T_MASK                                  0xff

// Sets HW_BARRIER_3_STATUS.HBS[i] to 1'b1 when T[i]=1'b1. (access: W)
#define EU_HW_BARRIER_3_TRIG_T_BIT                                   0
#define EU_HW_BARRIER_3_TRIG_T_WIDTH                                 8
#define EU_HW_BARRIER_3_TRIG_T_MASK                                  0xff

// Sets HW_BARRIER_4_STATUS.HBS[i] to 1'b1 when T[i]=1'b1. (access: W)
#define EU_HW_BARRIER_4_TRIG_T_BIT                                   0
#define EU_HW_BARRIER_4_TRIG_T_WIDTH                                 8
#define EU_HW_BARRIER_4_TRIG_T_MASK                                  0xff

// Sets HW_BARRIER_5_STATUS.HBS[i] to 1'b1 when T[i]=1'b1. (access: W)
#define EU_HW_BARRIER_5_TRIG_T_BIT                                   0
#define EU_HW_BARRIER_5_TRIG_T_WIDTH                                 8
#define EU_HW_BARRIER_5_TRIG_T_MASK                                  0xff

// Sets HW_BARRIER_6_STATUS.HBS[i] to 1'b1 when T[i]=1'b1. (access: W)
#define EU_HW_BARRIER_6_TRIG_T_BIT                                   0
#define EU_HW_BARRIER_6_TRIG_T_WIDTH                                 8
#define EU_HW_BARRIER_6_TRIG_T_MASK                                  0xff

// Sets HW_BARRIER_7_STATUS.HBS[i] to 1'b1 when T[i]=1'b1. (access: W)
#define EU_HW_BARRIER_7_TRIG_T_BIT                                   0
#define EU_HW_BARRIER_7_TRIG_T_WIDTH                                 8
#define EU_HW_BARRIER_7_TRIG_T_MASK                                  0xff

// Sets HW_BARRIER_0_STATUS.HBS[i] to 1'b1 when issued by cluster core i. (access: R)
#define EU_HW_BARRIER_0_SELF_TRIG_T_BIT                              0
#define EU_HW_BARRIER_0_SELF_TRIG_T_WIDTH                            32
#define EU_HW_BARRIER_0_SELF_TRIG_T_MASK                             0xffffffff

// Sets HW_BARRIER_1_STATUS.HBS[i] to 1'b1 when issued by cluster core i. (access: R)
#define EU_HW_BARRIER_1_SELF_TRIG_T_BIT                              0
#define EU_HW_BARRIER_1_SELF_TRIG_T_WIDTH                            32
#define EU_HW_BARRIER_1_SELF_TRIG_T_MASK                             0xffffffff

// Sets HW_BARRIER_2_STATUS.HBS[i] to 1'b1 when issued by cluster core i. (access: R)
#define EU_HW_BARRIER_2_SELF_TRIG_T_BIT                              0
#define EU_HW_BARRIER_2_SELF_TRIG_T_WIDTH                            32
#define EU_HW_BARRIER_2_SELF_TRIG_T_MASK                             0xffffffff

// Sets HW_BARRIER_3_STATUS.HBS[i] to 1'b1 when issued by cluster core i. (access: R)
#define EU_HW_BARRIER_3_SELF_TRIG_T_BIT                              0
#define EU_HW_BARRIER_3_SELF_TRIG_T_WIDTH                            32
#define EU_HW_BARRIER_3_SELF_TRIG_T_MASK                             0xffffffff

// Sets HW_BARRIER_4_STATUS.HBS[i] to 1'b1 when issued by cluster core i. (access: R)
#define EU_HW_BARRIER_4_SELF_TRIG_T_BIT                              0
#define EU_HW_BARRIER_4_SELF_TRIG_T_WIDTH                            32
#define EU_HW_BARRIER_4_SELF_TRIG_T_MASK                             0xffffffff

// Sets HW_BARRIER_5_STATUS.HBS[i] to 1'b1 when issued by cluster core i. (access: R)
#define EU_HW_BARRIER_5_SELF_TRIG_T_BIT                              0
#define EU_HW_BARRIER_5_SELF_TRIG_T_WIDTH                            32
#define EU_HW_BARRIER_5_SELF_TRIG_T_MASK                             0xffffffff

// Sets HW_BARRIER_6_STATUS.HBS[i] to 1'b1 when issued by cluster core i. (access: R)
#define EU_HW_BARRIER_6_SELF_TRIG_T_BIT                              0
#define EU_HW_BARRIER_6_SELF_TRIG_T_WIDTH                            32
#define EU_HW_BARRIER_6_SELF_TRIG_T_MASK                             0xffffffff

// Sets HW_BARRIER_7_STATUS.HBS[i] to 1'b1 when issued by cluster core i. (access: R)
#define EU_HW_BARRIER_7_SELF_TRIG_T_BIT                              0
#define EU_HW_BARRIER_7_SELF_TRIG_T_WIDTH                            32
#define EU_HW_BARRIER_7_SELF_TRIG_T_MASK                             0xffffffff

// Set HW_BARRIER_0[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_0 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_0_TRIG_WAIT_EBM_BIT                            0
#define EU_HW_BARRIER_0_TRIG_WAIT_EBM_WIDTH                          32
#define EU_HW_BARRIER_0_TRIG_WAIT_EBM_MASK                           0xffffffff

// Set HW_BARRIER_1[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_1 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_1_TRIG_WAIT_EBM_BIT                            0
#define EU_HW_BARRIER_1_TRIG_WAIT_EBM_WIDTH                          32
#define EU_HW_BARRIER_1_TRIG_WAIT_EBM_MASK                           0xffffffff

// Set HW_BARRIER_2[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_2 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_2_TRIG_WAIT_EBM_BIT                            0
#define EU_HW_BARRIER_2_TRIG_WAIT_EBM_WIDTH                          32
#define EU_HW_BARRIER_2_TRIG_WAIT_EBM_MASK                           0xffffffff

// Set HW_BARRIER_3[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_3 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_3_TRIG_WAIT_EBM_BIT                            0
#define EU_HW_BARRIER_3_TRIG_WAIT_EBM_WIDTH                          32
#define EU_HW_BARRIER_3_TRIG_WAIT_EBM_MASK                           0xffffffff

// Set HW_BARRIER_4[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_4 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_4_TRIG_WAIT_EBM_BIT                            0
#define EU_HW_BARRIER_4_TRIG_WAIT_EBM_WIDTH                          32
#define EU_HW_BARRIER_4_TRIG_WAIT_EBM_MASK                           0xffffffff

// Set HW_BARRIER_5[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_5 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_5_TRIG_WAIT_EBM_BIT                            0
#define EU_HW_BARRIER_5_TRIG_WAIT_EBM_WIDTH                          32
#define EU_HW_BARRIER_5_TRIG_WAIT_EBM_MASK                           0xffffffff

// Set HW_BARRIER_6[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_6 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_6_TRIG_WAIT_EBM_BIT                            0
#define EU_HW_BARRIER_6_TRIG_WAIT_EBM_WIDTH                          32
#define EU_HW_BARRIER_6_TRIG_WAIT_EBM_MASK                           0xffffffff

// Set HW_BARRIER_7[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_7 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_7_TRIG_WAIT_EBM_BIT                            0
#define EU_HW_BARRIER_7_TRIG_WAIT_EBM_WIDTH                          32
#define EU_HW_BARRIER_7_TRIG_WAIT_EBM_MASK                           0xffffffff

// Set HW_BARRIER_0[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_0 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_0_TRIG_WAIT_CLEAR_EBM_BIT                      0
#define EU_HW_BARRIER_0_TRIG_WAIT_CLEAR_EBM_WIDTH                    32
#define EU_HW_BARRIER_0_TRIG_WAIT_CLEAR_EBM_MASK                     0xffffffff

// Set HW_BARRIER_1[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_1 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_1_TRIG_WAIT_CLEAR_EBM_BIT                      0
#define EU_HW_BARRIER_1_TRIG_WAIT_CLEAR_EBM_WIDTH                    32
#define EU_HW_BARRIER_1_TRIG_WAIT_CLEAR_EBM_MASK                     0xffffffff

// Set HW_BARRIER_2[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_2 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_2_TRIG_WAIT_CLEAR_EBM_BIT                      0
#define EU_HW_BARRIER_2_TRIG_WAIT_CLEAR_EBM_WIDTH                    32
#define EU_HW_BARRIER_2_TRIG_WAIT_CLEAR_EBM_MASK                     0xffffffff

// Set HW_BARRIER_3[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_3 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_3_TRIG_WAIT_CLEAR_EBM_BIT                      0
#define EU_HW_BARRIER_3_TRIG_WAIT_CLEAR_EBM_WIDTH                    32
#define EU_HW_BARRIER_3_TRIG_WAIT_CLEAR_EBM_MASK                     0xffffffff

// Set HW_BARRIER_4[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_4 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_4_TRIG_WAIT_CLEAR_EBM_BIT                      0
#define EU_HW_BARRIER_4_TRIG_WAIT_CLEAR_EBM_WIDTH                    32
#define EU_HW_BARRIER_4_TRIG_WAIT_CLEAR_EBM_MASK                     0xffffffff

// Set HW_BARRIER_5[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_5 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_5_TRIG_WAIT_CLEAR_EBM_BIT                      0
#define EU_HW_BARRIER_5_TRIG_WAIT_CLEAR_EBM_WIDTH                    32
#define EU_HW_BARRIER_5_TRIG_WAIT_CLEAR_EBM_MASK                     0xffffffff

// Set HW_BARRIER_6[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_6 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_6_TRIG_WAIT_CLEAR_EBM_BIT                      0
#define EU_HW_BARRIER_6_TRIG_WAIT_CLEAR_EBM_WIDTH                    32
#define EU_HW_BARRIER_6_TRIG_WAIT_CLEAR_EBM_MASK                     0xffffffff

// Set HW_BARRIER_7[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_7 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM (access: R)
#define EU_HW_BARRIER_7_TRIG_WAIT_CLEAR_EBM_BIT                      0
#define EU_HW_BARRIER_7_TRIG_WAIT_CLEAR_EBM_WIDTH                    32
#define EU_HW_BARRIER_7_TRIG_WAIT_CLEAR_EBM_MASK                     0xffffffff



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
    unsigned int emsoc           :1 ; // Soc peripheral input event mask configuration bitfield: - EMSOC[i]=1'b0: Input event request i is masked - EMSOC[i]=1'b1: Input event request i is not masked
    unsigned int emintcl         :1 ; // Inter-cluster input event mask configuration bitfield: - EMINTCL[i]=1'b0: Input event request i is masked - EMINTCL[i]=1'b1: Input event request i is not masked
    unsigned int emcl            :30; // Cluster internal input event mask configuration bitfield: - EMCL[i]=1'b0: Input event request i is masked - EMCL[i]=1'b1: Input event request i is not masked
  };
  unsigned int raw;
} __attribute__((packed)) eu_evt_mask_t;

typedef union {
  struct {
    unsigned int ema             :32; // Input event mask configuration bitfield update with bitwise AND operation. It allows clearing EMCL[i], EMINTCL[i] or EMSOC[i] if EMA[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_evt_mask_and_t;

typedef union {
  struct {
    unsigned int emo             :32; // Input event mask configuration bitfield update with bitwise OR operation. It allows setting EMCL[i], EMINTCL[i] or EMSOC[i] if EMO[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_evt_mask_or_t;

typedef union {
  struct {
    unsigned int imsoc           :1 ; // Soc peripheral interrupt request mask configuration bitfield: - bit[i]=1'b0: Interrupt request i is masked - bit[i]=1'b1: Interrupt request i is not masked
    unsigned int imintcl         :1 ; // Inter-cluster interrupt request mask configuration bitfield: - bit[i]=1'b0: Interrupt request i is masked - bit[i]=1'b1: Interrupt request i is not masked
    unsigned int imcl            :30; // Cluster internal interrupt request mask configuration bitfield: - bit[i]=1'b0: Interrupt request i is masked - bit[i]=1'b1: Interrupt request i is not masked
  };
  unsigned int raw;
} __attribute__((packed)) eu_irq_mask_t;

typedef union {
  struct {
    unsigned int ima             :32; // Interrupt request mask configuration bitfield update with bitwise AND operation. It allows clearing IMCL[i], IMINTCL[i] or IMSOC[i] if IMA[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_irq_mask_and_t;

typedef union {
  struct {
    unsigned int imo             :32; // Interrupt request mask configuration bitfield update with bitwise OR operation. It allows setting IMCL[i], IMINTCL[i] or IMSOC[i] if IMO[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_irq_mask_or_t;

typedef union {
  struct {
    unsigned int cs              :1 ; // Cluster core clock status bitfield: - 1'b0: Cluster core clocked is gated - 1'b1: Cluster core clocked is running
  };
  unsigned int raw;
} __attribute__((packed)) eu_clock_status_t;

typedef union {
  struct {
    unsigned int eb              :32; // Pending input events status bitfield. EB[i]=1'b1: one or more input event i request are pending.
  };
  unsigned int raw;
} __attribute__((packed)) eu_event_buffer_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Pending input events status bitfield with EVT_MASK applied. EBM[i]=1'b1: one or more input event i request are pending.
  };
  unsigned int raw;
} __attribute__((packed)) eu_event_buffer_masked_t;

typedef union {
  struct {
    unsigned int ibm             :32; // Pending input events status bitfield with IRQ_MASK applied. IBM[i]=1'b1:  one or more input events i are pending.
  };
  unsigned int raw;
} __attribute__((packed)) eu_event_buffer_irq_masked_t;

typedef union {
  struct {
    unsigned int ebc             :32; // Pending input events status clear command bitfield. It allows clearing EB[i] if EBC[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_event_buffer_clear_t;

typedef union {
  struct {
    unsigned int swem            :8 ; // Software events mask configuration bitfield: - bit[i]=1'b0: software events are masked for CL_CORE[i] - bit[i]=1'b1: software events are not masked for CL_CORE[i]
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_mask_t;

typedef union {
  struct {
    unsigned int swema           :8 ; // Software event mask configuration bitfield update with bitwise AND operation. It allows clearing SWEM[i] if SWEMA[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_mask_and_t;

typedef union {
  struct {
    unsigned int swemo           :8 ; // Software event mask configuration bitfield update with bitwise OR operation. It allows setting SWEM[i] if SWEMO[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_mask_or_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Reading this register will gate the Cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_event_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Reading this register has the same effect as reading EVENT_WAIT.EBM. In addition, EVENT_BUFFER.EB[i] bits are cleared if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_event_wait_clear_t;

typedef union {
  struct {
    unsigned int msg             :32; // Message to dispatch to all cluster cores selected in HW_DISPATCH_PUSH_TEAM_CONFIG.CT configuration bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_dispatch_push_task_t;

typedef union {
  struct {
    unsigned int msg             :32; // Message dispatched using HW_DISPATCH_PUSH_TASK command and popped by cluster core who issued HW_DISPATCH_POP_TASK command.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_dispatch_pop_task_t;

typedef union {
  struct {
    unsigned int ct              :8 ; // Cluster cores team selection configuration bitfield. It allows to transmit HW_DISPATCH_PUSH_TASK.MSG to cluster core i if CT[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_dispatch_push_team_config_t;

typedef union {
  struct {
    unsigned int msg             :32; // Message pushed when releasing hardware mutex 0 configuration bitfiled. It is a non-blocking access.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_mutex_0_msg_put_t;

typedef union {
  struct {
    unsigned int msg             :32; // Message popped when taking hardware mutex 0 data bitfiled. It is a blocking access.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_mutex_0_msg_get_t;

typedef union {
  struct {
    unsigned int msg             :32; // Message pushed when releasing hardware mutex 1 configuration bitfiled. It is a non-blocking access.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_mutex_1_msg_put_t;

typedef union {
  struct {
    unsigned int msg             :32; // Message popped when taking hardware mutex 1 data bitfiled. It is a blocking access.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_mutex_1_msg_get_t;

typedef union {
  struct {
    unsigned int sw0t            :8 ; // Triggers software event 0 for cluster core i if SW0T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_0_trig_t;

typedef union {
  struct {
    unsigned int sw1t            :8 ; // Triggers software event 1 for cluster core i if SW1T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_1_trig_t;

typedef union {
  struct {
    unsigned int sw2t            :8 ; // Triggers software event 2 for cluster core i if SW2T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_2_trig_t;

typedef union {
  struct {
    unsigned int sw3t            :8 ; // Triggers software event 3 for cluster core i if SW3T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_3_trig_t;

typedef union {
  struct {
    unsigned int sw4t            :8 ; // Triggers software event 4 for cluster core i if SW4T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_4_trig_t;

typedef union {
  struct {
    unsigned int sw5t            :8 ; // Triggers software event 5 for cluster core i if SW5T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_5_trig_t;

typedef union {
  struct {
    unsigned int sw6t            :8 ; // Triggers software event 6 for cluster core i if SW6T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_6_trig_t;

typedef union {
  struct {
    unsigned int sw7t            :8 ; // Triggers software event 7 for cluster core i if SW7T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_7_trig_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 0 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_0_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 1 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_1_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 2 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_2_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 3 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_3_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 4 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_4_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 5 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_5_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 6 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_6_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 7 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_7_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 0 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_0_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 1 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_1_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 2 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_2_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 3 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_3_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 4 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_4_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 5 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_5_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 6 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_6_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Triggers software event 7 to all cluster cores targeted in SW_EVENT_MASK and gate the issuing cluster core clock until at least one unmasked event occurs. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_sw_event_7_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int id              :8 ; // Oldest SoC peripheral event ID status bitfield.
    unsigned int valid           :1 ; // Validity bit of SOC_PERIPH_EVENT_ID.ID bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) eu_soc_periph_event_id_t;

typedef union {
  struct {
    unsigned int hb0tm           :8 ; // Trigger mask for hardware barrier 0 bitfield. Hardware barrier 0 will be triggered only if for all HB0TM[i] = 1'b1,  HW_BARRIER_0_STATUS.HB0S[i]=1'b1. HB0TM=0 means that hardware barrier 0 is disabled.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_0_trig_mask_t;

typedef union {
  struct {
    unsigned int hb1tm           :8 ; // Trigger mask for hardware barrier 1 bitfield. Hardware barrier 1 will be triggered only if for all HB1TM[i] = 1'b1,  HW_BARRIER_1_STATUS.HB1S[i]=1'b1. HB1TM=0 means that hardware barrier 1 is disabled.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_1_trig_mask_t;

typedef union {
  struct {
    unsigned int hb2tm           :8 ; // Trigger mask for hardware barrier 2 bitfield. Hardware barrier 2 will be triggered only if for all HB2TM[i] = 1'b1,  HW_BARRIER_2_STATUS.HB2S[i]=1'b1. HB2TM=0 means that hardware barrier 2 is disabled.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_2_trig_mask_t;

typedef union {
  struct {
    unsigned int hb3tm           :8 ; // Trigger mask for hardware barrier 3 bitfield. Hardware barrier 3 will be triggered only if for all HB3TM[i] = 1'b1,  HW_BARRIER_3_STATUS.HB3S[i]=1'b1. HB3TM=0 means that hardware barrier 3 is disabled.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_3_trig_mask_t;

typedef union {
  struct {
    unsigned int hb4tm           :8 ; // Trigger mask for hardware barrier 4 bitfield. Hardware barrier 4 will be triggered only if for all HB4TM[i] = 1'b1,  HW_BARRIER_4_STATUS.HB4S[i]=1'b1. HB4TM=0 means that hardware barrier 4 is disabled.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_4_trig_mask_t;

typedef union {
  struct {
    unsigned int hb5tm           :8 ; // Trigger mask for hardware barrier 5 bitfield. Hardware barrier 5 will be triggered only if for all HB5TM[i] = 1'b1,  HW_BARRIER_5_STATUS.HB5S[i]=1'b1. HB5TM=0 means that hardware barrier 5 is disabled.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_5_trig_mask_t;

typedef union {
  struct {
    unsigned int hb6tm           :8 ; // Trigger mask for hardware barrier 6 bitfield. Hardware barrier 6 will be triggered only if for all HB6TM[i] = 1'b1,  HW_BARRIER_6_STATUS.HB6S[i]=1'b1. HB6TM=0 means that hardware barrier 6 is disabled.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_6_trig_mask_t;

typedef union {
  struct {
    unsigned int hb7tm           :8 ; // Trigger mask for hardware barrier 7 bitfield. Hardware barrier 7 will be triggered only if for all HB7TM[i] = 1'b1,  HW_BARRIER_7_STATUS.HB7S[i]=1'b1. HB7TM=0 means that hardware barrier 7 is disabled.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_7_trig_mask_t;

typedef union {
  struct {
    unsigned int hbs             :8 ; // Current status of hardware barrier 0 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 0. It is cleared when HBS matches HW_BARRIER_0_TRIG_MASK.HB0TM.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_0_status_t;

typedef union {
  struct {
    unsigned int hbs             :8 ; // Current status of hardware barrier 1 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 1. It is cleared when HBS matches HW_BARRIER_1_TRIG_MASK.HB1TM.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_1_status_t;

typedef union {
  struct {
    unsigned int hbs             :8 ; // Current status of hardware barrier 2 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 2. It is cleared when HBS matches HW_BARRIER_2_TRIG_MASK.HB2TM.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_2_status_t;

typedef union {
  struct {
    unsigned int hbs             :8 ; // Current status of hardware barrier 3 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 3. It is cleared when HBS matches HW_BARRIER_3_TRIG_MASK.HB3TM.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_3_status_t;

typedef union {
  struct {
    unsigned int hbs             :8 ; // Current status of hardware barrier 4 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 4. It is cleared when HBS matches HW_BARRIER_4_TRIG_MASK.HB4TM.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_4_status_t;

typedef union {
  struct {
    unsigned int hbs             :8 ; // Current status of hardware barrier 5 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 5. It is cleared when HBS matches HW_BARRIER_5_TRIG_MASK.HB5TM.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_5_status_t;

typedef union {
  struct {
    unsigned int hbs             :8 ; // Current status of hardware barrier 6 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 6. It is cleared when HBS matches HW_BARRIER_6_TRIG_MASK.HB6TM.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_6_status_t;

typedef union {
  struct {
    unsigned int hbs             :8 ; // Current status of hardware barrier 7 bitfield. HBS[i]=1'b1 means that cluster core i has triggered hardware barrier 7. It is cleared when HBS matches HW_BARRIER_7_TRIG_MASK.HB7TM.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_7_status_t;

typedef union {
  struct {
    unsigned int hbss            :8 ; // Current status of hardware barrier 0. HBSS[i] represents a summary of the barrier status for core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_0_status_sum_t;

typedef union {
  struct {
    unsigned int hbss            :8 ; // Current status of hardware barrier 1. HBSS[i] represents a summary of the barrier status for core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_1_status_sum_t;

typedef union {
  struct {
    unsigned int hbss            :8 ; // Current status of hardware barrier 2. HBSS[i] represents a summary of the barrier status for core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_2_status_sum_t;

typedef union {
  struct {
    unsigned int hbss            :8 ; // Current status of hardware barrier 3. HBSS[i] represents a summary of the barrier status for core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_3_status_sum_t;

typedef union {
  struct {
    unsigned int hbss            :8 ; // Current status of hardware barrier 4. HBSS[i] represents a summary of the barrier status for core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_4_status_sum_t;

typedef union {
  struct {
    unsigned int hbss            :8 ; // Current status of hardware barrier 5. HBSS[i] represents a summary of the barrier status for core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_5_status_sum_t;

typedef union {
  struct {
    unsigned int hbss            :8 ; // Current status of hardware barrier 6. HBSS[i] represents a summary of the barrier status for core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_6_status_sum_t;

typedef union {
  struct {
    unsigned int hbss            :8 ; // Current status of hardware barrier 7. HBSS[i] represents a summary of the barrier status for core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_7_status_sum_t;

typedef union {
  struct {
    unsigned int hbtam           :8 ; // Cluster hardware barrier 0 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 0 event when HW_BARRIER_0_STATUS will match HW_BARRIER_0_TRIG_MASK.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_0_target_mask_t;

typedef union {
  struct {
    unsigned int hbtam           :8 ; // Cluster hardware barrier 1 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 1 event when HW_BARRIER_1_STATUS will match HW_BARRIER_1_TRIG_MASK.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_1_target_mask_t;

typedef union {
  struct {
    unsigned int hbtam           :8 ; // Cluster hardware barrier 2 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 2 event when HW_BARRIER_2_STATUS will match HW_BARRIER_2_TRIG_MASK.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_2_target_mask_t;

typedef union {
  struct {
    unsigned int hbtam           :8 ; // Cluster hardware barrier 3 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 3 event when HW_BARRIER_3_STATUS will match HW_BARRIER_3_TRIG_MASK.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_3_target_mask_t;

typedef union {
  struct {
    unsigned int hbtam           :8 ; // Cluster hardware barrier 4 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 4 event when HW_BARRIER_4_STATUS will match HW_BARRIER_4_TRIG_MASK.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_4_target_mask_t;

typedef union {
  struct {
    unsigned int hbtam           :8 ; // Cluster hardware barrier 5 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 5 event when HW_BARRIER_5_STATUS will match HW_BARRIER_5_TRIG_MASK.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_5_target_mask_t;

typedef union {
  struct {
    unsigned int hbtam           :8 ; // Cluster hardware barrier 6 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 6 event when HW_BARRIER_6_STATUS will match HW_BARRIER_6_TRIG_MASK.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_6_target_mask_t;

typedef union {
  struct {
    unsigned int hbtam           :8 ; // Cluster hardware barrier 7 target mask configuration bitfield. HBATM[i]=1'b1 means that cluster core i will receive hardware barrier 7 event when HW_BARRIER_7_STATUS will match HW_BARRIER_7_TRIG_MASK.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_7_target_mask_t;

typedef union {
  struct {
    unsigned int t               :8 ; // Sets HW_BARRIER_0_STATUS.HBS[i] to 1'b1 when T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_0_trig_t;

typedef union {
  struct {
    unsigned int t               :8 ; // Sets HW_BARRIER_1_STATUS.HBS[i] to 1'b1 when T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_1_trig_t;

typedef union {
  struct {
    unsigned int t               :8 ; // Sets HW_BARRIER_2_STATUS.HBS[i] to 1'b1 when T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_2_trig_t;

typedef union {
  struct {
    unsigned int t               :8 ; // Sets HW_BARRIER_3_STATUS.HBS[i] to 1'b1 when T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_3_trig_t;

typedef union {
  struct {
    unsigned int t               :8 ; // Sets HW_BARRIER_4_STATUS.HBS[i] to 1'b1 when T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_4_trig_t;

typedef union {
  struct {
    unsigned int t               :8 ; // Sets HW_BARRIER_5_STATUS.HBS[i] to 1'b1 when T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_5_trig_t;

typedef union {
  struct {
    unsigned int t               :8 ; // Sets HW_BARRIER_6_STATUS.HBS[i] to 1'b1 when T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_6_trig_t;

typedef union {
  struct {
    unsigned int t               :8 ; // Sets HW_BARRIER_7_STATUS.HBS[i] to 1'b1 when T[i]=1'b1.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_7_trig_t;

typedef union {
  struct {
    unsigned int t               :32; // Sets HW_BARRIER_0_STATUS.HBS[i] to 1'b1 when issued by cluster core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_0_self_trig_t;

typedef union {
  struct {
    unsigned int t               :32; // Sets HW_BARRIER_1_STATUS.HBS[i] to 1'b1 when issued by cluster core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_1_self_trig_t;

typedef union {
  struct {
    unsigned int t               :32; // Sets HW_BARRIER_2_STATUS.HBS[i] to 1'b1 when issued by cluster core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_2_self_trig_t;

typedef union {
  struct {
    unsigned int t               :32; // Sets HW_BARRIER_3_STATUS.HBS[i] to 1'b1 when issued by cluster core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_3_self_trig_t;

typedef union {
  struct {
    unsigned int t               :32; // Sets HW_BARRIER_4_STATUS.HBS[i] to 1'b1 when issued by cluster core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_4_self_trig_t;

typedef union {
  struct {
    unsigned int t               :32; // Sets HW_BARRIER_5_STATUS.HBS[i] to 1'b1 when issued by cluster core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_5_self_trig_t;

typedef union {
  struct {
    unsigned int t               :32; // Sets HW_BARRIER_6_STATUS.HBS[i] to 1'b1 when issued by cluster core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_6_self_trig_t;

typedef union {
  struct {
    unsigned int t               :32; // Sets HW_BARRIER_7_STATUS.HBS[i] to 1'b1 when issued by cluster core i.
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_7_self_trig_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_0[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_0 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_0_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_1[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_1 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_1_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_2[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_2 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_2_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_3[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_3 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_3_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_4[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_4 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_4_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_5[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_5 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_5_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_6[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_6 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_6_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_7[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_7 is released. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_7_trig_wait_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_0[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_0 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_0_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_1[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_1 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_1_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_2[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_2 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_2_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_3[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_3 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_3_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_4[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_4 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_4_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_5[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_5 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_5_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_6[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_6 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_6_trig_wait_clear_t;

typedef union {
  struct {
    unsigned int ebm             :32; // Set HW_BARRIER_7[i] when issued by cluster core i and gate the issuing cluster core i clock until HW_BARRIER_7 is released. In addition, EVENT_BUFFER.EB[i] bits are cleared after the read if EVT_MASK[i]=1'b1. The read content of this bitfield is equivalent to EVENT_BUFFER_MASKED.EBM
  };
  unsigned int raw;
} __attribute__((packed)) eu_hw_barrier_7_trig_wait_clear_t;

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int evt_mask        ; // Input event mask configuration register.
  unsigned int evt_mask_and    ; // Input event mask update command register with bitwise AND operation.
  unsigned int evt_mask_or     ; // Input event mask update command register with bitwise OR operation.
  unsigned int irq_mask        ; // Interrupt request mask configuration register.
  unsigned int irq_mask_and    ; // Interrupt request mask update command register with bitwise AND operation.
  unsigned int irq_mask_or     ; // Interrupt request mask update command register with bitwise OR operation.
  unsigned int clock_status    ; // Cluster cores clock status register.
  unsigned int event_buffer    ; // Pending input events status register.
  unsigned int event_buffer_masked; // Pending input events status register with EVT_MASK applied.
  unsigned int event_buffer_irq_masked; // Pending input events status register with IRQ_MASK applied.
  unsigned int event_buffer_clear; // Pending input events status clear command register.
  unsigned int sw_event_mask   ; // Software events cluster cores destination mask configuration register.
  unsigned int sw_event_mask_and; // Software events cluster cores destination mask update command register with bitwise AND operation.
  unsigned int sw_event_mask_or; // Software events cluster cores destination mask update command register with bitwise OR operation.
  unsigned int event_wait      ; // Input event wait command register.
  unsigned int event_wait_clear; // Input event wait and clear command register.
  unsigned int hw_dispatch_push_task; // Hardware task dispatcher push command register.
  unsigned int hw_dispatch_pop_task; // Hardware task dispatcher pop command register.
  unsigned int hw_dispatch_push_team_config; // Hardware task dispatcher cluster core team configuration register.
  unsigned int hw_mutex_0_msg_put; // Hardware mutex 0 non-blocking put command register.
  unsigned int hw_mutex_0_msg_get; // Hardware mutex 0 blocking get command register.
  unsigned int hw_mutex_1_msg_put; // Hardware mutex 1 non-blocking put command register.
  unsigned int hw_mutex_1_msg_get; // Hardware mutex 1 blocking get command register.
  unsigned int sw_event_0_trig ; // Cluster Software event 0 trigger command register.
  unsigned int sw_event_1_trig ; // Cluster Software event 1 trigger command register.
  unsigned int sw_event_2_trig ; // Cluster Software event 2 trigger command register.
  unsigned int sw_event_3_trig ; // Cluster Software event 3 trigger command register.
  unsigned int sw_event_4_trig ; // Cluster Software event 4 trigger command register.
  unsigned int sw_event_5_trig ; // Cluster Software event 5 trigger command register.
  unsigned int sw_event_6_trig ; // Cluster Software event 6 trigger command register.
  unsigned int sw_event_7_trig ; // Cluster Software event 7 trigger command register.
  unsigned int sw_event_0_trig_wait; // Cluster Software event 0 trigger and wait command register.
  unsigned int sw_event_1_trig_wait; // Cluster Software event 1 trigger and wait command register.
  unsigned int sw_event_2_trig_wait; // Cluster Software event 2 trigger and wait command register.
  unsigned int sw_event_3_trig_wait; // Cluster Software event 3 trigger and wait command register.
  unsigned int sw_event_4_trig_wait; // Cluster Software event 4 trigger and wait command register.
  unsigned int sw_event_5_trig_wait; // Cluster Software event 5 trigger and wait command register.
  unsigned int sw_event_6_trig_wait; // Cluster Software event 6 trigger and wait command register.
  unsigned int sw_event_7_trig_wait; // Cluster Software event 7 trigger and wait command register.
  unsigned int sw_event_0_trig_wait_clear; // Cluster Software event 0 trigger, wait and clear command register.
  unsigned int sw_event_1_trig_wait_clear; // Cluster Software event 1 trigger, wait and clear command register.
  unsigned int sw_event_2_trig_wait_clear; // Cluster Software event 2 trigger, wait and clear command register.
  unsigned int sw_event_3_trig_wait_clear; // Cluster Software event 3 trigger, wait and clear command register.
  unsigned int sw_event_4_trig_wait_clear; // Cluster Software event 4 trigger, wait and clear command register.
  unsigned int sw_event_5_trig_wait_clear; // Cluster Software event 5 trigger, wait and clear command register.
  unsigned int sw_event_6_trig_wait_clear; // Cluster Software event 6 trigger, wait and clear command register.
  unsigned int sw_event_7_trig_wait_clear; // Cluster Software event 7 trigger, wait and clear command register.
  unsigned int soc_periph_event_id; // Cluster SoC peripheral event ID status register.
  unsigned int hw_barrier_0_trig_mask; // Cluster hardware barrier 0 trigger mask configuration register.
  unsigned int hw_barrier_1_trig_mask; // Cluster hardware barrier 1 trigger mask configuration register.
  unsigned int hw_barrier_2_trig_mask; // Cluster hardware barrier 2 trigger mask configuration register.
  unsigned int hw_barrier_3_trig_mask; // Cluster hardware barrier 3 trigger mask configuration register.
  unsigned int hw_barrier_4_trig_mask; // Cluster hardware barrier 4 trigger mask configuration register.
  unsigned int hw_barrier_5_trig_mask; // Cluster hardware barrier 5 trigger mask configuration register.
  unsigned int hw_barrier_6_trig_mask; // Cluster hardware barrier 6 trigger mask configuration register.
  unsigned int hw_barrier_7_trig_mask; // Cluster hardware barrier 7 trigger mask configuration register.
  unsigned int hw_barrier_0_status; // Cluster hardware barrier 0 status register.
  unsigned int hw_barrier_1_status; // Cluster hardware barrier 1 status register.
  unsigned int hw_barrier_2_status; // Cluster hardware barrier 2 status register.
  unsigned int hw_barrier_3_status; // Cluster hardware barrier 3 status register.
  unsigned int hw_barrier_4_status; // Cluster hardware barrier 4 status register.
  unsigned int hw_barrier_5_status; // Cluster hardware barrier 5 status register.
  unsigned int hw_barrier_6_status; // Cluster hardware barrier 6 status register.
  unsigned int hw_barrier_7_status; // Cluster hardware barrier 7 status register.
  unsigned int hw_barrier_0_status_sum; // Cluster hardware barrier summary status register.
  unsigned int hw_barrier_1_status_sum; // Cluster hardware barrier summary status register.
  unsigned int hw_barrier_2_status_sum; // Cluster hardware barrier summary status register.
  unsigned int hw_barrier_3_status_sum; // Cluster hardware barrier summary status register.
  unsigned int hw_barrier_4_status_sum; // Cluster hardware barrier summary status register.
  unsigned int hw_barrier_5_status_sum; // Cluster hardware barrier summary status register.
  unsigned int hw_barrier_6_status_sum; // Cluster hardware barrier summary status register.
  unsigned int hw_barrier_7_status_sum; // Cluster hardware barrier summary status register.
  unsigned int hw_barrier_0_target_mask; // Cluster hardware barrier 0 target mask configuration register.
  unsigned int hw_barrier_1_target_mask; // Cluster hardware barrier 1 target mask configuration register.
  unsigned int hw_barrier_2_target_mask; // Cluster hardware barrier 2 target mask configuration register.
  unsigned int hw_barrier_3_target_mask; // Cluster hardware barrier 3 target mask configuration register.
  unsigned int hw_barrier_4_target_mask; // Cluster hardware barrier 4 target mask configuration register.
  unsigned int hw_barrier_5_target_mask; // Cluster hardware barrier 5 target mask configuration register.
  unsigned int hw_barrier_6_target_mask; // Cluster hardware barrier 6 target mask configuration register.
  unsigned int hw_barrier_7_target_mask; // Cluster hardware barrier 7 target mask configuration register.
  unsigned int hw_barrier_0_trig; // Cluster hardware barrier 0 trigger command register.
  unsigned int hw_barrier_1_trig; // Cluster hardware barrier 1 trigger command register.
  unsigned int hw_barrier_2_trig; // Cluster hardware barrier 2 trigger command register.
  unsigned int hw_barrier_3_trig; // Cluster hardware barrier 3 trigger command register.
  unsigned int hw_barrier_4_trig; // Cluster hardware barrier 4 trigger command register.
  unsigned int hw_barrier_5_trig; // Cluster hardware barrier 5 trigger command register.
  unsigned int hw_barrier_6_trig; // Cluster hardware barrier 6 trigger command register.
  unsigned int hw_barrier_7_trig; // Cluster hardware barrier 7 trigger command register.
  unsigned int hw_barrier_0_self_trig; // Cluster hardware barrier 0 self trigger command register.
  unsigned int hw_barrier_1_self_trig; // Cluster hardware barrier 1 self trigger command register.
  unsigned int hw_barrier_2_self_trig; // Cluster hardware barrier 2 self trigger command register.
  unsigned int hw_barrier_3_self_trig; // Cluster hardware barrier 3 self trigger command register.
  unsigned int hw_barrier_4_self_trig; // Cluster hardware barrier 4 self trigger command register.
  unsigned int hw_barrier_5_self_trig; // Cluster hardware barrier 5 self trigger command register.
  unsigned int hw_barrier_6_self_trig; // Cluster hardware barrier 6 self trigger command register.
  unsigned int hw_barrier_7_self_trig; // Cluster hardware barrier 7 self trigger command register.
  unsigned int hw_barrier_0_trig_wait; // Cluster hardware barrier 0 trigger and wait command register.
  unsigned int hw_barrier_1_trig_wait; // Cluster hardware barrier 1 trigger and wait command register.
  unsigned int hw_barrier_2_trig_wait; // Cluster hardware barrier 2 trigger and wait command register.
  unsigned int hw_barrier_3_trig_wait; // Cluster hardware barrier 3 trigger and wait command register.
  unsigned int hw_barrier_4_trig_wait; // Cluster hardware barrier 4 trigger and wait command register.
  unsigned int hw_barrier_5_trig_wait; // Cluster hardware barrier 5 trigger and wait command register.
  unsigned int hw_barrier_6_trig_wait; // Cluster hardware barrier 6 trigger and wait command register.
  unsigned int hw_barrier_7_trig_wait; // Cluster hardware barrier 7 trigger and wait command register.
  unsigned int hw_barrier_0_trig_wait_clear; // Cluster hardware barrier 0 trigger, wait and clear command register.
  unsigned int hw_barrier_1_trig_wait_clear; // Cluster hardware barrier 1 trigger, wait and clear command register.
  unsigned int hw_barrier_2_trig_wait_clear; // Cluster hardware barrier 2 trigger, wait and clear command register.
  unsigned int hw_barrier_3_trig_wait_clear; // Cluster hardware barrier 3 trigger, wait and clear command register.
  unsigned int hw_barrier_4_trig_wait_clear; // Cluster hardware barrier 4 trigger, wait and clear command register.
  unsigned int hw_barrier_5_trig_wait_clear; // Cluster hardware barrier 5 trigger, wait and clear command register.
  unsigned int hw_barrier_6_trig_wait_clear; // Cluster hardware barrier 6 trigger, wait and clear command register.
  unsigned int hw_barrier_7_trig_wait_clear; // Cluster hardware barrier 7 trigger, wait and clear command register.
} __attribute__((packed)) eu_eu_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t eu_evt_mask_get(uint32_t base) { return ARCHI_READ(base, EU_EVT_MASK_OFFSET); }
static inline void eu_evt_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_EVT_MASK_OFFSET, value); }

static inline uint32_t eu_evt_mask_and_get(uint32_t base) { return ARCHI_READ(base, EU_EVT_MASK_AND_OFFSET); }
static inline void eu_evt_mask_and_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_EVT_MASK_AND_OFFSET, value); }

static inline uint32_t eu_evt_mask_or_get(uint32_t base) { return ARCHI_READ(base, EU_EVT_MASK_OR_OFFSET); }
static inline void eu_evt_mask_or_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_EVT_MASK_OR_OFFSET, value); }

static inline uint32_t eu_irq_mask_get(uint32_t base) { return ARCHI_READ(base, EU_IRQ_MASK_OFFSET); }
static inline void eu_irq_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_IRQ_MASK_OFFSET, value); }

static inline uint32_t eu_irq_mask_and_get(uint32_t base) { return ARCHI_READ(base, EU_IRQ_MASK_AND_OFFSET); }
static inline void eu_irq_mask_and_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_IRQ_MASK_AND_OFFSET, value); }

static inline uint32_t eu_irq_mask_or_get(uint32_t base) { return ARCHI_READ(base, EU_IRQ_MASK_OR_OFFSET); }
static inline void eu_irq_mask_or_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_IRQ_MASK_OR_OFFSET, value); }

static inline uint32_t eu_clock_status_get(uint32_t base) { return ARCHI_READ(base, EU_CLOCK_STATUS_OFFSET); }
static inline void eu_clock_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_CLOCK_STATUS_OFFSET, value); }

static inline uint32_t eu_event_buffer_get(uint32_t base) { return ARCHI_READ(base, EU_EVENT_BUFFER_OFFSET); }
static inline void eu_event_buffer_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_EVENT_BUFFER_OFFSET, value); }

static inline uint32_t eu_event_buffer_masked_get(uint32_t base) { return ARCHI_READ(base, EU_EVENT_BUFFER_MASKED_OFFSET); }
static inline void eu_event_buffer_masked_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_EVENT_BUFFER_MASKED_OFFSET, value); }

static inline uint32_t eu_event_buffer_irq_masked_get(uint32_t base) { return ARCHI_READ(base, EU_EVENT_BUFFER_IRQ_MASKED_OFFSET); }
static inline void eu_event_buffer_irq_masked_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_EVENT_BUFFER_IRQ_MASKED_OFFSET, value); }

static inline uint32_t eu_event_buffer_clear_get(uint32_t base) { return ARCHI_READ(base, EU_EVENT_BUFFER_CLEAR_OFFSET); }
static inline void eu_event_buffer_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_EVENT_BUFFER_CLEAR_OFFSET, value); }

static inline uint32_t eu_sw_event_mask_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_MASK_OFFSET); }
static inline void eu_sw_event_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_MASK_OFFSET, value); }

static inline uint32_t eu_sw_event_mask_and_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_MASK_AND_OFFSET); }
static inline void eu_sw_event_mask_and_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_MASK_AND_OFFSET, value); }

static inline uint32_t eu_sw_event_mask_or_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_MASK_OR_OFFSET); }
static inline void eu_sw_event_mask_or_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_MASK_OR_OFFSET, value); }

static inline uint32_t eu_event_wait_get(uint32_t base) { return ARCHI_READ(base, EU_EVENT_WAIT_OFFSET); }
static inline void eu_event_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_EVENT_WAIT_OFFSET, value); }

static inline uint32_t eu_event_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_EVENT_WAIT_CLEAR_OFFSET); }
static inline void eu_event_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_EVENT_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_hw_dispatch_push_task_get(uint32_t base) { return ARCHI_READ(base, EU_HW_DISPATCH_PUSH_TASK_OFFSET); }
static inline void eu_hw_dispatch_push_task_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_DISPATCH_PUSH_TASK_OFFSET, value); }

static inline uint32_t eu_hw_dispatch_pop_task_get(uint32_t base) { return ARCHI_READ(base, EU_HW_DISPATCH_POP_TASK_OFFSET); }
static inline void eu_hw_dispatch_pop_task_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_DISPATCH_POP_TASK_OFFSET, value); }

static inline uint32_t eu_hw_dispatch_push_team_config_get(uint32_t base) { return ARCHI_READ(base, EU_HW_DISPATCH_PUSH_TEAM_CONFIG_OFFSET); }
static inline void eu_hw_dispatch_push_team_config_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_DISPATCH_PUSH_TEAM_CONFIG_OFFSET, value); }

static inline uint32_t eu_hw_mutex_0_msg_put_get(uint32_t base) { return ARCHI_READ(base, EU_HW_MUTEX_0_MSG_PUT_OFFSET); }
static inline void eu_hw_mutex_0_msg_put_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_MUTEX_0_MSG_PUT_OFFSET, value); }

static inline uint32_t eu_hw_mutex_0_msg_get_get(uint32_t base) { return ARCHI_READ(base, EU_HW_MUTEX_0_MSG_GET_OFFSET); }
static inline void eu_hw_mutex_0_msg_get_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_MUTEX_0_MSG_GET_OFFSET, value); }

static inline uint32_t eu_hw_mutex_1_msg_put_get(uint32_t base) { return ARCHI_READ(base, EU_HW_MUTEX_1_MSG_PUT_OFFSET); }
static inline void eu_hw_mutex_1_msg_put_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_MUTEX_1_MSG_PUT_OFFSET, value); }

static inline uint32_t eu_hw_mutex_1_msg_get_get(uint32_t base) { return ARCHI_READ(base, EU_HW_MUTEX_1_MSG_GET_OFFSET); }
static inline void eu_hw_mutex_1_msg_get_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_MUTEX_1_MSG_GET_OFFSET, value); }

static inline uint32_t eu_sw_event_0_trig_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_0_TRIG_OFFSET); }
static inline void eu_sw_event_0_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_0_TRIG_OFFSET, value); }

static inline uint32_t eu_sw_event_1_trig_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_1_TRIG_OFFSET); }
static inline void eu_sw_event_1_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_1_TRIG_OFFSET, value); }

static inline uint32_t eu_sw_event_2_trig_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_2_TRIG_OFFSET); }
static inline void eu_sw_event_2_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_2_TRIG_OFFSET, value); }

static inline uint32_t eu_sw_event_3_trig_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_3_TRIG_OFFSET); }
static inline void eu_sw_event_3_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_3_TRIG_OFFSET, value); }

static inline uint32_t eu_sw_event_4_trig_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_4_TRIG_OFFSET); }
static inline void eu_sw_event_4_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_4_TRIG_OFFSET, value); }

static inline uint32_t eu_sw_event_5_trig_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_5_TRIG_OFFSET); }
static inline void eu_sw_event_5_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_5_TRIG_OFFSET, value); }

static inline uint32_t eu_sw_event_6_trig_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_6_TRIG_OFFSET); }
static inline void eu_sw_event_6_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_6_TRIG_OFFSET, value); }

static inline uint32_t eu_sw_event_7_trig_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_7_TRIG_OFFSET); }
static inline void eu_sw_event_7_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_7_TRIG_OFFSET, value); }

static inline uint32_t eu_sw_event_0_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_0_TRIG_WAIT_OFFSET); }
static inline void eu_sw_event_0_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_0_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_sw_event_1_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_1_TRIG_WAIT_OFFSET); }
static inline void eu_sw_event_1_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_1_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_sw_event_2_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_2_TRIG_WAIT_OFFSET); }
static inline void eu_sw_event_2_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_2_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_sw_event_3_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_3_TRIG_WAIT_OFFSET); }
static inline void eu_sw_event_3_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_3_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_sw_event_4_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_4_TRIG_WAIT_OFFSET); }
static inline void eu_sw_event_4_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_4_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_sw_event_5_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_5_TRIG_WAIT_OFFSET); }
static inline void eu_sw_event_5_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_5_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_sw_event_6_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_6_TRIG_WAIT_OFFSET); }
static inline void eu_sw_event_6_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_6_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_sw_event_7_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_7_TRIG_WAIT_OFFSET); }
static inline void eu_sw_event_7_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_7_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_sw_event_0_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_0_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_sw_event_0_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_0_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_sw_event_1_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_1_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_sw_event_1_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_1_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_sw_event_2_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_2_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_sw_event_2_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_2_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_sw_event_3_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_3_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_sw_event_3_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_3_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_sw_event_4_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_4_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_sw_event_4_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_4_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_sw_event_5_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_5_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_sw_event_5_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_5_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_sw_event_6_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_6_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_sw_event_6_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_6_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_sw_event_7_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_SW_EVENT_7_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_sw_event_7_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SW_EVENT_7_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_soc_periph_event_id_get(uint32_t base) { return ARCHI_READ(base, EU_SOC_PERIPH_EVENT_ID_OFFSET); }
static inline void eu_soc_periph_event_id_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_SOC_PERIPH_EVENT_ID_OFFSET, value); }

static inline uint32_t eu_hw_barrier_0_trig_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_0_TRIG_MASK_OFFSET); }
static inline void eu_hw_barrier_0_trig_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_0_TRIG_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_1_trig_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_1_TRIG_MASK_OFFSET); }
static inline void eu_hw_barrier_1_trig_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_1_TRIG_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_2_trig_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_2_TRIG_MASK_OFFSET); }
static inline void eu_hw_barrier_2_trig_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_2_TRIG_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_3_trig_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_3_TRIG_MASK_OFFSET); }
static inline void eu_hw_barrier_3_trig_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_3_TRIG_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_4_trig_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_4_TRIG_MASK_OFFSET); }
static inline void eu_hw_barrier_4_trig_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_4_TRIG_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_5_trig_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_5_TRIG_MASK_OFFSET); }
static inline void eu_hw_barrier_5_trig_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_5_TRIG_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_6_trig_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_6_TRIG_MASK_OFFSET); }
static inline void eu_hw_barrier_6_trig_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_6_TRIG_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_7_trig_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_7_TRIG_MASK_OFFSET); }
static inline void eu_hw_barrier_7_trig_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_7_TRIG_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_0_status_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_0_STATUS_OFFSET); }
static inline void eu_hw_barrier_0_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_0_STATUS_OFFSET, value); }

static inline uint32_t eu_hw_barrier_1_status_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_1_STATUS_OFFSET); }
static inline void eu_hw_barrier_1_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_1_STATUS_OFFSET, value); }

static inline uint32_t eu_hw_barrier_2_status_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_2_STATUS_OFFSET); }
static inline void eu_hw_barrier_2_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_2_STATUS_OFFSET, value); }

static inline uint32_t eu_hw_barrier_3_status_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_3_STATUS_OFFSET); }
static inline void eu_hw_barrier_3_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_3_STATUS_OFFSET, value); }

static inline uint32_t eu_hw_barrier_4_status_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_4_STATUS_OFFSET); }
static inline void eu_hw_barrier_4_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_4_STATUS_OFFSET, value); }

static inline uint32_t eu_hw_barrier_5_status_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_5_STATUS_OFFSET); }
static inline void eu_hw_barrier_5_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_5_STATUS_OFFSET, value); }

static inline uint32_t eu_hw_barrier_6_status_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_6_STATUS_OFFSET); }
static inline void eu_hw_barrier_6_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_6_STATUS_OFFSET, value); }

static inline uint32_t eu_hw_barrier_7_status_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_7_STATUS_OFFSET); }
static inline void eu_hw_barrier_7_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_7_STATUS_OFFSET, value); }

static inline uint32_t eu_hw_barrier_0_status_sum_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_0_STATUS_SUM_OFFSET); }
static inline void eu_hw_barrier_0_status_sum_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_0_STATUS_SUM_OFFSET, value); }

static inline uint32_t eu_hw_barrier_1_status_sum_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_1_STATUS_SUM_OFFSET); }
static inline void eu_hw_barrier_1_status_sum_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_1_STATUS_SUM_OFFSET, value); }

static inline uint32_t eu_hw_barrier_2_status_sum_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_2_STATUS_SUM_OFFSET); }
static inline void eu_hw_barrier_2_status_sum_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_2_STATUS_SUM_OFFSET, value); }

static inline uint32_t eu_hw_barrier_3_status_sum_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_3_STATUS_SUM_OFFSET); }
static inline void eu_hw_barrier_3_status_sum_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_3_STATUS_SUM_OFFSET, value); }

static inline uint32_t eu_hw_barrier_4_status_sum_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_4_STATUS_SUM_OFFSET); }
static inline void eu_hw_barrier_4_status_sum_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_4_STATUS_SUM_OFFSET, value); }

static inline uint32_t eu_hw_barrier_5_status_sum_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_5_STATUS_SUM_OFFSET); }
static inline void eu_hw_barrier_5_status_sum_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_5_STATUS_SUM_OFFSET, value); }

static inline uint32_t eu_hw_barrier_6_status_sum_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_6_STATUS_SUM_OFFSET); }
static inline void eu_hw_barrier_6_status_sum_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_6_STATUS_SUM_OFFSET, value); }

static inline uint32_t eu_hw_barrier_7_status_sum_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_7_STATUS_SUM_OFFSET); }
static inline void eu_hw_barrier_7_status_sum_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_7_STATUS_SUM_OFFSET, value); }

static inline uint32_t eu_hw_barrier_0_target_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_0_TARGET_MASK_OFFSET); }
static inline void eu_hw_barrier_0_target_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_0_TARGET_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_1_target_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_1_TARGET_MASK_OFFSET); }
static inline void eu_hw_barrier_1_target_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_1_TARGET_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_2_target_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_2_TARGET_MASK_OFFSET); }
static inline void eu_hw_barrier_2_target_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_2_TARGET_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_3_target_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_3_TARGET_MASK_OFFSET); }
static inline void eu_hw_barrier_3_target_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_3_TARGET_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_4_target_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_4_TARGET_MASK_OFFSET); }
static inline void eu_hw_barrier_4_target_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_4_TARGET_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_5_target_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_5_TARGET_MASK_OFFSET); }
static inline void eu_hw_barrier_5_target_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_5_TARGET_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_6_target_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_6_TARGET_MASK_OFFSET); }
static inline void eu_hw_barrier_6_target_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_6_TARGET_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_7_target_mask_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_7_TARGET_MASK_OFFSET); }
static inline void eu_hw_barrier_7_target_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_7_TARGET_MASK_OFFSET, value); }

static inline uint32_t eu_hw_barrier_0_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_0_TRIG_OFFSET); }
static inline void eu_hw_barrier_0_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_0_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_1_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_1_TRIG_OFFSET); }
static inline void eu_hw_barrier_1_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_1_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_2_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_2_TRIG_OFFSET); }
static inline void eu_hw_barrier_2_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_2_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_3_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_3_TRIG_OFFSET); }
static inline void eu_hw_barrier_3_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_3_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_4_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_4_TRIG_OFFSET); }
static inline void eu_hw_barrier_4_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_4_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_5_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_5_TRIG_OFFSET); }
static inline void eu_hw_barrier_5_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_5_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_6_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_6_TRIG_OFFSET); }
static inline void eu_hw_barrier_6_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_6_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_7_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_7_TRIG_OFFSET); }
static inline void eu_hw_barrier_7_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_7_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_0_self_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_0_SELF_TRIG_OFFSET); }
static inline void eu_hw_barrier_0_self_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_0_SELF_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_1_self_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_1_SELF_TRIG_OFFSET); }
static inline void eu_hw_barrier_1_self_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_1_SELF_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_2_self_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_2_SELF_TRIG_OFFSET); }
static inline void eu_hw_barrier_2_self_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_2_SELF_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_3_self_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_3_SELF_TRIG_OFFSET); }
static inline void eu_hw_barrier_3_self_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_3_SELF_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_4_self_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_4_SELF_TRIG_OFFSET); }
static inline void eu_hw_barrier_4_self_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_4_SELF_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_5_self_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_5_SELF_TRIG_OFFSET); }
static inline void eu_hw_barrier_5_self_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_5_SELF_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_6_self_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_6_SELF_TRIG_OFFSET); }
static inline void eu_hw_barrier_6_self_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_6_SELF_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_7_self_trig_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_7_SELF_TRIG_OFFSET); }
static inline void eu_hw_barrier_7_self_trig_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_7_SELF_TRIG_OFFSET, value); }

static inline uint32_t eu_hw_barrier_0_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_0_TRIG_WAIT_OFFSET); }
static inline void eu_hw_barrier_0_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_0_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_hw_barrier_1_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_1_TRIG_WAIT_OFFSET); }
static inline void eu_hw_barrier_1_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_1_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_hw_barrier_2_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_2_TRIG_WAIT_OFFSET); }
static inline void eu_hw_barrier_2_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_2_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_hw_barrier_3_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_3_TRIG_WAIT_OFFSET); }
static inline void eu_hw_barrier_3_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_3_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_hw_barrier_4_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_4_TRIG_WAIT_OFFSET); }
static inline void eu_hw_barrier_4_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_4_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_hw_barrier_5_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_5_TRIG_WAIT_OFFSET); }
static inline void eu_hw_barrier_5_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_5_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_hw_barrier_6_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_6_TRIG_WAIT_OFFSET); }
static inline void eu_hw_barrier_6_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_6_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_hw_barrier_7_trig_wait_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_7_TRIG_WAIT_OFFSET); }
static inline void eu_hw_barrier_7_trig_wait_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_7_TRIG_WAIT_OFFSET, value); }

static inline uint32_t eu_hw_barrier_0_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_0_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_hw_barrier_0_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_0_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_hw_barrier_1_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_1_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_hw_barrier_1_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_1_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_hw_barrier_2_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_2_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_hw_barrier_2_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_2_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_hw_barrier_3_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_3_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_hw_barrier_3_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_3_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_hw_barrier_4_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_4_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_hw_barrier_4_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_4_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_hw_barrier_5_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_5_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_hw_barrier_5_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_5_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_hw_barrier_6_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_6_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_hw_barrier_6_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_6_TRIG_WAIT_CLEAR_OFFSET, value); }

static inline uint32_t eu_hw_barrier_7_trig_wait_clear_get(uint32_t base) { return ARCHI_READ(base, EU_HW_BARRIER_7_TRIG_WAIT_CLEAR_OFFSET); }
static inline void eu_hw_barrier_7_trig_wait_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, EU_HW_BARRIER_7_TRIG_WAIT_CLEAR_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#define EU_EVT_MASK_EMSOC_GET(value)                       (ARCHI_BEXTRACTU((value),1,31))
#define EU_EVT_MASK_EMSOC_GETS(value)                      (ARCHI_BEXTRACT((value),1,31))
#define EU_EVT_MASK_EMSOC_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,31))
#define EU_EVT_MASK_EMSOC(val)                             ((val) << 31)

#define EU_EVT_MASK_EMINTCL_GET(value)                     (ARCHI_BEXTRACTU((value),1,30))
#define EU_EVT_MASK_EMINTCL_GETS(value)                    (ARCHI_BEXTRACT((value),1,30))
#define EU_EVT_MASK_EMINTCL_SET(value,field)               (ARCHI_BINSERT((value),(field),1,30))
#define EU_EVT_MASK_EMINTCL(val)                           ((val) << 30)

#define EU_EVT_MASK_EMCL_GET(value)                        (ARCHI_BEXTRACTU((value),30,0))
#define EU_EVT_MASK_EMCL_GETS(value)                       (ARCHI_BEXTRACT((value),30,0))
#define EU_EVT_MASK_EMCL_SET(value,field)                  (ARCHI_BINSERT((value),(field),30,0))
#define EU_EVT_MASK_EMCL(val)                              ((val) << 0)

#define EU_EVT_MASK_AND_EMA_GET(value)                     (ARCHI_BEXTRACTU((value),32,0))
#define EU_EVT_MASK_AND_EMA_GETS(value)                    (ARCHI_BEXTRACT((value),32,0))
#define EU_EVT_MASK_AND_EMA_SET(value,field)               (ARCHI_BINSERT((value),(field),32,0))
#define EU_EVT_MASK_AND_EMA(val)                           ((val) << 0)

#define EU_EVT_MASK_OR_EMO_GET(value)                      (ARCHI_BEXTRACTU((value),32,0))
#define EU_EVT_MASK_OR_EMO_GETS(value)                     (ARCHI_BEXTRACT((value),32,0))
#define EU_EVT_MASK_OR_EMO_SET(value,field)                (ARCHI_BINSERT((value),(field),32,0))
#define EU_EVT_MASK_OR_EMO(val)                            ((val) << 0)

#define EU_IRQ_MASK_IMSOC_GET(value)                       (ARCHI_BEXTRACTU((value),1,31))
#define EU_IRQ_MASK_IMSOC_GETS(value)                      (ARCHI_BEXTRACT((value),1,31))
#define EU_IRQ_MASK_IMSOC_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,31))
#define EU_IRQ_MASK_IMSOC(val)                             ((val) << 31)

#define EU_IRQ_MASK_IMINTCL_GET(value)                     (ARCHI_BEXTRACTU((value),1,30))
#define EU_IRQ_MASK_IMINTCL_GETS(value)                    (ARCHI_BEXTRACT((value),1,30))
#define EU_IRQ_MASK_IMINTCL_SET(value,field)               (ARCHI_BINSERT((value),(field),1,30))
#define EU_IRQ_MASK_IMINTCL(val)                           ((val) << 30)

#define EU_IRQ_MASK_IMCL_GET(value)                        (ARCHI_BEXTRACTU((value),30,0))
#define EU_IRQ_MASK_IMCL_GETS(value)                       (ARCHI_BEXTRACT((value),30,0))
#define EU_IRQ_MASK_IMCL_SET(value,field)                  (ARCHI_BINSERT((value),(field),30,0))
#define EU_IRQ_MASK_IMCL(val)                              ((val) << 0)

#define EU_IRQ_MASK_AND_IMA_GET(value)                     (ARCHI_BEXTRACTU((value),32,0))
#define EU_IRQ_MASK_AND_IMA_GETS(value)                    (ARCHI_BEXTRACT((value),32,0))
#define EU_IRQ_MASK_AND_IMA_SET(value,field)               (ARCHI_BINSERT((value),(field),32,0))
#define EU_IRQ_MASK_AND_IMA(val)                           ((val) << 0)

#define EU_IRQ_MASK_OR_IMO_GET(value)                      (ARCHI_BEXTRACTU((value),32,0))
#define EU_IRQ_MASK_OR_IMO_GETS(value)                     (ARCHI_BEXTRACT((value),32,0))
#define EU_IRQ_MASK_OR_IMO_SET(value,field)                (ARCHI_BINSERT((value),(field),32,0))
#define EU_IRQ_MASK_OR_IMO(val)                            ((val) << 0)

#define EU_CLOCK_STATUS_CS_GET(value)                      (ARCHI_BEXTRACTU((value),1,0))
#define EU_CLOCK_STATUS_CS_GETS(value)                     (ARCHI_BEXTRACT((value),1,0))
#define EU_CLOCK_STATUS_CS_SET(value,field)                (ARCHI_BINSERT((value),(field),1,0))
#define EU_CLOCK_STATUS_CS(val)                            ((val) << 0)

#define EU_EVENT_BUFFER_EB_GET(value)                      (ARCHI_BEXTRACTU((value),32,0))
#define EU_EVENT_BUFFER_EB_GETS(value)                     (ARCHI_BEXTRACT((value),32,0))
#define EU_EVENT_BUFFER_EB_SET(value,field)                (ARCHI_BINSERT((value),(field),32,0))
#define EU_EVENT_BUFFER_EB(val)                            ((val) << 0)

#define EU_EVENT_BUFFER_MASKED_EBM_GET(value)              (ARCHI_BEXTRACTU((value),32,0))
#define EU_EVENT_BUFFER_MASKED_EBM_GETS(value)             (ARCHI_BEXTRACT((value),32,0))
#define EU_EVENT_BUFFER_MASKED_EBM_SET(value,field)        (ARCHI_BINSERT((value),(field),32,0))
#define EU_EVENT_BUFFER_MASKED_EBM(val)                    ((val) << 0)

#define EU_EVENT_BUFFER_IRQ_MASKED_IBM_GET(value)          (ARCHI_BEXTRACTU((value),32,0))
#define EU_EVENT_BUFFER_IRQ_MASKED_IBM_GETS(value)         (ARCHI_BEXTRACT((value),32,0))
#define EU_EVENT_BUFFER_IRQ_MASKED_IBM_SET(value,field)    (ARCHI_BINSERT((value),(field),32,0))
#define EU_EVENT_BUFFER_IRQ_MASKED_IBM(val)                ((val) << 0)

#define EU_EVENT_BUFFER_CLEAR_EBC_GET(value)               (ARCHI_BEXTRACTU((value),32,0))
#define EU_EVENT_BUFFER_CLEAR_EBC_GETS(value)              (ARCHI_BEXTRACT((value),32,0))
#define EU_EVENT_BUFFER_CLEAR_EBC_SET(value,field)         (ARCHI_BINSERT((value),(field),32,0))
#define EU_EVENT_BUFFER_CLEAR_EBC(val)                     ((val) << 0)

#define EU_SW_EVENT_MASK_SWEM_GET(value)                   (ARCHI_BEXTRACTU((value),8,0))
#define EU_SW_EVENT_MASK_SWEM_GETS(value)                  (ARCHI_BEXTRACT((value),8,0))
#define EU_SW_EVENT_MASK_SWEM_SET(value,field)             (ARCHI_BINSERT((value),(field),8,0))
#define EU_SW_EVENT_MASK_SWEM(val)                         ((val) << 0)

#define EU_SW_EVENT_MASK_AND_SWEMA_GET(value)              (ARCHI_BEXTRACTU((value),8,0))
#define EU_SW_EVENT_MASK_AND_SWEMA_GETS(value)             (ARCHI_BEXTRACT((value),8,0))
#define EU_SW_EVENT_MASK_AND_SWEMA_SET(value,field)        (ARCHI_BINSERT((value),(field),8,0))
#define EU_SW_EVENT_MASK_AND_SWEMA(val)                    ((val) << 0)

#define EU_SW_EVENT_MASK_OR_SWEMO_GET(value)               (ARCHI_BEXTRACTU((value),8,0))
#define EU_SW_EVENT_MASK_OR_SWEMO_GETS(value)              (ARCHI_BEXTRACT((value),8,0))
#define EU_SW_EVENT_MASK_OR_SWEMO_SET(value,field)         (ARCHI_BINSERT((value),(field),8,0))
#define EU_SW_EVENT_MASK_OR_SWEMO(val)                     ((val) << 0)

#define EU_EVENT_WAIT_EBM_GET(value)                       (ARCHI_BEXTRACTU((value),32,0))
#define EU_EVENT_WAIT_EBM_GETS(value)                      (ARCHI_BEXTRACT((value),32,0))
#define EU_EVENT_WAIT_EBM_SET(value,field)                 (ARCHI_BINSERT((value),(field),32,0))
#define EU_EVENT_WAIT_EBM(val)                             ((val) << 0)

#define EU_EVENT_WAIT_CLEAR_EBM_GET(value)                 (ARCHI_BEXTRACTU((value),32,0))
#define EU_EVENT_WAIT_CLEAR_EBM_GETS(value)                (ARCHI_BEXTRACT((value),32,0))
#define EU_EVENT_WAIT_CLEAR_EBM_SET(value,field)           (ARCHI_BINSERT((value),(field),32,0))
#define EU_EVENT_WAIT_CLEAR_EBM(val)                       ((val) << 0)

#define EU_HW_DISPATCH_PUSH_TASK_MSG_GET(value)            (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_DISPATCH_PUSH_TASK_MSG_GETS(value)           (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_DISPATCH_PUSH_TASK_MSG_SET(value,field)      (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_DISPATCH_PUSH_TASK_MSG(val)                  ((val) << 0)

#define EU_HW_DISPATCH_POP_TASK_MSG_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_DISPATCH_POP_TASK_MSG_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_DISPATCH_POP_TASK_MSG_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_DISPATCH_POP_TASK_MSG(val)                   ((val) << 0)

#define EU_HW_DISPATCH_PUSH_TEAM_CONFIG_CT_GET(value)      (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_DISPATCH_PUSH_TEAM_CONFIG_CT_GETS(value)     (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_DISPATCH_PUSH_TEAM_CONFIG_CT_SET(value,field) (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_DISPATCH_PUSH_TEAM_CONFIG_CT(val)            ((val) << 0)

#define EU_HW_MUTEX_0_MSG_PUT_MSG_GET(value)               (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_MUTEX_0_MSG_PUT_MSG_GETS(value)              (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_MUTEX_0_MSG_PUT_MSG_SET(value,field)         (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_MUTEX_0_MSG_PUT_MSG(val)                     ((val) << 0)

#define EU_HW_MUTEX_0_MSG_GET_MSG_GET(value)               (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_MUTEX_0_MSG_GET_MSG_GETS(value)              (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_MUTEX_0_MSG_GET_MSG_SET(value,field)         (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_MUTEX_0_MSG_GET_MSG(val)                     ((val) << 0)

#define EU_HW_MUTEX_1_MSG_PUT_MSG_GET(value)               (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_MUTEX_1_MSG_PUT_MSG_GETS(value)              (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_MUTEX_1_MSG_PUT_MSG_SET(value,field)         (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_MUTEX_1_MSG_PUT_MSG(val)                     ((val) << 0)

#define EU_HW_MUTEX_1_MSG_GET_MSG_GET(value)               (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_MUTEX_1_MSG_GET_MSG_GETS(value)              (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_MUTEX_1_MSG_GET_MSG_SET(value,field)         (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_MUTEX_1_MSG_GET_MSG(val)                     ((val) << 0)

#define EU_SW_EVENT_0_TRIG_SW0T_GET(value)                 (ARCHI_BEXTRACTU((value),8,0))
#define EU_SW_EVENT_0_TRIG_SW0T_GETS(value)                (ARCHI_BEXTRACT((value),8,0))
#define EU_SW_EVENT_0_TRIG_SW0T_SET(value,field)           (ARCHI_BINSERT((value),(field),8,0))
#define EU_SW_EVENT_0_TRIG_SW0T(val)                       ((val) << 0)

#define EU_SW_EVENT_1_TRIG_SW1T_GET(value)                 (ARCHI_BEXTRACTU((value),8,0))
#define EU_SW_EVENT_1_TRIG_SW1T_GETS(value)                (ARCHI_BEXTRACT((value),8,0))
#define EU_SW_EVENT_1_TRIG_SW1T_SET(value,field)           (ARCHI_BINSERT((value),(field),8,0))
#define EU_SW_EVENT_1_TRIG_SW1T(val)                       ((val) << 0)

#define EU_SW_EVENT_2_TRIG_SW2T_GET(value)                 (ARCHI_BEXTRACTU((value),8,0))
#define EU_SW_EVENT_2_TRIG_SW2T_GETS(value)                (ARCHI_BEXTRACT((value),8,0))
#define EU_SW_EVENT_2_TRIG_SW2T_SET(value,field)           (ARCHI_BINSERT((value),(field),8,0))
#define EU_SW_EVENT_2_TRIG_SW2T(val)                       ((val) << 0)

#define EU_SW_EVENT_3_TRIG_SW3T_GET(value)                 (ARCHI_BEXTRACTU((value),8,0))
#define EU_SW_EVENT_3_TRIG_SW3T_GETS(value)                (ARCHI_BEXTRACT((value),8,0))
#define EU_SW_EVENT_3_TRIG_SW3T_SET(value,field)           (ARCHI_BINSERT((value),(field),8,0))
#define EU_SW_EVENT_3_TRIG_SW3T(val)                       ((val) << 0)

#define EU_SW_EVENT_4_TRIG_SW4T_GET(value)                 (ARCHI_BEXTRACTU((value),8,0))
#define EU_SW_EVENT_4_TRIG_SW4T_GETS(value)                (ARCHI_BEXTRACT((value),8,0))
#define EU_SW_EVENT_4_TRIG_SW4T_SET(value,field)           (ARCHI_BINSERT((value),(field),8,0))
#define EU_SW_EVENT_4_TRIG_SW4T(val)                       ((val) << 0)

#define EU_SW_EVENT_5_TRIG_SW5T_GET(value)                 (ARCHI_BEXTRACTU((value),8,0))
#define EU_SW_EVENT_5_TRIG_SW5T_GETS(value)                (ARCHI_BEXTRACT((value),8,0))
#define EU_SW_EVENT_5_TRIG_SW5T_SET(value,field)           (ARCHI_BINSERT((value),(field),8,0))
#define EU_SW_EVENT_5_TRIG_SW5T(val)                       ((val) << 0)

#define EU_SW_EVENT_6_TRIG_SW6T_GET(value)                 (ARCHI_BEXTRACTU((value),8,0))
#define EU_SW_EVENT_6_TRIG_SW6T_GETS(value)                (ARCHI_BEXTRACT((value),8,0))
#define EU_SW_EVENT_6_TRIG_SW6T_SET(value,field)           (ARCHI_BINSERT((value),(field),8,0))
#define EU_SW_EVENT_6_TRIG_SW6T(val)                       ((val) << 0)

#define EU_SW_EVENT_7_TRIG_SW7T_GET(value)                 (ARCHI_BEXTRACTU((value),8,0))
#define EU_SW_EVENT_7_TRIG_SW7T_GETS(value)                (ARCHI_BEXTRACT((value),8,0))
#define EU_SW_EVENT_7_TRIG_SW7T_SET(value,field)           (ARCHI_BINSERT((value),(field),8,0))
#define EU_SW_EVENT_7_TRIG_SW7T(val)                       ((val) << 0)

#define EU_SW_EVENT_0_TRIG_WAIT_EBM_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_0_TRIG_WAIT_EBM_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_0_TRIG_WAIT_EBM_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_0_TRIG_WAIT_EBM(val)                   ((val) << 0)

#define EU_SW_EVENT_1_TRIG_WAIT_EBM_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_1_TRIG_WAIT_EBM_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_1_TRIG_WAIT_EBM_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_1_TRIG_WAIT_EBM(val)                   ((val) << 0)

#define EU_SW_EVENT_2_TRIG_WAIT_EBM_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_2_TRIG_WAIT_EBM_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_2_TRIG_WAIT_EBM_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_2_TRIG_WAIT_EBM(val)                   ((val) << 0)

#define EU_SW_EVENT_3_TRIG_WAIT_EBM_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_3_TRIG_WAIT_EBM_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_3_TRIG_WAIT_EBM_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_3_TRIG_WAIT_EBM(val)                   ((val) << 0)

#define EU_SW_EVENT_4_TRIG_WAIT_EBM_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_4_TRIG_WAIT_EBM_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_4_TRIG_WAIT_EBM_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_4_TRIG_WAIT_EBM(val)                   ((val) << 0)

#define EU_SW_EVENT_5_TRIG_WAIT_EBM_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_5_TRIG_WAIT_EBM_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_5_TRIG_WAIT_EBM_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_5_TRIG_WAIT_EBM(val)                   ((val) << 0)

#define EU_SW_EVENT_6_TRIG_WAIT_EBM_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_6_TRIG_WAIT_EBM_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_6_TRIG_WAIT_EBM_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_6_TRIG_WAIT_EBM(val)                   ((val) << 0)

#define EU_SW_EVENT_7_TRIG_WAIT_EBM_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_7_TRIG_WAIT_EBM_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_7_TRIG_WAIT_EBM_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_7_TRIG_WAIT_EBM(val)                   ((val) << 0)

#define EU_SW_EVENT_0_TRIG_WAIT_CLEAR_EBM_GET(value)       (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_0_TRIG_WAIT_CLEAR_EBM_GETS(value)      (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_0_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_0_TRIG_WAIT_CLEAR_EBM(val)             ((val) << 0)

#define EU_SW_EVENT_1_TRIG_WAIT_CLEAR_EBM_GET(value)       (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_1_TRIG_WAIT_CLEAR_EBM_GETS(value)      (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_1_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_1_TRIG_WAIT_CLEAR_EBM(val)             ((val) << 0)

#define EU_SW_EVENT_2_TRIG_WAIT_CLEAR_EBM_GET(value)       (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_2_TRIG_WAIT_CLEAR_EBM_GETS(value)      (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_2_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_2_TRIG_WAIT_CLEAR_EBM(val)             ((val) << 0)

#define EU_SW_EVENT_3_TRIG_WAIT_CLEAR_EBM_GET(value)       (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_3_TRIG_WAIT_CLEAR_EBM_GETS(value)      (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_3_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_3_TRIG_WAIT_CLEAR_EBM(val)             ((val) << 0)

#define EU_SW_EVENT_4_TRIG_WAIT_CLEAR_EBM_GET(value)       (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_4_TRIG_WAIT_CLEAR_EBM_GETS(value)      (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_4_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_4_TRIG_WAIT_CLEAR_EBM(val)             ((val) << 0)

#define EU_SW_EVENT_5_TRIG_WAIT_CLEAR_EBM_GET(value)       (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_5_TRIG_WAIT_CLEAR_EBM_GETS(value)      (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_5_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_5_TRIG_WAIT_CLEAR_EBM(val)             ((val) << 0)

#define EU_SW_EVENT_6_TRIG_WAIT_CLEAR_EBM_GET(value)       (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_6_TRIG_WAIT_CLEAR_EBM_GETS(value)      (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_6_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_6_TRIG_WAIT_CLEAR_EBM(val)             ((val) << 0)

#define EU_SW_EVENT_7_TRIG_WAIT_CLEAR_EBM_GET(value)       (ARCHI_BEXTRACTU((value),32,0))
#define EU_SW_EVENT_7_TRIG_WAIT_CLEAR_EBM_GETS(value)      (ARCHI_BEXTRACT((value),32,0))
#define EU_SW_EVENT_7_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_SW_EVENT_7_TRIG_WAIT_CLEAR_EBM(val)             ((val) << 0)

#define EU_SOC_PERIPH_EVENT_ID_ID_GET(value)               (ARCHI_BEXTRACTU((value),8,0))
#define EU_SOC_PERIPH_EVENT_ID_ID_GETS(value)              (ARCHI_BEXTRACT((value),8,0))
#define EU_SOC_PERIPH_EVENT_ID_ID_SET(value,field)         (ARCHI_BINSERT((value),(field),8,0))
#define EU_SOC_PERIPH_EVENT_ID_ID(val)                     ((val) << 0)

#define EU_SOC_PERIPH_EVENT_ID_VALID_GET(value)            (ARCHI_BEXTRACTU((value),1,31))
#define EU_SOC_PERIPH_EVENT_ID_VALID_GETS(value)           (ARCHI_BEXTRACT((value),1,31))
#define EU_SOC_PERIPH_EVENT_ID_VALID_SET(value,field)      (ARCHI_BINSERT((value),(field),1,31))
#define EU_SOC_PERIPH_EVENT_ID_VALID(val)                  ((val) << 31)

#define EU_HW_BARRIER_0_TRIG_MASK_HB0TM_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_0_TRIG_MASK_HB0TM_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_0_TRIG_MASK_HB0TM_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_0_TRIG_MASK_HB0TM(val)               ((val) << 0)

#define EU_HW_BARRIER_1_TRIG_MASK_HB1TM_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_1_TRIG_MASK_HB1TM_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_1_TRIG_MASK_HB1TM_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_1_TRIG_MASK_HB1TM(val)               ((val) << 0)

#define EU_HW_BARRIER_2_TRIG_MASK_HB2TM_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_2_TRIG_MASK_HB2TM_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_2_TRIG_MASK_HB2TM_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_2_TRIG_MASK_HB2TM(val)               ((val) << 0)

#define EU_HW_BARRIER_3_TRIG_MASK_HB3TM_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_3_TRIG_MASK_HB3TM_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_3_TRIG_MASK_HB3TM_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_3_TRIG_MASK_HB3TM(val)               ((val) << 0)

#define EU_HW_BARRIER_4_TRIG_MASK_HB4TM_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_4_TRIG_MASK_HB4TM_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_4_TRIG_MASK_HB4TM_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_4_TRIG_MASK_HB4TM(val)               ((val) << 0)

#define EU_HW_BARRIER_5_TRIG_MASK_HB5TM_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_5_TRIG_MASK_HB5TM_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_5_TRIG_MASK_HB5TM_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_5_TRIG_MASK_HB5TM(val)               ((val) << 0)

#define EU_HW_BARRIER_6_TRIG_MASK_HB6TM_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_6_TRIG_MASK_HB6TM_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_6_TRIG_MASK_HB6TM_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_6_TRIG_MASK_HB6TM(val)               ((val) << 0)

#define EU_HW_BARRIER_7_TRIG_MASK_HB7TM_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_7_TRIG_MASK_HB7TM_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_7_TRIG_MASK_HB7TM_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_7_TRIG_MASK_HB7TM(val)               ((val) << 0)

#define EU_HW_BARRIER_0_STATUS_HBS_GET(value)              (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_0_STATUS_HBS_GETS(value)             (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_0_STATUS_HBS_SET(value,field)        (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_0_STATUS_HBS(val)                    ((val) << 0)

#define EU_HW_BARRIER_1_STATUS_HBS_GET(value)              (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_1_STATUS_HBS_GETS(value)             (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_1_STATUS_HBS_SET(value,field)        (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_1_STATUS_HBS(val)                    ((val) << 0)

#define EU_HW_BARRIER_2_STATUS_HBS_GET(value)              (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_2_STATUS_HBS_GETS(value)             (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_2_STATUS_HBS_SET(value,field)        (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_2_STATUS_HBS(val)                    ((val) << 0)

#define EU_HW_BARRIER_3_STATUS_HBS_GET(value)              (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_3_STATUS_HBS_GETS(value)             (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_3_STATUS_HBS_SET(value,field)        (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_3_STATUS_HBS(val)                    ((val) << 0)

#define EU_HW_BARRIER_4_STATUS_HBS_GET(value)              (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_4_STATUS_HBS_GETS(value)             (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_4_STATUS_HBS_SET(value,field)        (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_4_STATUS_HBS(val)                    ((val) << 0)

#define EU_HW_BARRIER_5_STATUS_HBS_GET(value)              (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_5_STATUS_HBS_GETS(value)             (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_5_STATUS_HBS_SET(value,field)        (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_5_STATUS_HBS(val)                    ((val) << 0)

#define EU_HW_BARRIER_6_STATUS_HBS_GET(value)              (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_6_STATUS_HBS_GETS(value)             (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_6_STATUS_HBS_SET(value,field)        (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_6_STATUS_HBS(val)                    ((val) << 0)

#define EU_HW_BARRIER_7_STATUS_HBS_GET(value)              (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_7_STATUS_HBS_GETS(value)             (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_7_STATUS_HBS_SET(value,field)        (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_7_STATUS_HBS(val)                    ((val) << 0)

#define EU_HW_BARRIER_0_STATUS_SUM_HBSS_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_0_STATUS_SUM_HBSS_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_0_STATUS_SUM_HBSS_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_0_STATUS_SUM_HBSS(val)               ((val) << 0)

#define EU_HW_BARRIER_1_STATUS_SUM_HBSS_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_1_STATUS_SUM_HBSS_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_1_STATUS_SUM_HBSS_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_1_STATUS_SUM_HBSS(val)               ((val) << 0)

#define EU_HW_BARRIER_2_STATUS_SUM_HBSS_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_2_STATUS_SUM_HBSS_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_2_STATUS_SUM_HBSS_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_2_STATUS_SUM_HBSS(val)               ((val) << 0)

#define EU_HW_BARRIER_3_STATUS_SUM_HBSS_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_3_STATUS_SUM_HBSS_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_3_STATUS_SUM_HBSS_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_3_STATUS_SUM_HBSS(val)               ((val) << 0)

#define EU_HW_BARRIER_4_STATUS_SUM_HBSS_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_4_STATUS_SUM_HBSS_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_4_STATUS_SUM_HBSS_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_4_STATUS_SUM_HBSS(val)               ((val) << 0)

#define EU_HW_BARRIER_5_STATUS_SUM_HBSS_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_5_STATUS_SUM_HBSS_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_5_STATUS_SUM_HBSS_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_5_STATUS_SUM_HBSS(val)               ((val) << 0)

#define EU_HW_BARRIER_6_STATUS_SUM_HBSS_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_6_STATUS_SUM_HBSS_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_6_STATUS_SUM_HBSS_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_6_STATUS_SUM_HBSS(val)               ((val) << 0)

#define EU_HW_BARRIER_7_STATUS_SUM_HBSS_GET(value)         (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_7_STATUS_SUM_HBSS_GETS(value)        (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_7_STATUS_SUM_HBSS_SET(value,field)   (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_7_STATUS_SUM_HBSS(val)               ((val) << 0)

#define EU_HW_BARRIER_0_TARGET_MASK_HBTAM_GET(value)       (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_0_TARGET_MASK_HBTAM_GETS(value)      (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_0_TARGET_MASK_HBTAM_SET(value,field) (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_0_TARGET_MASK_HBTAM(val)             ((val) << 0)

#define EU_HW_BARRIER_1_TARGET_MASK_HBTAM_GET(value)       (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_1_TARGET_MASK_HBTAM_GETS(value)      (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_1_TARGET_MASK_HBTAM_SET(value,field) (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_1_TARGET_MASK_HBTAM(val)             ((val) << 0)

#define EU_HW_BARRIER_2_TARGET_MASK_HBTAM_GET(value)       (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_2_TARGET_MASK_HBTAM_GETS(value)      (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_2_TARGET_MASK_HBTAM_SET(value,field) (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_2_TARGET_MASK_HBTAM(val)             ((val) << 0)

#define EU_HW_BARRIER_3_TARGET_MASK_HBTAM_GET(value)       (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_3_TARGET_MASK_HBTAM_GETS(value)      (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_3_TARGET_MASK_HBTAM_SET(value,field) (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_3_TARGET_MASK_HBTAM(val)             ((val) << 0)

#define EU_HW_BARRIER_4_TARGET_MASK_HBTAM_GET(value)       (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_4_TARGET_MASK_HBTAM_GETS(value)      (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_4_TARGET_MASK_HBTAM_SET(value,field) (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_4_TARGET_MASK_HBTAM(val)             ((val) << 0)

#define EU_HW_BARRIER_5_TARGET_MASK_HBTAM_GET(value)       (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_5_TARGET_MASK_HBTAM_GETS(value)      (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_5_TARGET_MASK_HBTAM_SET(value,field) (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_5_TARGET_MASK_HBTAM(val)             ((val) << 0)

#define EU_HW_BARRIER_6_TARGET_MASK_HBTAM_GET(value)       (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_6_TARGET_MASK_HBTAM_GETS(value)      (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_6_TARGET_MASK_HBTAM_SET(value,field) (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_6_TARGET_MASK_HBTAM(val)             ((val) << 0)

#define EU_HW_BARRIER_7_TARGET_MASK_HBTAM_GET(value)       (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_7_TARGET_MASK_HBTAM_GETS(value)      (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_7_TARGET_MASK_HBTAM_SET(value,field) (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_7_TARGET_MASK_HBTAM(val)             ((val) << 0)

#define EU_HW_BARRIER_0_TRIG_T_GET(value)                  (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_0_TRIG_T_GETS(value)                 (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_0_TRIG_T_SET(value,field)            (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_0_TRIG_T(val)                        ((val) << 0)

#define EU_HW_BARRIER_1_TRIG_T_GET(value)                  (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_1_TRIG_T_GETS(value)                 (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_1_TRIG_T_SET(value,field)            (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_1_TRIG_T(val)                        ((val) << 0)

#define EU_HW_BARRIER_2_TRIG_T_GET(value)                  (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_2_TRIG_T_GETS(value)                 (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_2_TRIG_T_SET(value,field)            (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_2_TRIG_T(val)                        ((val) << 0)

#define EU_HW_BARRIER_3_TRIG_T_GET(value)                  (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_3_TRIG_T_GETS(value)                 (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_3_TRIG_T_SET(value,field)            (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_3_TRIG_T(val)                        ((val) << 0)

#define EU_HW_BARRIER_4_TRIG_T_GET(value)                  (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_4_TRIG_T_GETS(value)                 (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_4_TRIG_T_SET(value,field)            (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_4_TRIG_T(val)                        ((val) << 0)

#define EU_HW_BARRIER_5_TRIG_T_GET(value)                  (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_5_TRIG_T_GETS(value)                 (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_5_TRIG_T_SET(value,field)            (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_5_TRIG_T(val)                        ((val) << 0)

#define EU_HW_BARRIER_6_TRIG_T_GET(value)                  (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_6_TRIG_T_GETS(value)                 (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_6_TRIG_T_SET(value,field)            (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_6_TRIG_T(val)                        ((val) << 0)

#define EU_HW_BARRIER_7_TRIG_T_GET(value)                  (ARCHI_BEXTRACTU((value),8,0))
#define EU_HW_BARRIER_7_TRIG_T_GETS(value)                 (ARCHI_BEXTRACT((value),8,0))
#define EU_HW_BARRIER_7_TRIG_T_SET(value,field)            (ARCHI_BINSERT((value),(field),8,0))
#define EU_HW_BARRIER_7_TRIG_T(val)                        ((val) << 0)

#define EU_HW_BARRIER_0_SELF_TRIG_T_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_0_SELF_TRIG_T_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_0_SELF_TRIG_T_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_0_SELF_TRIG_T(val)                   ((val) << 0)

#define EU_HW_BARRIER_1_SELF_TRIG_T_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_1_SELF_TRIG_T_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_1_SELF_TRIG_T_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_1_SELF_TRIG_T(val)                   ((val) << 0)

#define EU_HW_BARRIER_2_SELF_TRIG_T_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_2_SELF_TRIG_T_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_2_SELF_TRIG_T_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_2_SELF_TRIG_T(val)                   ((val) << 0)

#define EU_HW_BARRIER_3_SELF_TRIG_T_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_3_SELF_TRIG_T_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_3_SELF_TRIG_T_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_3_SELF_TRIG_T(val)                   ((val) << 0)

#define EU_HW_BARRIER_4_SELF_TRIG_T_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_4_SELF_TRIG_T_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_4_SELF_TRIG_T_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_4_SELF_TRIG_T(val)                   ((val) << 0)

#define EU_HW_BARRIER_5_SELF_TRIG_T_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_5_SELF_TRIG_T_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_5_SELF_TRIG_T_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_5_SELF_TRIG_T(val)                   ((val) << 0)

#define EU_HW_BARRIER_6_SELF_TRIG_T_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_6_SELF_TRIG_T_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_6_SELF_TRIG_T_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_6_SELF_TRIG_T(val)                   ((val) << 0)

#define EU_HW_BARRIER_7_SELF_TRIG_T_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_7_SELF_TRIG_T_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_7_SELF_TRIG_T_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_7_SELF_TRIG_T(val)                   ((val) << 0)

#define EU_HW_BARRIER_0_TRIG_WAIT_EBM_GET(value)           (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_0_TRIG_WAIT_EBM_GETS(value)          (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_0_TRIG_WAIT_EBM_SET(value,field)     (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_0_TRIG_WAIT_EBM(val)                 ((val) << 0)

#define EU_HW_BARRIER_1_TRIG_WAIT_EBM_GET(value)           (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_1_TRIG_WAIT_EBM_GETS(value)          (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_1_TRIG_WAIT_EBM_SET(value,field)     (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_1_TRIG_WAIT_EBM(val)                 ((val) << 0)

#define EU_HW_BARRIER_2_TRIG_WAIT_EBM_GET(value)           (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_2_TRIG_WAIT_EBM_GETS(value)          (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_2_TRIG_WAIT_EBM_SET(value,field)     (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_2_TRIG_WAIT_EBM(val)                 ((val) << 0)

#define EU_HW_BARRIER_3_TRIG_WAIT_EBM_GET(value)           (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_3_TRIG_WAIT_EBM_GETS(value)          (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_3_TRIG_WAIT_EBM_SET(value,field)     (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_3_TRIG_WAIT_EBM(val)                 ((val) << 0)

#define EU_HW_BARRIER_4_TRIG_WAIT_EBM_GET(value)           (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_4_TRIG_WAIT_EBM_GETS(value)          (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_4_TRIG_WAIT_EBM_SET(value,field)     (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_4_TRIG_WAIT_EBM(val)                 ((val) << 0)

#define EU_HW_BARRIER_5_TRIG_WAIT_EBM_GET(value)           (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_5_TRIG_WAIT_EBM_GETS(value)          (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_5_TRIG_WAIT_EBM_SET(value,field)     (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_5_TRIG_WAIT_EBM(val)                 ((val) << 0)

#define EU_HW_BARRIER_6_TRIG_WAIT_EBM_GET(value)           (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_6_TRIG_WAIT_EBM_GETS(value)          (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_6_TRIG_WAIT_EBM_SET(value,field)     (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_6_TRIG_WAIT_EBM(val)                 ((val) << 0)

#define EU_HW_BARRIER_7_TRIG_WAIT_EBM_GET(value)           (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_7_TRIG_WAIT_EBM_GETS(value)          (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_7_TRIG_WAIT_EBM_SET(value,field)     (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_7_TRIG_WAIT_EBM(val)                 ((val) << 0)

#define EU_HW_BARRIER_0_TRIG_WAIT_CLEAR_EBM_GET(value)     (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_0_TRIG_WAIT_CLEAR_EBM_GETS(value)    (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_0_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_0_TRIG_WAIT_CLEAR_EBM(val)           ((val) << 0)

#define EU_HW_BARRIER_1_TRIG_WAIT_CLEAR_EBM_GET(value)     (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_1_TRIG_WAIT_CLEAR_EBM_GETS(value)    (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_1_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_1_TRIG_WAIT_CLEAR_EBM(val)           ((val) << 0)

#define EU_HW_BARRIER_2_TRIG_WAIT_CLEAR_EBM_GET(value)     (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_2_TRIG_WAIT_CLEAR_EBM_GETS(value)    (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_2_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_2_TRIG_WAIT_CLEAR_EBM(val)           ((val) << 0)

#define EU_HW_BARRIER_3_TRIG_WAIT_CLEAR_EBM_GET(value)     (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_3_TRIG_WAIT_CLEAR_EBM_GETS(value)    (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_3_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_3_TRIG_WAIT_CLEAR_EBM(val)           ((val) << 0)

#define EU_HW_BARRIER_4_TRIG_WAIT_CLEAR_EBM_GET(value)     (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_4_TRIG_WAIT_CLEAR_EBM_GETS(value)    (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_4_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_4_TRIG_WAIT_CLEAR_EBM(val)           ((val) << 0)

#define EU_HW_BARRIER_5_TRIG_WAIT_CLEAR_EBM_GET(value)     (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_5_TRIG_WAIT_CLEAR_EBM_GETS(value)    (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_5_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_5_TRIG_WAIT_CLEAR_EBM(val)           ((val) << 0)

#define EU_HW_BARRIER_6_TRIG_WAIT_CLEAR_EBM_GET(value)     (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_6_TRIG_WAIT_CLEAR_EBM_GETS(value)    (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_6_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_6_TRIG_WAIT_CLEAR_EBM(val)           ((val) << 0)

#define EU_HW_BARRIER_7_TRIG_WAIT_CLEAR_EBM_GET(value)     (ARCHI_BEXTRACTU((value),32,0))
#define EU_HW_BARRIER_7_TRIG_WAIT_CLEAR_EBM_GETS(value)    (ARCHI_BEXTRACT((value),32,0))
#define EU_HW_BARRIER_7_TRIG_WAIT_CLEAR_EBM_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define EU_HW_BARRIER_7_TRIG_WAIT_CLEAR_EBM(val)           ((val) << 0)

#endif

#endif
