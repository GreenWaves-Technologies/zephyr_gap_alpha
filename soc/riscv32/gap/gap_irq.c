/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief gap interrupt management code
 */
#include <irq.h>
#include <soc.h>

void _arch_irq_enable(unsigned int irq)
{
};

void _arch_irq_disable(unsigned int irq)
{
};

int _arch_irq_is_enabled(unsigned int irq)
{
	return 0;
}

#if defined(CONFIG_RISCV_SOC_INTERRUPT_INIT)
void soc_interrupt_init(void)
{
}
#endif
