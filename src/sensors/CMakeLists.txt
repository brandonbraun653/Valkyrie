include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

add_subdirectory(accelerometer)
add_subdirectory(gyroscope)
add_subdirectory(magnetometer)

gen_static_lib_variants(
  TARGET
    lib_valkyrie_sensor
  SOURCES
    sensor_imu.cpp
  PRV_LIBRARIES
    aurora_intf_inc
    chimera_intf_inc
    project_inc
  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Valkyrie/sensors"
)
