CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

PROJECT(myshell)

# 设置C++标准
SET(CMAKE_CXX_STANDARD 11)

# 添加可执行文件
ADD_EXECUTABLE(myshell src/main.c)

aux_source_directory(${PROJECT_SOURCE_DIR}/src src_dirs)

# 条件判断
if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -O0")
    message("Debug mode:${CMAKE_C_FLAGS_DEBUG}")
    add_executable(test_debug ${src_dirs})

elseif(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall -O3")
    message("Release mode:${CMAKE_C_FLAGS_RELEASE}")
    add_executable(test_release ${src_dirs})
else()
    message("else:${CMAKE_BUILD_TYPE}")
    message("else:${CMAKE_C_FLAGS_RELEASE}")
    add_executable(test_release ${src_dirs})
endif()
