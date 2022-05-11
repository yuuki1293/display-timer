cmake_minimum_required(VERSION 3.16.3)
project(display_timer)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include)

add_executable(display_timer main.cpp)

target_link_libraries(display_timer eggx X11 m pthread)