/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <arch/cpu.h>
#include <device.h>
#include <system_timer.h>
#include <board.h>

#ifdef CONFIG_TICKLESS_IDLE
#error "Tickless idle not yet implemented for gap timer"
#endif

int z_clock_driver_init(struct device *device)
{
	ARG_UNUSED(device);
	return 0;
}

/**
 *
 * @brief Read the platform's timer hardware
 *
 * This routine returns the current time in terms of timer hardware clock
 * cycles.
 *
 * @return up counter of elapsed clock cycles
 */
u32_t _timer_cycle_get_32(void)
{
	return 0;
}

u32_t z_clock_elapsed(void)
{
	return 0;
}
