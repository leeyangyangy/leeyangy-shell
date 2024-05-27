# set cmake mini version
CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

# project name. result build object will use this project name
PROJECT(myshell)

# setting standard c/c++
SET(CMAKE_CXX_STANDARD 11)

# add custom target to build output dir 
# ADD_CUSTOM_COMMAND(CreateBuildDir
    # COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/build
    # COMMENT "Creating build directory."
# )

# use cmake --build  build custom object
# ADD_CUSTOM_COMMAND(
    # OUTPUT ${CMake_BINARY_DIR}/build
    # COMMAND ${CMAKE_COMMAND} -E echo "Build directory created at ${CMAKE_BINARY_DIR}/build"
    # DEPENDS CreateBuildDir
# )

# include all like .c file
FILE(GLOB_RECURSE src_dirs "${PROJECT_SOURCE_DIR}/src/**.c")

# add exec file
ADD_EXECUTABLE(myshell ${src_dirs})

# add target file
TARGET_SOURCES(myshell PRIVATE ${src_dirs})

# condiction judge debug or relase code
IF (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -O0")
    MESSAGE("Debug mode:${CMAKE_C_FLAGS_DEBUG}")
    ADD_EXECUTABLE(test_debug ${src_dirs})

ELSEIF (CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))
    SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall -O3")
    MESSAGE("Release mode:${CMAKE_C_FLAGS_RELEASE}")
    ADD_EXECUTABLE(test_release ${src_dirs})
ELSE ()
    MESSAGE("else:${CMAKE_BUILD_TYPE}")
    MESSAGE("else:${CMAKE_C_FLAGS_RELEASE}")
    ADD_EXECUTABLE(test_release ${src_dirs})
ENDIF ()
