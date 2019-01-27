/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel_structs.h>
#include <offsets.h>
#include <toolchain.h>
#include <linker/sections.h>
#include <soc.h>

/* exports */
GTEXT(__soc_save_context)
GTEXT(__soc_restore_context)
GTEXT(__soc_is_irq)
GTEXT(__soc_handle_irq)
GTEXT(__soc_irq_unlock)

/* Use ABI name of registers for the sake of simplicity */

SECTION_FUNC(exception.other, __soc_save_context)
	/* Save hardware loop registers to the soc_esf_t passed in a0. */
	csrr t0, PULP_LPSTART0
	csrr t1, PULP_LPEND0
	csrr t2, PULP_LPCOUNT0
	sw t0, __soc_esf_t_lpstart0_OFFSET(a0)
	sw t1, __soc_esf_t_lpend0_OFFSET(a0)
	sw t2, __soc_esf_t_lpcount0_OFFSET(a0)
	csrr t0, PULP_LPSTART1
	csrr t1, PULP_LPEND1
	csrr t2, PULP_LPCOUNT1
	sw t0, __soc_esf_t_lpstart1_OFFSET(a0)
	sw t1, __soc_esf_t_lpend1_OFFSET(a0)
	sw t2, __soc_esf_t_lpcount1_OFFSET(a0)

	/* Return */
	jalr x0, ra


SECTION_FUNC(exception.other, __soc_restore_context)
	/* Restore hardware loop registers from soc_esf_t in a0. */
	lw t0, __soc_esf_t_lpstart0_OFFSET(a0)
	lw t1, __soc_esf_t_lpend0_OFFSET(a0)
	lw t2, __soc_esf_t_lpcount0_OFFSET(a0)
	csrw PULP_LPSTART0, t0
	csrw PULP_LPEND0, t1
	csrw PULP_LPCOUNT0, t2
	lw t0, __soc_esf_t_lpstart1_OFFSET(a0)
	lw t1, __soc_esf_t_lpend1_OFFSET(a0)
	lw t2, __soc_esf_t_lpcount1_OFFSET(a0)
	csrw PULP_LPSTART1, t0
	csrw PULP_LPEND1, t1
	csrw PULP_LPCOUNT1, t2

	/* Return */
	jalr x0, ra


/*
 * SOC-specific function to handle pending IRQ number generating the interrupt.
 *
 */
SECTION_FUNC(exception.other, __soc_handle_irq)
	/* Return */
	jalr x0, ra


/*
 * SOC-specific function to determine if the exception is the result of a
 * an interrupt or an exception
 * return 1 (interrupt) or 0 (exception)
 */
SECTION_FUNC(exception.other, __soc_is_irq)
	/* Get exception number from the mcause CSR register. */
	csrr a0, mcause
	srli a0, a0, 31

	jalr x0, ra
