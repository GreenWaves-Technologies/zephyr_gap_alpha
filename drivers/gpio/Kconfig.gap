# Kconfig.pulpino - pulpino GPIO configuration option
#
# Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
#
# SPDX-License-Identifier: Apache-2.0
#

menuconfig GPIO_GAP
	bool "GAP GPIO controller driver"
	depends on GPIO && SOC_RISCV32_GAP8
	select HAS_DTS_GPIO
	help
	  Enable driver for the GAP GPIO controller.

	  Says n if not sure.
