#!/bin/sh -ex

cp $PULP_PROJECT_HOME/runtime/pulp-rt/drivers/hyper/hyperram-v1.c pulprt/drivers/hyper
cp $PULP_PROJECT_HOME/runtime/pulp-rt/kernel/riscv/pe-eu-v3.S pulprt/kernel/riscv
cp $PULP_PROJECT_HOME/runtime/pulp-rt/kernel/cluster_call.c pulprt/kernel/

cp -r $PULP_PROJECT_HOME/runtime/pulp-rt/include/pmsis/* pulprt/include/pmsis/