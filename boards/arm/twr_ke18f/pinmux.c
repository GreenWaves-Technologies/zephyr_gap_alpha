/*
 * Copyright (c) 2019 Vestas Wind Systems A/S
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>
#include <pinmux.h>
#include <fsl_port.h>

static int twr_ke18f_pinmux_init(struct device *dev)
{
	ARG_UNUSED(dev);

#ifdef CONFIG_PINMUX_MCUX_PORTA
	__unused struct device *porta =
		device_get_binding(CONFIG_PINMUX_MCUX_PORTA_NAME);
#endif
#ifdef CONFIG_PINMUX_MCUX_PORTB
	__unused struct device *portb =
		device_get_binding(CONFIG_PINMUX_MCUX_PORTB_NAME);
#endif
#ifdef CONFIG_PINMUX_MCUX_PORTC
	__unused struct device *portc =
		device_get_binding(CONFIG_PINMUX_MCUX_PORTC_NAME);
#endif
#ifdef CONFIG_PINMUX_MCUX_PORTD
	__unused struct device *portd =
		device_get_binding(CONFIG_PINMUX_MCUX_PORTD_NAME);
#endif

#ifdef CONFIG_PINMUX_MCUX_PORTE
	__unused struct device *porte =
		device_get_binding(CONFIG_PINMUX_MCUX_PORTE_NAME);
#endif

	/* LEDs */
	pinmux_pin_set(portb, 5, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portc, 10, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portc, 11, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portc, 12, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portc, 13, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portd, 15, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portd, 16, PORT_PCR_MUX(kPORT_MuxAsGpio));

	/* Buttons */
	pinmux_pin_set(portd, 3, PORT_PCR_MUX(kPORT_MuxAsGpio));
	pinmux_pin_set(portd, 6, PORT_PCR_MUX(kPORT_MuxAsGpio));

#ifdef CONFIG_UART_MCUX_LPUART_0
	/* UART0 RX, TX */
	pinmux_pin_set(portb, 0, PORT_PCR_MUX(kPORT_MuxAlt2));
	pinmux_pin_set(portb, 1, PORT_PCR_MUX(kPORT_MuxAlt2));
#endif

#ifdef CONFIG_SPI_0
	/* SPI0 SCK, SIN, SOUT */
	pinmux_pin_set(porte, 0, PORT_PCR_MUX(kPORT_MuxAlt2));
	pinmux_pin_set(porte, 1, PORT_PCR_MUX(kPORT_MuxAlt2));
	pinmux_pin_set(porte, 2, PORT_PCR_MUX(kPORT_MuxAlt2));
#endif
#ifdef CONFIG_BOARD_TWR_KE18F_SPI_0_PCS2
	/* SPI0 PCS2 */
	pinmux_pin_set(porte, 6, PORT_PCR_MUX(kPORT_MuxAlt2));
#else
	pinmux_pin_set(porte, 6, PORT_PCR_MUX(kPORT_MuxAsGpio));
#endif

#ifdef CONFIG_SPI_1
	/* SPI1 SCK, SIN, SOUT */
	pinmux_pin_set(portd, 0, PORT_PCR_MUX(kPORT_MuxAlt3));
	pinmux_pin_set(portd, 1, PORT_PCR_MUX(kPORT_MuxAlt3));
	pinmux_pin_set(portd, 2, PORT_PCR_MUX(kPORT_MuxAlt3));
#endif
#ifdef CONFIG_BOARD_TWR_KE18F_SPI_1_PCS0
	/* SPI1 PCS0 */
	pinmux_pin_set(portd, 3, PORT_PCR_MUX(kPORT_MuxAlt3));
#else
	pinmux_pin_set(portd, 3, PORT_PCR_MUX(kPORT_MuxAsGpio));
#endif
#ifdef CONFIG_BOARD_TWR_KE18F_SPI_1_PCS2
	/* SPI1 PCS2 */
	pinmux_pin_set(porta, 16, PORT_PCR_MUX(kPORT_MuxAlt3));
#else
	pinmux_pin_set(porta, 16, PORT_PCR_MUX(kPORT_MuxAsGpio));
#endif

#ifdef CONFIG_BOARD_TWR_KE18F_FLEXIO_CLKOUT
	/* CLKOUT */
	pinmux_pin_set(porte, 10, PORT_PCR_MUX(kPORT_MuxAlt2));
#endif

#if CONFIG_I2C_0
	/* LPI2C0 SCL, SDA - FXOS8700 */
	pinmux_pin_set(porta, 3, PORT_PCR_MUX(kPORT_MuxAlt3));
	pinmux_pin_set(porta, 2, PORT_PCR_MUX(kPORT_MuxAlt3));
#endif

#if CONFIG_I2C_1
	/* LPI2C1 SCL, SDA - Elevator connector */
	pinmux_pin_set(portd, 9, PORT_PCR_MUX(kPORT_MuxAlt2));
	pinmux_pin_set(portd, 8, PORT_PCR_MUX(kPORT_MuxAlt2));
#endif

	/* FXOS8700 INT1, INT2, RST */
#ifdef DT_NXP_FXOS8700_0_INT1_GPIOS_PIN
	pinmux_pin_set(porta, 14, PORT_PCR_MUX(kPORT_MuxAsGpio));
#endif
#ifdef DT_NXP_FXOS8700_0_INT2_GPIOS_PIN
	pinmux_pin_set(portc, 17, PORT_PCR_MUX(kPORT_MuxAsGpio));
#endif
	pinmux_pin_set(portc, 15, PORT_PCR_MUX(kPORT_MuxAsGpio));

#ifdef CONFIG_ADC_0
	/* Thermistor A, B */
	pinmux_pin_set(porta, 0, PORT_PCR_MUX(kPORT_PinDisabledOrAnalog));
	pinmux_pin_set(porta, 1, PORT_PCR_MUX(kPORT_PinDisabledOrAnalog));
	/* Potentiometer */
	pinmux_pin_set(portc, 14, PORT_PCR_MUX(kPORT_PinDisabledOrAnalog));
#endif

	return 0;
}

SYS_INIT(twr_ke18f_pinmux_init, PRE_KERNEL_1, CONFIG_PINMUX_INIT_PRIORITY);

