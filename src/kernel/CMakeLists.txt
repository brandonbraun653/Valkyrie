include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

add_subdirectory(data)
add_subdirectory(startup)

gen_intf_lib_variants(
  TARGET
    lib_valkyrie_kernel
  LIBRARIES
    lib_valkyrie_kernel_data
    lib_valkyrie_kernel_startup
  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Valkyrie"
)
