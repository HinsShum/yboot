# @file tools\win32.cmake
# @author HinsShum hinsshum@qq.com
# @date 2021/11/11 13:19:48
# @encoding utf-8
# @brief Here's the first line of every win32.cmake,
#        which is the required name of the file CMake looks for:
cmake_minimum_required(VERSION 3.1)

set(C_SOURCE_LIBS ${C_SOURCE_LIBS} "pthread")

add_subdirectory(bsp/win32)
add_subdirectory(lib/win32)