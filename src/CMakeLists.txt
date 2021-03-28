include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")



add_executable(Valkyrie
  kernel/startup/main.cpp
  kernel/startup/sys_init.cpp
)
target_include_directories(Valkyrie PRIVATE "." ${PROJECT_ROOT})
target_link_libraries(Valkyrie PRIVATE
  # Public Includes
  aurora_intf_inc
  Boost::boost
  chimera_intf_inc

  # Hardware Libraries
  chimera_core_dbg

  # Target Properties
  prj_device_target
  prj_build_target
)

# Copy the built executable to the common output directory for debugging
add_custom_command(TARGET Valkyrie POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Valkyrie> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sys_image
)