/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __SOC_RISCV32_PULP_COMMON_ALLOC_H__
#define __SOC_RISCV32_PULP_COMMON_ALLOC_H__

#include <pmsis_decl.h>

typedef struct rt_alloc_block_s {
  int                      size;
  struct rt_alloc_block_s *next;
} rt_alloc_chunk_t;

typedef struct rt_alloc_s {
  rt_alloc_chunk_t *first_free;
} rt_alloc_t;

L2_DATA extern rt_alloc_t alloc_l1[];
L2_DATA extern rt_alloc_t alloc_l2;

void rt_user_alloc_info(rt_alloc_t *alloc, int *_size, void **first_chunk, int *_nb_chunks);

void rt_user_alloc_dump(rt_alloc_t *alloc);

void *rt_user_alloc(rt_alloc_t *a, int size);

void *rt_user_alloc_align(rt_alloc_t *a, int size, int align);

void rt_user_free(rt_alloc_t *a, void *_chunk, int size);

void l1_alloc_init(int cid);

static inline rt_alloc_t *rt_alloc_l1(int cid) { return &alloc_l1[cid]; }

static inline rt_alloc_t *rt_alloc_l2() { return &alloc_l2; }

#include <pmsis_implem.h>


#endif