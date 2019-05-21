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

  if (task->id == FC_TASK_CALLBACK_ID)
  {
    k_work_init(&task->implem.workitem, end_of_task_handler);
    k_work_submit(&task->implem.workitem);
  }
}
