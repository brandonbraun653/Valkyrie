include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

gen_static_lib_variants(
  TARGET
    lib_valkyrie_kernel_threads
  SOURCES
    background_thread.cpp
    hardware_thread.cpp
    monitor_thread.cpp
    thread_listing.cpp
  PRV_LIBRARIES
    aurora_intf_inc
    chimera_intf_inc
    project_inc
  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Valkyrie/kernel"
)