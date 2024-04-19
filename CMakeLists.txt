cmake_minimum_required(VERSION 3.27)

project(cstruct)

##
### Test definitions ###
##
SET(CMAKE_SYSTEM_PROCESSOR arm)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_C_STANDARD 99)
configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(test)

##
### Source definitions ###
##

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/*/*.h"
        "${PROJECT_SOURCE_DIR}/include/*/*/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c")

add_library(cstruct ${sources})
