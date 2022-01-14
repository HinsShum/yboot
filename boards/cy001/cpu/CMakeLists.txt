# @file boards/cy001/cpu/CMakeLists.txt
# @author HinsShum hinsshum@qq.com
# @date 2021/11/22 16:47:52
# @encoding utf-8
# @brief Here's the first line of every CMakeLists.txt,
#        which is the required name of the file CMake looks for:
cmake_minimum_required(VERSION 3.1)

file(GLOB FILES "*.c")
file(GLOB ASM_FILES "${CMAKE_CURRENT_SOURCE_DIR}/gcc/*.s")

# set filter out files
set(FILES_OUT "")
filter_out(FILES_OUT FILES FILES)

set(C_SOURCE_FILES ${C_SOURCE_FILES} ${FILES} ${ASM_FILES} PARENT_SCOPE)
set(G_SOURCE_INCLUDE_DIRS ${G_SOURCE_INCLUDE_DIRS} "${CMAKE_CURRENT_SOURCE_DIR}/inc" PARENT_SCOPE)