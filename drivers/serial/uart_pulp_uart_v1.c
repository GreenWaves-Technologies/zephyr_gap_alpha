/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <kernel.h>
#include <arch/cpu.h>
#include <zephyr/types.h>
#include <soc.h>

#include <init.h>
#include <toolchain.h>
#include <linker/sections.h>
#include <uart.h>
#include <sys_io.h>

#include "hal/pulp.h"
#include "soc.h"

struct uart_pulp_device_config {
};

struct uart_pulp_dev_data_t {
	u32_t itf;
	struct k_sem sync;
	struct k_mutex mutex;
};

static __attribute__((section(".l2_ram"))) int uart_pulp_console_poll_out;


#define DEV_CFG(dev) \
	((const struct uart_pulp_device_config * const) \
	 (dev)->config->config_info)
#define DEV_DATA(dev) \
	((struct uart_pulp_dev_data_t *)(dev)->driver_data)


static void uart_pulp_udma_tx_handler(struct device *dev)
{
	struct uart_pulp_dev_data_t * const dev_data = DEV_DATA(dev);

	k_sem_give(&dev_data->sync);
}

static int uart_pulp_init(struct device *dev)
{
	struct uart_pulp_dev_data_t * const dev_data = DEV_DATA(dev);

	int udma_periph = dev_data->itf + ARCHI_UDMA_UART_ID(0);

	// Deactivate UART channel clock-gating
	plp_udma_cg_set(plp_udma_cg_get() | (1<<udma_periph));

	// Activate UDMA events fro this periph to be notified by transfer
	// completion (both RX and TX).
	soc_eu_fcEventMask_setEvent(UDMA_EVENT_ID(udma_periph));
	soc_eu_fcEventMask_setEvent(UDMA_EVENT_ID(udma_periph)+1);

	pulp_soc_eu_register_udma_callback(UDMA_EVENT_ID(udma_periph)+1, uart_pulp_udma_tx_handler, dev);

  int div =  (50000000 + 625000/2) / 625000;

  // The counter in the UDMA will count from 0 to div included
  // and then will restart from 0, so we must give div - 1 as
  // divider
  plp_uart_setup(dev_data->itf, 0, div-1);

	return 0;
}

static int uart_pulp_poll_in(struct device *dev, unsigned char *c)
{
	return -1;
}

static unsigned char uart_pulp_poll_out(struct device *dev,
					   unsigned char c)
{
	struct uart_pulp_dev_data_t * const dev_data = DEV_DATA(dev);

	int udma_periph = dev_data->itf + ARCHI_UDMA_UART_ID(0);

	k_mutex_lock(&dev_data->mutex, K_FOREVER);

	uart_pulp_console_poll_out = c;

	plp_udma_enqueue(hal_udma_periph_base(udma_periph) + UDMA_CHANNEL_TX_OFFSET, (int)&uart_pulp_console_poll_out, 1, UDMA_CHANNEL_CFG_SIZE_8 | UDMA_CHANNEL_CFG_EN);

	k_sem_take(&dev_data->sync, K_FOREVER);

	k_mutex_unlock(&dev_data->mutex );

	return c;
}

static int uart_pulp_err_check(struct device *dev)
{
	return 0;
}


static const struct uart_driver_api uart_pulp_driver_api = {
	.poll_in = uart_pulp_poll_in,
	.poll_out = uart_pulp_poll_out,
	.err_check = uart_pulp_err_check
};

static const struct uart_pulp_device_config uart_pulp_dev_cfg = {
};

static struct uart_pulp_dev_data_t uart_pulp_dev_data = {
	.itf = 0,
	.sync = _K_SEM_INITIALIZER(uart_pulp_dev_data.sync, 0, 1),
	.mutex = _K_MUTEX_INITIALIZER(uart_pulp_dev_data.mutex)
};

DEVICE_AND_API_INIT(uart_pulp, CONFIG_UART_PULP_PORT_NAME, &uart_pulp_init,
		&uart_pulp_dev_data, &uart_pulp_dev_cfg,
		PRE_KERNEL_2, CONFIG_KERNEL_INIT_PRIORITY_DEVICE,
		&uart_pulp_driver_api);
