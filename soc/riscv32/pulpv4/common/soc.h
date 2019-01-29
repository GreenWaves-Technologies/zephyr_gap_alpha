/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file SoC configuration macros for the gap core
 */

#ifndef __GAP_SOC_H_
#define __GAP_SOC_H_

/* CSR Registers */
#define PULP_MESTATUS              0x7C0 /* Machine Exception Status Register */
#define PULP_LPSTART0              0x7B0 /* Hardware Loop 0 Start Register */
#define PULP_LPEND0                0x7B1 /* Hardware Loop 0 End Register */
#define PULP_LPCOUNT0              0x7B2 /* Hardware Loop 0 Count Register */
#define PULP_LPSTART1              0x7B4 /* Hardware Loop 1 Start Register */
#define PULP_LPEND1                0x7B5 /* Hardware Loop 1 End Register */
#define PULP_LPCOUNT1              0x7B6 /* Hardware Loop 1 Count Register */

/* IRQ numbers */
#define PULP_I2C_0_IRQ             23 /* I2C Controller */
#define PULP_SPI_0_IRQ             26 /* SPI Controller #0 */
#define PULP_SPI_1_IRQ             27 /* SPI Controller #1 */
#define PULP_TIMER_A_OVERFLOW_IRQ  28 /* Timer Overflow A */
#define PULP_TIMER_A_CMP_IRQ       29 /* Timer Output Cmp A */
#define PULP_TIMER_B_OVERFLOW_IRQ  30 /* Timer Overflow B */
#define PULP_TIMER_B_CMP_IRQ       31 /* Timer Output Cmp B */

/* min value to consider as IRQ in MCAUSE register */
#define PULP_MIN_IRQ               PULP_I2C_0_IRQ

/* Exception numbers */
#define PULP_ECALL_EXP             11 /* ECALL Instruction */

/*
 * SOC-specific MSTATUS related info
 */
/* MSTATUS register to save/restore upon interrupt/exception/context switch */
#define SOC_MSTATUS_REG            PULP_MESTATUS

#define SOC_MSTATUS_IEN            (1 << 3) /* Machine Interrupt Enable bit */

/*
 * Default MSTATUS register value to restore from stack
 * upon scheduling a thread for the first time
 */
#define SOC_MSTATUS_DEF_RESTORE    SOC_MSTATUS_IEN

/* SOC-specific MCAUSE bitfields */
#define SOC_MCAUSE_EXP_MASK        0x1F           /* Exception code Mask */
#define SOC_MCAUSE_ECALL_EXP       PULP_ECALL_EXP /* ECALL exception number */

/* SOC-Specific EXIT ISR command */
#define SOC_ERET                   mret

/* UART configuration */
#define CONFIG_UART_NS16550_PORT_0_IRQ_PRI       0
#define CONFIG_UART_NS16550_PORT_0_IRQ_FLAGS     0

/* PAD configuration */
#define PULP_PAD_BASE              0x1A107000

#define PULP_IER_ADDR  (PULP_IRQ_BASE + 0x00) /* IRQ Enable Register */
#define PULP_IPR_ADDR  (PULP_IRQ_BASE + 0x04) /* IRQ Pending Register */
#define PULP_ISP_ADDR  (PULP_IRQ_BASE + 0x08) /* IRQ Set Pending Register */
#define PULP_ICP_ADDR  (PULP_IRQ_BASE + 0x0C) /* IRQ Clear Pending Register */
#define PULP_EER_ADDR  (PULP_IRQ_BASE + 0x10) /* Event Enable Register */
#define PULP_EPR_ADDR  (PULP_IRQ_BASE + 0x14) /* Event Pending Register */
#define PULP_ESP_ADDR  (PULP_IRQ_BASE + 0x18) /* Event Set Pending Register */
#define PULP_ECP_ADDR  (PULP_IRQ_BASE + 0x1C) /* Event Clear Pending Register */
#define PULP_SCR_ADDR  (PULP_IRQ_BASE + 0x20) /* Sleep Control Register */

/* Timer configuration */
#define PULP_TIMER_A_BASE          0x1A103000
#define PULP_TIMER_B_BASE          0x1A103010

#define wfi                        wfi

#ifndef _ASMLANGUAGE
#include <irq.h>

/* Register Access MACRO */
#define PULP_REG(x)                (*((volatile unsigned int *)(x)))

/* Interrupt Registers */
#define PULP_IER                   PULP_REG(PULP_IER_ADDR)
#define PULP_IPR                   PULP_REG(PULP_IPR_ADDR)
#define PULP_ISP                   PULP_REG(PULP_ISP_ADDR)
#define PULP_ICP                   PULP_REG(PULP_ICP_ADDR)
#define PULP_EER                   PULP_REG(PULP_EER_ADDR)
#define PULP_EPR                   PULP_REG(PULP_EPR_ADDR)
#define PULP_ESP                   PULP_REG(PULP_ESP_ADDR)
#define PULP_ECP                   PULP_REG(PULP_ECP_ADDR)
#define PULP_SCR                   PULP_REG(PULP_SCR_ADDR)

/* PAD MUX register */
#define PULP_PADMUX                PULP_REG(PULP_PAD_BASE)

#define PULP_PAD_SPI               0
#define PULP_PAD_GPIO              1
#define PULP_PAD_MASK              1

#if defined(CONFIG_RISCV_SOC_INTERRUPT_INIT)
void soc_interrupt_init(void);
#endif

#define SOC_WFI                    __asm__ volatile("wfi")

/* lib-c hooks required RAM defined variables */
#define RISCV_RAM_BASE             CONFIG_DTCM_BASE_ADDRESS
#define RISCV_RAM_SIZE             CONFIG_DTCM_SIZE

void pulp_soc_eu_register_udma_callback(u32_t event, void (*callback)(), void *arg);

int cluster_power_up();

int cluster_power_down();

void cluster_alloc_init();

#endif /* !_ASMLANGUAGE */

// This event is used by FC to notify few events to the cluster:
//  - A remote cluster to FC event was handled and the cluster can then try to
//    post again another event in case it was working
//  - There was a remote request handled so the cluster can check iif the one is
//    waiting for has finished
#define CLUSTER_CALL_EVT 1

#define FC_TASK_END 1

#define CLUSTER_TASK_T_NEXT              0
#define CLUSTER_TASK_T_NB_CORES          4
#define CLUSTER_TASK_T_ENTRY             8
#define CLUSTER_TASK_T_ARGS              12
#define CLUSTER_TASK_T_STACKS            16
#define CLUSTER_TASK_T_MASTER_STACK_SIZE 20
#define CLUSTER_TASK_T_SLAVE_STACK_SIZE  24
#define CLUSTER_TASK_T_PENDING           28

#endif /* __GAP_SOC_H_ */
