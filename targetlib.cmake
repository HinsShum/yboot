# @file targetlib.cmake
# @author HinsShum hinsshum@qq.com
# @date 2022/02/17 15:11:06
# @encoding utf-8
# @brief Here's the first line of every targetlib.cmake,
#        which is the required name of the file CMake looks for:
cmake_minimum_required(VERSION 3.1)

if("${TARGETLIB_NAME}" STREQUAL "")
    message(FATAL_ERROR "Must set ${TARGETLIB_NAME} before include this cmake file")
endif()
set(CMAKELISTS_DIRS)
set(TARGET_C_FILES)
set(TARGET_INC_DIRS)

# recursively call CMakeLists.txt
file(GLOB_RECURSE CMAKELISTS "CMakeLists.txt")
dirname(CMAKELISTS CMAKELISTS_DIRS)
filter_out(CMAKE_CURRENT_SOURCE_DIR CMAKELISTS_DIRS CMAKELISTS_DIRS)
foreach(SUB_DIR ${CMAKELISTS_DIRS})
    add_subdirectory(${SUB_DIR})
endforeach(SUB_DIR)

# compile target
add_library(${TARGETLIB_NAME} STATIC ${TARGET_C_FILES})
target_include_directories(${TARGETLIB_NAME} PRIVATE ${TARGET_INC_DIRS} ${G_SOURCE_INCLUDE_DIRS})

# set global variables
set(C_SOURCE_LIBS ${C_SOURCE_LIBS} ${TARGETLIB_NAME} PARENT_SCOPE)
set(G_SOURCE_INCLUDE_DIRS ${G_SOURCE_INCLUDE_DIRS} ${TARGET_INC_DIRS} PARENT_SCOPE)