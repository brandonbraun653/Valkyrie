cmake_minimum_required(VERSION 3.18.0)
project(DroneController NONE)
enable_language(C CXX ASM)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CPP_PLATFORM "freertos")

# ====================================================
# Perform very high level configuration
# ====================================================
include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")
include("lib/CommonTools/cmake/options/common.cmake")

# For now hard code the sim target build settings
add_subdirectory("lib/CommonTools/cmake/device/generic")

# Override the linker command
if(Toolchain::HAS_GCC_ARM_NONE_EABI OR Toolchain::HAS_GCC)
  include("lib/CommonTools/cmake/toolchains/linker_whole_archive.cmake")
endif()

# Select a global target flag
if(Toolchain::HAS_GCC_ARM_NONE_EABI)
  add_compile_definitions(EMBEDDED)
elseif(Toolchain::HAS_GCC)
  add_compile_definitions(SIMULATOR)
endif()

# ====================================================
# NanoPB exports
# ====================================================
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/nanopb/extra)
find_package(Nanopb REQUIRED)
set(NANO_PB_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/lib/nanopb" CACHE STRING "")

# ====================================================
# Import common packages and projects
# ====================================================
find_package(Boost REQUIRED)
add_subdirectory("lib/Aurora")
add_subdirectory("lib/Chimera")
add_subdirectory("lib/ChimeraSim")
add_subdirectory("lib/CommonTools/cpputest")
add_subdirectory("lib/CommonTools/googletest")
add_subdirectory("lib/FreeRTOS")
add_subdirectory("lib/Ripple")
add_subdirectory("lib/nanopb")

# ====================================================
# Project Exports
# ====================================================
# Project Headers
gen_intf_lib(
  TARGET
    project_inc
  INTF_INCLUDES
    "${PROJECT_ROOT}"
    "${PROJECT_ROOT}/src/config"
  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Project"
)

# FreeRTOS Configuration
gen_intf_lib(
  TARGET
    freertos_cfg
  INTF_INCLUDES
    "${PROJECT_ROOT}/src/config/freertos"
  #INTF_LIBRARIES
    #segger_sys_view_intf

    # TODO: Will need to create the A8 variant
    #segger_sys_view_cortex_m4_freertos_intf
  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Project"
)

# ====================================================
# Project Imports
# ====================================================
add_subdirectory("src")
