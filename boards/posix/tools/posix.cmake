# @file boards\posix\tools\linux.cmake
# @author HinsShum hinsshum@qq.com
# @date 2021/11/11 13:19:48
# @encoding utf-8
# @brief Here's the first line of every win32.cmake,
#        which is the required name of the file CMake looks for:
cmake_minimum_required(VERSION 3.1)

set(C_SOURCE_LIBS ${C_SOURCE_LIBS} "pthread")
set(G_SOURCE_INCLUDE_DIRS ${G_SOURCE_INCLUDE_DIRS} "${PROJECT_SOURCE_DIR}/boards/${BOARD_NAME}")
add_definitions(-DCONFIG_OPTIONS_FILE="config/options.h")
add_definitions(-DYMODEM_CONFIG_FILE="config/ymodem_config.h")

include("${PROJECT_SOURCE_DIR}/boards/${BOARD_NAME}/config/driver.cmake")

add_subdirectory(boards/posix/bsp)
add_subdirectory(boards/posix/src)
add_subdirectory(lib/posix)

set(CMAKE_C_FLAGS "-Wall -Werror -Wformat=0 -std=gnu99 -ffunction-sections -fdata-sections")