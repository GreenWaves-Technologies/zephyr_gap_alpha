if(CONFIG_HAS_PULP_HAL)
  zephyr_include_directories(include)
  zephyr_include_directories(pulprt/include)
endif()

add_subdirectory(pulprt)