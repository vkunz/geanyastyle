# project name
project(geanyastyle)

# require cmake version >= 2.8
cmake_minimum_required(VERSION 2.8)

# set path to projects additional cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

# set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING
    "Choose the type of build, options are: Debug Release" FORCE)
endif(NOT CMAKE_BUILD_TYPE)

# We do not accept InSource build anymore
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" InSource)
if(InSource)
    # print message
    message(FATAL_ERROR "InSource build is forbidden for ${PROJECT_NAME}\n"
            "Please use a subdirectory to build ${PROJECT_NAME}")
endif(InSource)

# find pkg-config
find_package(PkgConfig REQUIRED)

# find geany package config using pkg-config
pkg_check_modules(GEANY REQUIRED geany)

# add include directories provided by pkg-config
include_directories(${GEANY_INCLUDE_DIRS})

# add defines provided by pkg-config
add_definitions(${GEANY_CFLAGS})

# add src directory
add_subdirectory(src)

# print some information
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Install prefix: ${CMAKE_INSTALL_PREFIX}")
