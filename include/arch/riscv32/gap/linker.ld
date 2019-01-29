/*
 * Copyright (c) 2018 ETH Zurich, University of Bologna, GreenWaves Technologies
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Linker command/script file
 *
 * Linker script for the gap platform
 */

#define _LINKER
#define _ASMLANGUAGE

#include <autoconf.h>
#include <linker/sections.h>

#include <linker/linker-defs.h>
#include <linker/linker-tool.h>

#define ROMABLE_REGION              FC_RAM
#define RAMABLE_REGION              FC_RAM

#define _VECTOR_SECTION_NAME        vector
#define _EXCEPTION_SECTION_NAME     exceptions
#define _RESET_SECTION_NAME         reset

ENTRY(__reset)

MEMORY
    {
    L2_RAM (wx) : ORIGIN = CONFIG_L2_BASE_ADDRESS, LENGTH = CONFIG_L2_SIZE
    FC_RAM  (rw) : ORIGIN = CONFIG_FC_TCDM_BASE_ADDRESS, LENGTH = CONFIG_FC_TCDM_SIZE
    L1_RAM                 : ORIGIN = 0x10000004, LENGTH = 0x0000fffc
    L1_ALIAS_RAM           : ORIGIN = 0x00000004, LENGTH = 0x0000fffc
    /* Used by and documented in include/linker/intlist.ld */
    IDT_LIST  (wx)      : ORIGIN = 0xFFFFF7FF, LENGTH = 2K
}

SECTIONS
    {

#include <linker/rel-sections.ld>

    /*
     * .plt and .iplt are here according to
     * 'riscv32-zephyr-elf-ld --verbose', before text section.
     */
    SECTION_PROLOGUE(.plt,,)
	{
		*(.plt)
	}

    SECTION_PROLOGUE(.iplt,,)
	{
		*(.iplt)
	}

    GROUP_START(L2_RAM)

    SECTION_PROLOGUE(_VECTOR_SECTION_NAME,,)
    {
		. = ALIGN(4);
		KEEP(*(.vectors))
    KEEP(*(.vectors.*))
    } GROUP_LINK_IN(L2_RAM)

    SECTION_PROLOGUE(_RESET_SECTION_NAME,,)
    {
		KEEP(*(.reset.*))
    } GROUP_LINK_IN(L2_RAM)

    SECTION_PROLOGUE(_EXCEPTION_SECTION_NAME,,)
    {
		 KEEP(*(".exception.entry.*"))
		 *(".exception.other.*")
    } GROUP_LINK_IN(L2_RAM)

    SECTION_PROLOGUE(_TEXT_SECTION_NAME,,)
	{
		. = ALIGN(4);

		KEEP(*(.openocd_dbg))
		KEEP(*(".openocd_dbg.*"))

		_image_text_start = .;
		*(.text)
		*(".text.*")
		*(.gnu.linkonce.t.*)
		*(.eh_frame)
	} GROUP_LINK_IN(L2_RAM)

    _image_text_end = .;

    GROUP_END(L2_RAM)

    GROUP_START(RAMABLE_REGION)

#include <linker/common-rom.ld>

    SECTION_PROLOGUE(_RODATA_SECTION_NAME,,)
	{
		 . = ALIGN(4);
#ifdef CONFIG_GEN_SW_ISR_TABLE
		KEEP(*(SW_ISR_TABLE))
#endif
		*(.rodata)
		*(".rodata.*")
		*(.gnu.linkonce.r.*)

#ifdef CONFIG_SOC_RODATA_LD
#include <soc-rodata.ld>
#endif

	} GROUP_LINK_IN(RAMABLE_REGION)

    _image_ram_start = .;

#include <linker/common-ram.ld>

    SECTION_DATA_PROLOGUE(_DATA_SECTION_NAME,,)
	{

		 . = ALIGN(4);
		 *(.data)
		 *(".data.*")

		 *(.sdata .sdata.* .gnu.linkonce.s.*)
		 *(.sdata2 .sdata2.* .gnu.linkonce.s2.*)

#ifdef CONFIG_SOC_RWDATA_LD
#include <soc-rwdata.ld>
#endif

	}  GROUP_LINK_IN(RAMABLE_REGION)

	SECTION_DATA_PROLOGUE(_BSS_SECTION_NAME,(NOLOAD),)
	{
		/*
		 * For performance, BSS section is assumed to be 4 byte aligned and
		 * a multiple of 4 bytes
		 */
		 . = ALIGN(4);
		 __bss_start = .;
		 *(.sbss)
		 *(".sbss.*")
		 *(.bss)
		 *(".bss.*")
		 COMMON_SYMBOLS
		 /*
		  * As memory is cleared in words only, it is simpler to ensure the BSS
		  * section ends on a 4 byte boundary. This wastes a maximum of 3 bytes.
		  */
		  __bss_end = ALIGN(4);
	}  GROUP_LINK_IN(RAMABLE_REGION)

    SECTION_PROLOGUE(_NOINIT_SECTION_NAME,(NOLOAD),)
	{
		/*
		 * This section is used for non-initialized objects that
		 * will not be cleared during the boot process.
		 */
		 *(.noinit)
		 *(".noinit.*")

#ifdef CONFIG_SOC_NOINIT_LD
#include <soc-noinit.ld>
#endif

	} GROUP_LINK_IN(RAMABLE_REGION)

     _image_ram_end = .;
     _end = .; /* end of image */

#ifdef CONFIG_GEN_ISR_TABLES
#include <linker/intlist.ld>
#endif

     GROUP_END(RAMABLE_REGION)

  SECTION_DATA_PROLOGUE(l2_ram,(NOLOAD),)
  {
     *(.l2_ram)
     *(".l2_ram.*")
  }  GROUP_LINK_IN(L2_RAM)

  SECTION_DATA_PROLOGUE(l1_tiny_ram,(NOLOAD),)
  {
     *(.l1_tiny_ram)
     *(".l1_tiny_ram.*")
  }  GROUP_LINK_IN(L1_ALIAS_RAM)

  SECTION_DATA_PROLOGUE(l1_ram,(ORIGIN(L1_RAM) + SIZEOF(l1_tiny_ram)),)
  {
     *(.l1_ram)
     *(".l1_ram.*")
  }  GROUP_LINK_IN(L1_RAM)

  __l1_heap_start = ALIGN(4);
  __l1_heap_size = LENGTH(L1_RAM) - __l1_heap_start + ORIGIN(L1_RAM);

#include <linker/debug-sections.ld>

  SECTION_PROLOGUE(.Pulp_Chip.Info, 0,)            { *(.Pulp_Chip.Info) }

}
