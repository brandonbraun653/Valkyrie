include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

# Import the project modules
add_subdirectory(dbg)
add_subdirectory(kernel)
add_subdirectory(sensors)
add_subdirectory(sim)



target_compile_options(prj_device_target INTERFACE
  -Wno-unused-parameter
  -Wno-ignored-qualifiers
)

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

  # Hardware Libraries
  chimera_core_dbg

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

# Linux HW Build Libraries
if(Toolchain::HAS_GCC_ARM_LINUX_EABIHF AND Toolchain::REQUIRES_NATIVE_THREADS)
  target_link_libraries(Valkyrie PRIVATE
      mercury_core
      pthread
    )
endif()

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


# Copy the built executable to the common output directory for debugging
add_custom_command(TARGET Valkyrie POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Valkyrie> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sys_image
)