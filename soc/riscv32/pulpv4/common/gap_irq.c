/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief gap interrupt management code
 */
#include <irq.h>
#include <soc.h>
#include "hal/pulp.h"

/*
 * Register memory map
 */

// Global offsets
#define EU_CORES_AREA_OFFSET                0x0000
#define EU_CORES_AREA_SIZE                  0x0400
#define EU_CORE_AREA_SIZE_LOG2              6
#define EU_CORE_AREA_SIZE                   (1<<EU_CORE_AREA_SIZE_LOG2)
#define EU_BARRIER_AREA_OFFSET              0x0400
#define EU_BARRIER_AREA_SIZE                0x0200
#define EU_BARRIER_SIZE_LOG2                5
#define EU_BARRIER_SIZE                     (1<<EU_BARRIER_SIZE_LOG2)
#define EU_SW_EVENTS_AREA_BASE              0x0600
#define EU_SW_EVENTS_AREA_SIZE              0x0100
#define EU_SOC_EVENTS_AREA_OFFSET           0x0700
#define EU_SOC_EVENTS_AREA_SIZE             0x0080
#define EU_EXT_EVENT_AREA_OFFSET            0x0780
#define EU_EXT_EVENT_AREA_SIZE              0x0080
#define EU_MUTEX_AREA_SIZE_LOG2             6
#define EU_MUTEX_AREA_SIZE                  (1<<EU_MUTEX_AREA_SIZE_LOG2)
#define EU_DISPATCH_AREA_SIZE_LOG2          6
#define EU_DISPATCH_AREA_SIZE               (1<<EU_DISPATCH_AREA_SIZE_LOG2)

// Demux offsets
#define EU_CORE_DEMUX_OFFSET                0x0000
#define EU_CORE_DEMUX_SIZE                  0x0040
#define EU_MUTEX_DEMUX_OFFSET               0x00C0
#define EU_MUTEX_DEMUX_SIZE                 0x0040
#define EU_DISPATCH_DEMUX_OFFSET            0x0080
#define EU_DISPATCH_DEMUX_SIZE              0x0040
#define EU_LOOP_DEMUX_OFFSET                0x0060
#define EU_LOOP_DEMUX_SIZE                  0x0020
#define EU_SW_EVENTS_DEMUX_OFFSET           0x0100
#define EU_SW_EVENTS_DEMUX_SIZE             0x0100
#define EU_BARRIER_DEMUX_OFFSET             0x0200
#define EU_BARRIER_DEMUX_SIZE               0x0200

// Only when secure extensions are active
#define EU_SEC_DEMUX_OFFSET                  0x040
#define EU_SEC_DEMUX_SIZE                    0x040

#define EU_SEC_MASK                          0x00
#define EU_SEC_MASK_AND                      0x04
#define EU_SEC_MASK_OR                       0x08


// Core area
#define EU_CORE_MASK                           0x00
#define EU_CORE_MASK_AND                       0x04
#define EU_CORE_MASK_OR                        0x08
#define EU_CORE_MASK_IRQ                       0x0C
#define EU_CORE_MASK_IRQ_AND                   0x10
#define EU_CORE_MASK_IRQ_OR                    0x14
#define EU_CORE_STATUS                         0x18
#define EU_CORE_BUFFER                         0x1C
#define EU_CORE_BUFFER_MASKED                  0x20
#define EU_CORE_BUFFER_IRQ_MASKED              0x24
#define EU_CORE_BUFFER_CLEAR                   0x28
#define EU_CORE_SW_EVENTS_MASK                 0x2C
#define EU_CORE_SW_EVENTS_MASK_AND             0x30
#define EU_CORE_SW_EVENTS_MASK_OR              0x34
#define EU_CORE_EVENT_WAIT                     0x38
#define EU_CORE_EVENT_WAIT_CLEAR               0x3C

#define EU_CORE_TRIGG_SW_EVENT                 0x00
#define EU_CORE_TRIGG_SW_EVENT_SIZE            0x40
#define EU_CORE_TRIGG_SW_EVENT_WAIT            0x40
#define EU_CORE_TRIGG_SW_EVENT_WAIT_SIZE       0x40
#define EU_CORE_TRIGG_SW_EVENT_WAIT_CLEAR      0x80
#define EU_CORE_TRIGG_SW_EVENT_WAIT_CLEAR_SIZE 0x40

#define EU_CORE_MASK_SEC_IRQ                   0x40

// ROM area
#define EU_ROM_EVENT_SOURCE                 0x00

// Soc events area
#define EU_SOC_EVENTS_CURRENT_EVENT         0x00
#define EU_SOC_EVENTS_VALID_BIT             31
#define EU_SOC_EVENTS_EVENT_MASK_BITS       8
#define EU_SOC_EVENTS_EVENT_MASK_OFFSET     0
#define EU_SOC_EVENTS_EVENT_MASK            (((1<<EU_SOC_EVENTS_EVENT_MASK_BITS)-1) << EU_SOC_EVENTS_EVENT_MASK_OFFSET)

// External events area
#define EU_EXT_EVENT_GEN                    0x00

 // Single barrier
#define EU_HW_BARR_TRIGGER_MASK             0x00
#define EU_HW_BARR_STATUS                   0x04
#define EU_HW_BARR_STATUS_SUMMARY           0x08
#define EU_HW_BARR_TARGET_MASK              0x0C
#define EU_HW_BARR_TRIGGER                  0x10
#define EU_HW_BARR_TRIGGER_SELF             0x14
#define EU_HW_BARR_TRIGGER_WAIT             0x18
#define EU_HW_BARR_TRIGGER_WAIT_CLEAR       0x1C

// Dispatch
#define EU_DISPATCH_FIFO_ACCESS             0x0
#define EU_DISPATCH_TEAM_CONFIG             0x4
#define EU_DISPATCH_NB_ELEM                 8

// Loop
#define EU_LOOP_STATE                       0x0
#define EU_LOOP_START                       0x4
#define EU_LOOP_END                         0x8
#define EU_LOOP_INCR                        0xc
#define EU_LOOP_CHUNK                      0x10
#define EU_LOOP_EPOCH                      0x14
#define EU_LOOP_SINGLE                     0x18

#define EU_LOOP_DONE                        0x0
#define EU_LOOP_LOCKED                      0x1
#define EU_LOOP_SKIP                        0x2

// Soc barriers
#define EU_SOC_BARRIER_AREA_OFFSET         0x0000
#define EU_SOC_BARRIER_AREA_SIZE           0x0100
#define EU_SOC_BARRIER_SIZE_LOG2           3
#define EU_SOC_BARRIER_SIZE                (1<<EU_SOC_BARRIER_SIZE_LOG2)

#define EU_SOC_HW_BARR_TRIGGER             0x0
#define EU_SOC_HW_BARR_TRIGGER_MASK        0x4

#define EU_SOC_LOCK_AREA_OFFSET            0x0100
#define EU_SOC_LOCK_AREA_SIZE              0x0200
#define EU_SOC_LOCK_SIZE_LOG2              4
#define EU_SOC_LOCK_SIZE                   (1<<EU_SOC_LOCK_SIZE_LOG2)

#define EU_SOC_LOCK_REG                    0x0
#define EU_SOC_LOCK_UNREG                  0x4
#define EU_SOC_LOCK_VALUE                  0x8
 


/*
 * Macros
 */

 // Areas
#define EU_CORE_AREA_OFFSET_GET(coreId)                 (EU_CORES_AREA_OFFSET + (coreId)*EU_CORE_AREA_SIZE)
#define EU_CORE_AREA_COREID_GET(offset)                 ((offset)>>EU_CORE_AREA_SIZE_LOG2)
#define EU_ROM_AREA_OFFSET_GET(coreId)                  (EU_CORE_AREA_OFFSET_GET(coreId) + EU_ROM_AREA_OFFSET)
#define EU_BARRIER_AREA_OFFSET_GET(barrier)             ((barrier)*EU_BARRIER_SIZE)
#define EU_BARRIER_AREA_BARRIERID_GET(offset)           (((offset) & (EU_BARRIER_AREA_SIZE - 1)) >> EU_BARRIER_SIZE_LOG2)
#define EU_MUTEX_AREA_OFFSET_GET(mutex)                 ((mutex)*EU_MUTEX_AREA_SIZE)
#define EU_MUTEX_AREA_MUTEXID_GET(offset)               (((offset) & (EU_MUTEX_AREA_SIZE - 1)) >> 2)
#define EU_DISPATCH_AREA_OFFSET_GET(mutex)              ((dispatch)*EU_DISPATCH_AREA_SIZE)
#define EU_DISPATCH_AREA_DISPATCHID_GET(offset)         (((offset) & (EU_DISPATCH_AREA_SIZE - 1)) >> 3)

// Core area
#define EU_CORE_TRIGG_SW_EVENT_OFFSET(event)            (EU_CORE_TRIGG_SW_EVENT + ((event)*0x4))
#define EU_CORE_TRIGG_SW_EVENT_WAIT_OFFSET(event)       (EU_CORE_TRIGG_SW_EVENT_WAIT + ((event)*0x4))
#define EU_CORE_TRIGG_SW_EVENT_WAIT_CLEAR_OFFSET(event) (EU_CORE_TRIGG_SW_EVENT_WAIT_CLEAR + ((event)*0x4))

// ROM area
#define EU_ROM_EVENT_SOURCE_OFFSET(event)               (EU_ROM_EVENT_SOURCE + ((event)*0x4))

// TODO should be moved to chip part ?
#define PULP_NB_GP_EVENTS                 8
#define PULP_FIRST_GP_EVENT               0
#define PULP_TIMER0_EVENT                 10
#define PULP_TIMER1_EVENT                 11
 // TODO the real value is not yet specified
#define EVENT_HWCE                        15
#define PULP_HW_BAR_EVENT                 16
#define PULP_MUTEX_EVENT                  17
#define PULP_DISPATCH_EVENT               18
#define PULP_LOOP_EVENT                   19
#if PULP_CHIP_FAMILY == CHIP_GAP
#define PULP_FC_SOC_EVENTS_EVENT          27
#else
#define PULP_FC_SOC_EVENTS_EVENT          26
#endif
#define PULP_SOC_EVENTS_EVENT             27
#define PULP_SOC_TRIGGER_EVENT            28
#define PULP_SOC_LOCK_EVENT               29
#define PULP_SOC_HW_BAR_EVENT             30

// SOC areas
#define ARCHI_CLUSTER_ADDR              0x00000000

#define EU_SOC_BARRIER_AREA_OFFSET_GET(barrier)             ((barrier)*EU_SOC_BARRIER_SIZE)
#define EU_SOC_BARRIER_AREA_BARRIERID_GET(offset)           (((offset) & (EU_SOC_BARRIER_AREA_SIZE - 1)) >> EU_SOC_BARRIER_SIZE_LOG2)

#define EU_SOC_LOCK_AREA_OFFSET_GET(lock)             ((lock)*EU_SOC_LOCK_SIZE)
#define EU_SOC_LOCK_AREA_LOCKID_GET(offset)           (((offset) & (EU_SOC_LOCK_AREA_SIZE - 1)) >> EU_SOC_LOCK_SIZE_LOG2)

#define pulp_write32(add, val_) (*(volatile unsigned int *)(long)(add) = val_)
#define pulp_read32(add) (*(volatile unsigned int *)(long)(add))

#define ARCHI_DEMUX_PERIPHERALS_OFFSET        0x204000

#define ARCHI_DEMUX_PERIPHERALS_ADDR          ( ARCHI_CLUSTER_ADDR + ARCHI_DEMUX_PERIPHERALS_OFFSET )

#define ARCHI_EU_DEMUX_OFFSET                 ( 0x00000 )
#define ARCHI_EU_DEMUX_ADDR                   ( ARCHI_DEMUX_PERIPHERALS_ADDR + ARCHI_EU_DEMUX_OFFSET )

static inline void eu_irq_maskSet_base(unsigned int base, unsigned int irqMask)
{
  pulp_write32(base + EU_CORE_MASK_IRQ_OR, irqMask);
}

static inline void eu_irq_maskSet(unsigned int irqMask)
{
  eu_irq_maskSet_base(ARCHI_EU_DEMUX_ADDR, irqMask);
}

static inline void eu_irq_maskClr(unsigned int irqMask)
{
  pulp_write32(ARCHI_EU_DEMUX_ADDR + EU_CORE_MASK_IRQ_AND, irqMask);
}

static inline void eu_evt_maskSet_base(unsigned int base, unsigned int evtMask)
{
#if defined(__riscv__) && !defined(__LLVM__)
  // TODO riscv compiler is not able to factorize the event unit base if we use classic C code
  __asm volatile ("sw %0,%1(%2)" : : "r" (evtMask), "I" (EU_CORE_MASK_OR), "r" (base) );
#else
  pulp_write32(base + EU_CORE_MASK_OR, evtMask);
#endif
}

static inline void eu_evt_maskSet(unsigned int evtMask)
{
  eu_evt_maskSet_base(ARCHI_EU_DEMUX_ADDR, evtMask);
}

static inline void eu_evt_maskClr(unsigned int evtMask)
{
#if defined(__riscv__) && !defined(__LLVM__)
  // TODO riscv compiler is not able to factorize the event unit base if we use classic C code
  __asm volatile ("sw %0,%1(%2)" : : "r" (evtMask), "I" (EU_CORE_MASK_AND), "r" (ARCHI_EU_DEMUX_ADDR) );
#else
  pulp_write32(ARCHI_EU_DEMUX_ADDR + EU_CORE_MASK_AND, evtMask);
#endif
}

static inline unsigned int eu_irq_mask_get()
{
  return pulp_read32(ARCHI_EU_DEMUX_ADDR + EU_CORE_MASK_IRQ);
}

void _arch_irq_enable(unsigned int irq)
{
	unsigned int key;

	key = irq_lock();
  eu_irq_maskSet(1<<irq);
  eu_evt_maskSet(1<<irq);	
	irq_unlock(key);
};

void _arch_irq_disable(unsigned int irq)
{
	unsigned int key;

	key = irq_lock();
  eu_irq_maskClr(1<<irq);
  eu_evt_maskClr(1<<irq);
	irq_unlock(key);
};

int _arch_irq_is_enabled(unsigned int irq)
{
	return (eu_irq_mask_get() >> irq) & 1;\
}

#if defined(CONFIG_RISCV_SOC_INTERRUPT_INIT)
void soc_interrupt_init(void)
{
	__asm__ volatile("csrw mtvec, %0" : : "r" (0x1c000000));
}
#endif
