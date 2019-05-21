zephyr_compile_options_ifndef(
  CONFIG_RISCV_GENERIC_TOOLCHAIN
  -march=rv32imcxgap8 -mPE=8 -mFC=1
  )

zephyr_sources(
  drivers/hyper/hyperram-v1.c
  kernel/riscv/pe-eu-v3.S
 )
