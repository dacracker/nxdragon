cmake_minimum_required(VERSION 2.8)

include_directories(../../../src)

set(simple_window_src _main.c)

add_executable(simple_window ${simple_window_src})
target_link_libraries(simple_window nxkernel nxgui)

nx_filter("${simple_window_src}")
