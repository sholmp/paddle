
enable_testing()

add_executable(stopwatch_test stopwatch_test.cpp)

target_link_libraries(stopwatch_test shp_utils gtest gtest_main pthread)

include_directories(${CMAKE_SOURCE_DIR}/src/utils)
add_test(NAME StopWatchTest COMMAND stopwatch_test)