# @file app\CMakeLists.txt
# @author HinsShum hinsshum@qq.com
# @date 2022/02/17 15:09:17
# @encoding utf-8
# @brief Here's the first line of every CMakeLists.txt,
#        which is the required name of the file CMake looks for:
cmake_minimum_required(VERSION 3.1)

# set(TARGETLIB_NAME app)
# include("${PROJECT_SOURCE_DIR}/targetlib.cmake")
set(CFILES)
set(INCDIRS)

# recursively call CMakeLists.txt
file(GLOB_RECURSE CMAKELISTS "CMakeLists.txt")
dirname(CMAKELISTS CMAKELISTS_DIRS)
filter_out(CMAKE_CURRENT_SOURCE_DIR CMAKELISTS_DIRS CMAKELISTS_DIRS)
foreach(SUB_DIR ${CMAKELISTS_DIRS})
    add_subdirectory(${SUB_DIR})
endforeach(SUB_DIR)

set(C_SOURCE_FILES ${C_SOURCE_FILES} ${CFILES} PARENT_SCOPE)
set(G_SOURCE_INCLUDE_DIRS ${G_SOURCE_INCLUDE_DIRS} ${INCDIRS} PARENT_SCOPE)