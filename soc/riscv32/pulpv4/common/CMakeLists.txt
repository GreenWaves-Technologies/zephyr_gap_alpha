zephyr_include_directories(.)

zephyr_compile_options_ifndef(
  CONFIG_RISCV_GENERIC_TOOLCHAIN
  -march=IMXpulpv2
  )

zephyr_sources(
  soc_irq.S
  vector.S
  gap_irq.c
  gap_idle.c
  soc_event_eu.c
  )
