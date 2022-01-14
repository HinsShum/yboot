# @file boards\CMakeLists.txt
# @author HinsShum hinsshum@qq.com
# @date 2022/01/14 19:44:30
# @encoding utf-8
# @brief Here's the first line of every CMakeLists.txt,
#        which is the required name of the file CMake looks for:
cmake_minimum_required(VERSION 3.1)

file(GLOB FILES "*.c")

set(FILES_OUT "")
filter_out(FILES_OUT FILES FILES)

set(C_SOURCE_FILES ${C_SOURCE_FILES} ${FILES} PARENT_SCOPE)
set(G_SOURCE_INCLUDE_DIRS ${G_SOURCE_INCLUDE_DIRS} "${CMAKE_CURRENT_SOURCE_DIR}/inc" PARENT_SCOPE)