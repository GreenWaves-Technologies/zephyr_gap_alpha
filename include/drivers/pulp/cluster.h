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

#if 0
struct pi_cluster_task
{
  struct pi_cluster_task *next;
  int nb_cores;
  // entry function and its argument(s)
  void (*entry)(struct pi_cluster_task *);
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

int cluster_send_task_async(struct cluster *cluster, struct pi_cluster_task *cl_task, struct k_poll_signal *signal);

int cluster_send_task(struct cluster *cluster, struct pi_cluster_task *cl_task);

int cluster_disable(struct cluster *cluster);


#define CLUSTER_TASK(cluster_entry) { .entry=cluster_entry, .stacks=NULL, .master_stack_size=0, .slave_stack_size=0, .nb_cores=0 }

#endif

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_DRIVERS_PULP_CLUSTER_H_ */
