include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

# Import the project modules
add_subdirectory(dbg)
add_subdirectory(kernel)
add_subdirectory(sensors)
add_subdirectory(sim)


# Collect all the source modules together

#------------------------------------------------------------------------------
# Valkyrie Executable
#------------------------------------------------------------------------------
add_executable(Valkyrie kernel/startup/main.cpp)
target_include_directories(Valkyrie PRIVATE "." ${PROJECT_ROOT})
target_link_libraries(Valkyrie PRIVATE
  # Public Includes
  aurora_intf_inc
  Boost::boost
  chimera_intf_inc

  # Project Libraries
  lib_valkyrie_debug
  lib_valkyrie_kernel
  lib_valkyrie_sensor_accelerometer
  lib_valkyrie_sensor_gyroscope
  lib_valkyrie_sensor_magnetometer
  lib_valkyrie_sensor
  lib_valkyrie_sim

  # Apollo
  apollo_freertos_hooks

  # Hardware Libraries
  chimera_core_dbg

  # Segger System View (Make this only embedded)
  # segger_sys_view
  # segger_sys_view_intf
  # segger_sys_view_cortex_m4_freertos

  # Utility Libraries
  aurora_core_dbg
  aurora_hmi_dbg
  aurora_logging_dbg
  aurora_memory_dbg
  aurora_database_dbg
  aurora_datastore_dbg

  # Target Properties
  prj_device_target
  prj_build_target
)


# Sim Only Libraries
if(Toolchain::HAS_GCC)
  target_link_libraries(Valkyrie PRIVATE
    # Testing & Mock Libraries
    gmock_src
    gtest_src

    # Hardware sim
    chimera_sim_core

    # RTOS
    freertos_core
    freertos_posix_port
    freertos_heap_4
    freertos_intf_inc_all
    pthread

    # Simulator networking
    zmq
  )
endif()

# Force the protobuf definitions to be built before the executable
# add_dependencies(Valkyrie ahrs_pb2)

# Copy the built executable to the common output directory for debugging
add_custom_command(TARGET Valkyrie POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Valkyrie> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sys_image
)