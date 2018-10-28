/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file Driver for the gap GPIO controller.
 */

#include <errno.h>
#include <kernel.h>
#include <device.h>
#include <soc.h>
#include <gpio.h>
#include <misc/util.h>

#include "gpio_utils.h"

/**
 * @brief Configure pin
 *
 * @param dev Device structure
 * @param access_op Access operation
 * @param pin The pin number
 * @param flags Flags of pin or port
 *
 * @return 0 if successful, failed otherwise
 */
static int gpio_pulpino_config(struct device *dev,
			       int access_op,
			       u32_t pin,
			       int flags)
{
	return 0;
}

/**
 * @brief Set the pin
 *
 * @param dev Device struct
 * @param access_op Access operation
 * @param pin The pin number
 * @param value Value to set (0 or 1)
 *
 * @return 0 if successful, failed otherwise
 */
static int gpio_pulpino_write(struct device *dev,
			      int access_op,
			      u32_t pin,
			      u32_t value)
{
	return 0;
}

/**
 * @brief Read the pin
 *
 * @param dev Device struct
 * @param access_op Access operation
 * @param pin The pin number
 * @param value Value of input pin(s)
 *
 * @return 0 if successful, failed otherwise
 */
static int gpio_pulpino_read(struct device *dev,
			     int access_op,
			     u32_t pin,
			     u32_t *value)
{
	return 0;
}

static int gpio_pulpino_manage_callback(struct device *dev,
					struct gpio_callback *callback,
					bool set)
{
	return 0;
}

static int gpio_pulpino_enable_callback(struct device *dev,
					int access_op,
					u32_t pin)
{
	return 0;
}

static int gpio_pulpino_disable_callback(struct device *dev,
					 int access_op,
					 u32_t pin)
{
	return 0;
}

static const struct gpio_driver_api gpio_pulpino_driver = {
	.config              = gpio_pulpino_config,
	.write               = gpio_pulpino_write,
	.read                = gpio_pulpino_read,
	.manage_callback     = gpio_pulpino_manage_callback,
	.enable_callback     = gpio_pulpino_enable_callback,
	.disable_callback    = gpio_pulpino_disable_callback,
};

/**
 * @brief Initialize a GPIO controller
 *
 * Perform basic initialization of a GPIO controller
 *
 * @param dev GPIO device struct
 *
 * @return 0
 */
static int gap(struct device *dev)
{
	return 0;
}

DEVICE_AND_API_INIT(gpio_pulpino_0, "gpio0", gap,
		    NULL, NULL,
		    POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEVICE,
		    &gpio_pulpino_driver);
