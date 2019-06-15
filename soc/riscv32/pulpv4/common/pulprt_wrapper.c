/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* 
 * Authors: Germain Haugou, ETH (germain.haugou@iis.ee.ethz.ch)
 */

#include "pmsis.h"

static void end_of_task_handler(struct k_work *work)
{
  pi_task_t *task = (pi_task_t *)((intptr_t)work - (intptr_t)&(((pi_task_t *)NULL)->implem.workitem));
  ((void (*)(void *))task->arg[0])((void *)task->arg[1]);
}

void __rt_event_handle_end_of_task(pi_task_t *task)
{
  task->done = 1;
  if (task->implem.kpoll)
  {
    k_poll_signal_raise(&task->implem.signal, 0);
  }

  if (task->id == PI_TASK_CALLBACK_ID)
  {
    k_work_init(&task->implem.workitem, end_of_task_handler);
    k_work_submit(&task->implem.workitem);
  }
}

void pi_time_wait_us(int time_us)
{
  k_sleep((time_us + 999) / 1000);
}

void pi_task_push(pi_task_t *task)
{
  __rt_event_handle_end_of_task(task);
}

static void end_of_delayed_task_handler(struct k_work *work)
{
  pi_task_t *task = (pi_task_t *)((intptr_t)work - (intptr_t)&(((pi_task_t *)NULL)->implem.workitem));

  task->done = 1;
  if (task->implem.kpoll)
  {
    k_poll_signal_raise(&task->implem.signal, 0);
  }

  if (task->id == PI_TASK_CALLBACK_ID)
  {
    ((void (*)(void *))task->arg[0])((void *)task->arg[1]);
  }
}


void pi_task_push_delayed_us(pi_task_t *task, uint32_t delay)
{
  k_delayed_work_init(&task->implem.delayed_workitem, end_of_delayed_task_handler);
  k_delayed_work_submit(&task->implem.delayed_workitem, (delay + 999) / 1000);
}
