include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

add_subdirectory(log)

gen_intf_lib_variants(
  TARGET
    lib_valkyrie_debug
  LIBRARIES
    lib_valkyrie_debug_logger
  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Valkyrie"
)
