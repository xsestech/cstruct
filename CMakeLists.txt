cmake_minimum_required(VERSION 3.27)

project(cstruct VERSION 1.0.0 DESCRIPTION "My structs implementation on c")

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
include(GNUInstallDirs)
file(GLOB sources
                "${PROJECT_SOURCE_DIR}/include/*/*.h"
        #        "${PROJECT_SOURCE_DIR}/include/*/*/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c")
add_library(cstruct SHARED ${sources})
include_directories("${PROJECT_SOURCE_DIR}/include")
target_include_directories(cstruct PRIVATE .)

file(GLOB headers
#        "${PROJECT_SOURCE_DIR}/include/dynamic/*.h"
#        "${PROJECT_SOURCE_DIR}/include/node/*.h"
#        "${PROJECT_SOURCE_DIR}/include/static/*.h"
        "${PROJECT_SOURCE_DIR}/include/*/*.h"
)

target_include_directories(cstruct PUBLIC ${headers})
set_target_properties(cstruct PROPERTIES
        VERSION ${PROJECT_VERSION}
        PUBLIC_HEADER ${headers})
configure_file(cstruct.pc.in cstruct.pc @ONLY)
target_sources(cstruct
        PRIVATE ${sources}
        PUBLIC FILE_SET HEADERS
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES include/dynamic/vector.h)
install(TARGETS cstruct
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cstruct)

install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cstruct)
install(FILES ${CMAKE_BINARY_DIR}/cstruct.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

