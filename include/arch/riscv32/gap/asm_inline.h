/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_ARCH_RISCV32_GAP_ASM_INLINE_H_
#define ZEPHYR_INCLUDE_ARCH_RISCV32_GAP_ASM_INLINE_H_

/*
 * The file must not be included directly
 * Include arch/cpu.h instead
 */

#if defined(__GNUC__)
#include <arch/riscv32/gap/asm_inline_gcc.h>
#else
#error "Supports only GNU C compiler"
#endif

#endif /* ZEPHYR_INCLUDE_ARCH_RISCV32_GAP_ASM_INLINE_H_ */
