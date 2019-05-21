separate_arguments(runner_args WINDOWS_COMMAND "$ENV{RUNNER_ARGS}")

add_custom_target(run
  COMMAND
  pulp-run --config=gap --binary=${APPLICATION_BINARY_DIR}/zephyr/${KERNEL_ELF_NAME} prepare run ${runner_args}
  DEPENDS ${logical_target_for_zephyr_elf}
  WORKING_DIRECTORY ${APPLICATION_BINARY_DIR}
  USES_TERMINAL
  )
