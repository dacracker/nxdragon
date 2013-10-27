cmake_minimum_required(VERSION 2.8)

include_directories(../../../src
					../../../bindings/)

set(lua_parse_file_src _main.c)

add_executable(lua_parse_file ${lua_parse_file_src})
target_link_libraries(lua_parse_file nxkernel nxlua)

nx_filter("${lua_parse_file_src}")
