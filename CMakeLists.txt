project(Paddle)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS y)
# set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE DEBUG)



set(lib_paddle_sources
 src/tile.cpp
 src/game.cpp
 src/logger.cpp   
 )
add_library(paddle ${lib_paddle_sources})

message(${lib_paddle_sources})
target_link_libraries(paddle SDL2 fmt)

add_executable(paddle_exe src/main.cpp)

target_link_libraries(paddle_exe paddle)
