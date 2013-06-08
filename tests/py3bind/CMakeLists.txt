cmake_minimum_required(VERSION 2.8)

include_directories(../../src)

set(utest_py3bind_src _main.c)

add_executable(utest_py3bind ${utest_py3bind_src})
target_link_libraries(utest_py3bind nxkernel nxutest nxpy3bind)

nx_filter("${utest_py3bind_src}")

add_custom_command(TARGET utest_py3bind
                   POST_BUILD
                   COMMAND $<TARGET_FILE:utest_py3bind>)
