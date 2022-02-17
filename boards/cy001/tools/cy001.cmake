# @file tools/cy001.cmake
# @author HinsShum hinsshum@qq.com
# @date 2021/11/22 15:15:08
# @encoding utf-8
# @brief Here's the first line of every cy001.cmake,
#        which is the required name of the file CMake looks for:
cmake_minimum_required(VERSION 3.1)

set(G_SOURCE_INCLUDE_DIRS ${G_SOURCE_INCLUDE_DIRS} "${PROJECT_SOURCE_DIR}/boards/${BOARD_NAME}")
add_definitions(-DCONFIG_OPTIONS_FILE="config/options.h")
add_definitions(-DYMODEM_CONFIG_FILE="config/ymodem_config.h")

include("${PROJECT_SOURCE_DIR}/boards/${BOARD_NAME}/config/driver.cmake")
include("${PROJECT_SOURCE_DIR}/boards/${BOARD_NAME}/config/stlib.cmake")

add_subdirectory(arch/stm32f10x)
add_subdirectory(boards/cy001/cpu)
add_subdirectory(boards/cy001/bsp)
add_subdirectory(boards/cy001/src)
add_subdirectory(lib/st/stm32f10x/peripheral)