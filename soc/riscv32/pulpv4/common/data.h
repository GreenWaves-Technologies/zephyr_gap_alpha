/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __SOC_RISCV32_PULP_COMMON_DATA_H__
#define __SOC_RISCV32_PULP_COMMON_DATA_H__

#include "soc.h"
#include "archi/dma/mchan_v6.h"

#define CL_DMA_CMD_T_ID          (0*4)
#define CL_DMA_CMD_T_CMD         (1*4)
#define CL_DMA_CMD_T_SIZE        (2*4)
#define CL_DMA_CMD_T_STRIDE      (3*4)
#define CL_DMA_CMD_T_LENGTH      (4*4)
#define CL_DMA_CMD_T_LOC_ADDR    (5*4)
#define CL_DMA_CMD_T_EXT_ADDR    (6*4)
#define CL_DMA_CMD_T_NEXT        (7*4)

#endif
