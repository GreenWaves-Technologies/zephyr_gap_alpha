#!/bin/sh -ex

cp $PULP_PROJECT_HOME/runtime/pulp-rt/drivers/hyper/hyperram-v1.c pulprt/drivers/hyper
cp $PULP_PROJECT_HOME/runtime/pulp-rt/drivers/spi/spim-v2.c pulprt/drivers/spi
cp $PULP_PROJECT_HOME/runtime/pulp-rt/drivers/cpi/cpi-v1.c pulprt/drivers/cpi
cp $PULP_PROJECT_HOME/runtime/pulp-rt/drivers/i2c/i2c-v2.c pulprt/drivers/i2c
cp $PULP_PROJECT_HOME/runtime/pulp-rt/drivers/gpio/gpio-v2.c pulprt/drivers/gpio
cp $PULP_PROJECT_HOME/runtime/pulp-rt/drivers/udma/udma-v2.c pulprt/drivers/udma
cp $PULP_PROJECT_HOME/runtime/pulp-rt/kernel/riscv/pe-eu-v3.S pulprt/kernel/riscv
cp $PULP_PROJECT_HOME/runtime/pulp-rt/kernel/cluster_call.c pulprt/kernel/

cp -r $PULP_PROJECT_HOME/runtime/pulp-rt/include/pmsis/* pulprt/include/pmsis/