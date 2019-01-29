/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <toolchain.h>

/* exports */
GTEXT(__cluster_start)

/* imports */
GTEXT(__reset)
GTEXT(__irq_wrapper)


	.section .vectors, "ax"
	.option norvc;

	/* Call __irq_wrapper for all interrupts */
	.org 0x00
	.rept 32
	jal x0, __irq_wrapper
	.endr

	/* Call __reset for reset vector */
	.org 0x80
__cluster_start:
	jal x0, __cluster_pe_entry

	/* Illegal instruction */
	jal x0, __irq_wrapper

	/* ECALL (system call) */
	jal x0, __irq_wrapper

	/* Invalid memory access */
	jal x0, __irq_wrapper
