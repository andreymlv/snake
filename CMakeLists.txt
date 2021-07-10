cmake_minimum_required(VERSION 3.19)
project(modern_snake)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(modern_snake ${SDL2_INCLUDE_DIRS})


add_executable(modern_snake main.cpp window.cpp window.h)

target_link_libraries(modern_snake ${SDL2_LIBRARIES})
