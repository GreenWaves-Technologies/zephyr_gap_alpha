/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */
/*
 * Copyright (c) 2016 Jean-Paul Etienne <fractalclone@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <arch/cpu.h>
#include <device.h>
#include <system_timer.h>
#include "hal/timer/timer_v2.h"

static u32_t accumulated_cycle_count;

static void gap_timer_irq_handler(void *unused)
{
	ARG_UNUSED(unused);

	accumulated_cycle_count += sys_clock_hw_cycles_per_tick();

	z_clock_announce(1);
}

#ifdef CONFIG_TICKLESS_IDLE
#error "Tickless idle not yet implemented for pulpino timer"
#endif

int z_clock_driver_init(struct device *device)
{
	ARG_UNUSED(device);

	IRQ_CONNECT(ARCHI_FC_EVT_TIMER0_HI, 0,
		    gap_timer_irq_handler, NULL, 0);
	irq_enable(ARCHI_FC_EVT_TIMER0_HI);

  timer_cmp_set(timer_base_fc(0, 1), sys_clock_hw_cycles_per_tick());

  timer_conf_set(timer_base_fc(0, 1),
    TIMER_CFG_LO_ENABLE(1) |
    TIMER_CFG_LO_RESET(1)  |
    TIMER_CFG_LO_IRQEN(1)  |
    TIMER_CFG_LO_MODE(1)
  );

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
	return accumulated_cycle_count + timer_count_get(timer_base_fc(0, 1));
}

u32_t z_clock_elapsed(void)
{
	return 0;
}
