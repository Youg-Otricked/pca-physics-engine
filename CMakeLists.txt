cmake_minimum_required(VERSION 3.16)
project(game C)

set(CMAKE_C_STANDARD 99)

# Raylib (built from source in ./raylib)
add_subdirectory(raylib)

file(GLOB SOURCES CONFIGURE_DEPENDS "*.c")

add_executable(out ${SOURCES})

target_include_directories(out PRIVATE
    raylib/src
)

target_link_libraries(out PRIVATE
    raylib
    m
    pthread
    dl
    rt
    X11
    GL
)