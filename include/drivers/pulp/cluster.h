/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DRIVERS_PULP_CLUSTER_H_
#define ZEPHYR_INCLUDE_DRIVERS_PULP_CLUSTER_H_

#include <kernel.h>
#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

struct cluster_task
{
  struct cluster_task *next;
  int nb_cores;
  // entry function and its argument(s)
  void (*entry)(struct cluster_task *);
  void *arg;
  // pointer to first stack, and size for each cores
  void *stacks;
  u32_t master_stack_size;
  u32_t slave_stack_size;
  int pending;
  int cid;
  struct k_poll_signal *signal;
};

struct cluster
{
  int cid;
  struct k_mutex mutex;
  int enable_count;
};

struct cluster *cluster_get(struct device *device, int cid);

int cluster_enable(struct cluster *cluster);

int cluster_send_task_async(struct cluster *cluster, struct cluster_task *cl_task, struct k_poll_signal *signal);

int cluster_send_task(struct cluster *cluster, struct cluster_task *cl_task);

int cluster_disable(struct cluster *cluster);

void cluster_alloc_info(struct cluster *cluster, int *size, void **first_chunk, int *nb_chunks);

void cluster_alloc_dump(struct cluster *cluster);

void *cluster_alloc(struct cluster *cluster, int size);

void cluster_free(struct cluster *cluster, void *chunk, int size);

void *cluster_alloc_align(struct cluster *cluster, int size, int align);


#define CLUSTER_TASK(cluster_entry) { .entry=cluster_entry, .stacks=NULL, .master_stack_size=0, .slave_stack_size=0, .nb_cores=0 }

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_DRIVERS_PULP_CLUSTER_H_ */
