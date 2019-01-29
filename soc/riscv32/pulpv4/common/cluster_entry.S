/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#include <toolchain.h>
#include <archi/pulp.h>
#include <archi/pulp.h>
#include <archi/eu/eu_v3.h>
#include "soc.h"

/* exports */
GTEXT(__cluster_pe_entry)

__cluster_pe_entry:

    // Prepare few values that will be kept in saved registers to optimize the loop
    csrr    s1, 0xF14
    andi    s0, s1, 0x1f
    srli    s1, s1, 5

    li      s2, ARCHI_EU_DEMUX_ADDR

    bne     s0, x0, cluster_slave_loop



cluster_master_entry:

    // Prepare few values that will be kept in saved registers to optimize the loop
    li      s3, 1<<CLUSTER_CALL_EVT
    la      s4, cluster_entry_stub
    li      s6, ARCHI_FC_GLOBAL_ADDR + ARCHI_FC_PERIPHERALS_OFFSET + ARCHI_FC_EU_OFFSET + EU_SW_EVENTS_AREA_BASE + EU_CORE_TRIGG_SW_EVENT + (FC_TASK_END << 2)

cluster_master_loop:

    // Check if a task is ready, otherwise go to sleep.
    lw      s5, %tiny(cluster_first_task_cl)(x0)
    beq     s5, x0, cluster_master_sleep

    // Reads entry point information.
    lw      t0, CLUSTER_TASK_T_NEXT(s5)
    lw      t1, CLUSTER_TASK_T_MASTER_STACK_SIZE(s5)
    lw      sp, CLUSTER_TASK_T_STACKS(s5)
    mv      a0, s5
    add     sp, sp, t1

    // Update the task list. As the head is not null, cluster part is
    // owning it and is allowed to modify it.
    sw      t0, %tiny(cluster_first_task_cl)(x0)

    // Call entry stub, which will take care of other task aspects.
    jalr    ra, s4

    // Now notify FC side that the task is over, it will terminates it
    // and possiblity update task list head if it is null.
    sw      x0, CLUSTER_TASK_T_PENDING(s5)
    sw      x0, 0(s6)

    j       cluster_master_loop

cluster_master_sleep:
    // Just wait for 
    sw      s3, EU_CORE_MASK_OR(s2)
    p.elw   x0, EU_CORE_EVENT_WAIT_CLEAR(s2)
    sw      s3, EU_CORE_MASK_AND(s2)
    j       cluster_master_loop



cluster_slave_loop:

    j       cluster_slave_wait_for_dispatch



cluster_slave_wait_for_dispatch:

    // Wait for PC + arg information from dispatcher
    p.elw   t0, EU_DISPATCH_DEMUX_OFFSET + EU_DISPATCH_FIFO_ACCESS(s2)
    p.elw   a0, EU_DISPATCH_DEMUX_OFFSET + EU_DISPATCH_FIFO_ACCESS(s2)
