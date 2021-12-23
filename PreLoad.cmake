cmake_minimum_required(VERSION 3.18.0)

# ====================================================
# Override the toolchain used. This must be done here
# else CMake won't allow the override.
# ====================================================
set(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" CACHE STRING "")
set(COMMON_TOOL_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/lib/CommonTools" CACHE STRING "")
set(BOOST_ROOT "$ENV{HOME}/Boost/boost_1_77_0" CACHE STRING "")
set(ARM_LINUX_EABI_ROOT "$ENV{HOME}/toolchain/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/" CACHE STRING "")

include("${COMMON_TOOL_ROOT}/cmake/options/toolchain.cmake")
