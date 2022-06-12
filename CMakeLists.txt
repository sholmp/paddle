project(Paddle)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS y)
# set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE DEBUG)

# add_definitions(FONTS_DIR ${CMAKE_SOURCE_DIR}/fonts)
add_compile_definitions(FONTS_DIR="${CMAKE_SOURCE_DIR}/fonts")

set(lib_paddle_sources
    src/tile.h
 src/tile.cpp
 src/game.h
 src/game.cpp
 src/logger.h
 src/logger.cpp   
 )
add_library(paddle ${lib_paddle_sources})

message(${lib_paddle_sources})
target_link_libraries(paddle SDL2 SDL2_ttf fmt)

add_executable(paddle_exe src/main.cpp)

target_link_libraries(paddle_exe paddle)

add_subdirectory(src/utils)

add_subdirectory(test)
