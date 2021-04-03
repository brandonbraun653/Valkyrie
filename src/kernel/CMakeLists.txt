include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

add_subdirectory(data)
add_subdirectory(startup)
add_subdirectory(threads)

gen_intf_lib_variants(
  TARGET
    lib_valkyrie_kernel
  LIBRARIES
    lib_valkyrie_kernel_data
    lib_valkyrie_kernel_startup
    lib_valkyrie_kernel_threads
  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Valkyrie"
)
