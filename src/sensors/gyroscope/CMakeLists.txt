include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

gen_static_lib_variants(
  TARGET
    lib_valkyrie_sensor_gyroscope
  SOURCES
    gyro_driver_cmn.cpp
    gyro_driver_hw.cpp
    gyro_driver_sim.cpp
  PRV_LIBRARIES
    aurora_intf_inc
    chimera_intf_inc
    project_inc

    vdrone_nanopb_proto_intf_inc
    vdrone_nanopb_proto
  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Valkyrie/sensors"
)
