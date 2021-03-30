include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")
include("${COMMON_TOOL_ROOT}/cmake/modules/CodeCoverage.cmake")


# Create the executable target
add_executable(valkyrie_tests "bringup/test_test.cpp")
target_link_libraries(valkyrie_tests PRIVATE
  # Public Includes
  gtest_inc
  chimera_intf_inc
  aurora_intf_inc
  prj_device_target

  # Static Libraries
  gtest_src

  # Linux
  $<$<PLATFORM_ID:Linux>:pthread>
)
export(TARGETS valkyrie_tests FILE "${PROJECT_BINARY_DIR}/tests/valkyrie_tests.cmake")

# Create the coverage target
setup_target_for_coverage_lcov(
  NAME valkyrie_coverage_tests
  EXECUTABLE "${PROJECT_ROOT}/artifacts/last_build_version/sys_test"
  DEPENDENCIES valkyrie_tests
  BASE_DIRECTORY "../"
  EXCLUDE "/usr/*" "${PROJECT_ROOT}/tests/*" "${PROJECT_ROOT}/lib/*"
  NO_DEMANGLE
)

# Copy the built executable to the common output directory for debugging
add_custom_command(TARGET valkyrie_tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:valkyrie_tests> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sys_test
)

# Copy the coverage results into the artifacts directory
add_custom_command(TARGET valkyrie_coverage_tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_ROOT}/build/valkyrie_coverage_tests"
      $<TARGET_FILE_DIR:valkyrie_tests> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/coverage_results
)