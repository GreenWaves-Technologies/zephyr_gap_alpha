add_custom_target(run
  COMMAND
  pulp-run --config=gap --binary=${APPLICATION_BINARY_DIR}/zephyr/${KERNEL_ELF_NAME} prepare run
  DEPENDS ${logical_target_for_zephyr_elf}
  WORKING_DIRECTORY ${APPLICATION_BINARY_DIR}
  USES_TERMINAL
  )
