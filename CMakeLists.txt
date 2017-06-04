cmake_minimum_required(VERSION 3.5.1)
project(ActuaSoccer)

# Set all of our output directories.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/library/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/library/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -std=c11)

include_directories("${CMAKE_SOURCE_DIR}/")
include_directories("${CMAKE_SOURCE_DIR}/library/")

file(GLOB ACTUASOCCER_SOURCE_FILES

        *.h
        *.equ

        # New
        g_main.cpp
        g_config.cpp

        # Original
        euro_*.cpp
        #test.cpp
        menu.cpp
        results.cpp
        control.cpp
        gamedata.cpp
        3deng.cpp
        euro_*.c
        intronet.c
        network.c
        mallocx.c
        unmangle.c

        )

add_executable(ActuaSoccer ${ACTUASOCCER_SOURCE_FILES})

target_link_libraries(ActuaSoccer SDL2)