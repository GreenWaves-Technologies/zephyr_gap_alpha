zephyr_compile_options_ifndef(
  CONFIG_RISCV_GENERIC_TOOLCHAIN
  -march=rv32imcxgap8 -mPE=8 -mFC=1
  )

zephyr_sources(
  drivers/udma/udma-v2.c
  drivers/cpi/cpi-v1.c
  drivers/spi/spim-v2.c
  drivers/i2c/i2c-v2.c
  drivers/gpio/gpio-v2.c
  drivers/hyper/hyperram-v1.c
  kernel/riscv/pe-eu-v3.S
  kernel/cluster_call.c
 )
