/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <init.h>
#include <irq.h>
#include <soc.h>
#include <device.h>
#include <string.h>
#include "hal/pulp.h"

static void (*pulp_soc_eu_udma_callbacks[ARCHI_SOC_EVENT_UDMA_NB_EVT])();
static void (*pulp_soc_eu_udma_callbacks_args[ARCHI_SOC_EVENT_UDMA_NB_EVT])();
static void (*pulp_soc_eu_udma_extra_callbacks[ARCHI_SOC_EVENT_UDMA_NB_EXTRA_EVT])();
static void (*pulp_soc_eu_udma_extra_callbacks_args[ARCHI_SOC_EVENT_UDMA_NB_EXTRA_EVT])();

extern uint32_t __pmu_soc_events;

static void pulp_soc_eu_handle_udma_event(u32_t event)
{
  void (*callback)(int event, void *) = pulp_soc_eu_udma_callbacks[event];
  if (callback)
  {
    callback(event, pulp_soc_eu_udma_callbacks_args[event]);
  }
}

static void pulp_soc_eu_handle_udma_extra_event(u32_t event)
{
  void (*callback)(int event, void *) = pulp_soc_eu_udma_extra_callbacks[event];
  if (callback)
  {
    callback(event, pulp_soc_eu_udma_extra_callbacks_args[event]);
  }
}

void pulp_soc_eu_register_udma_callback(u32_t event, void (*callback)(int event, void *), void *arg)
{
  pulp_soc_eu_udma_callbacks[event] = callback;
  pulp_soc_eu_udma_callbacks_args[event] = arg;
}

void pulp_soc_eu_register_udma_extra_callback(u32_t event, void (*callback)(int event, void *), void *arg)
{
  pulp_soc_eu_udma_extra_callbacks[event - ARCHI_SOC_EVENT_UDMA_FIRST_EXTRA_EVT] = callback;
  pulp_soc_eu_udma_extra_callbacks_args[event - ARCHI_SOC_EVENT_UDMA_FIRST_EXTRA_EVT] = arg;
}

static void pulp_soc_eu_irq_handler(void *unused)
{
  ARG_UNUSED(unused);

  while(1) {
    u32_t event = fc_eu_soc_events_pop();

    if (!eu_soc_events_is_valid(event))
      break;

    event = eu_soc_events_get_event(event);

    if (event < ARCHI_SOC_EVENT_UDMA_NB_EVT)
    {
      pulp_soc_eu_handle_udma_event(event);
    }
    else if (event < ARCHI_SOC_EVENT_UDMA_FIRST_EXTRA_EVT + ARCHI_SOC_EVENT_UDMA_NB_EXTRA_EVT)
    {
      pulp_soc_eu_handle_udma_extra_event(event - ARCHI_SOC_EVENT_UDMA_FIRST_EXTRA_EVT);
    }
    else if (event >= ARCHI_SOC_EVENT_PMU_FIRST_EVENT && event < ARCHI_SOC_EVENT_PMU_FIRST_EVENT + ARCHI_SOC_EVENT_PMU_NB_EVENTS)
    {
      __pmu_soc_events |= 1<<(event - ARCHI_SOC_EVENT_PMU_FIRST_EVENT);
    }
  }
}

static int pulp_soc_eu_init(struct device *device)
{
  ARG_UNUSED(device);

  memset(pulp_soc_eu_udma_callbacks, 0, sizeof(pulp_soc_eu_udma_callbacks));

  IRQ_CONNECT(ARCHI_FC_EVT_SOC_EVT, 0,
        pulp_soc_eu_irq_handler, NULL, 0);
  irq_enable(ARCHI_FC_EVT_SOC_EVT);

  return 0;
}

SYS_DEVICE_DEFINE("soc_event", pulp_soc_eu_init, NULL,
                PRE_KERNEL_1, 0);

