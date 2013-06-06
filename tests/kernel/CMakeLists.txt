cmake_minimum_required(VERSION 2.8)

include_directories(../../src)

set(utest_kernel_src _main.c
					 test_atomic.h
					 test_atomic.c
					 test_list.h
					 test_list.c)

add_executable(utest_kernel ${utest_kernel_src})
target_link_libraries(utest_kernel nxkernel nxutest)

nx_filter("${utest_kernel_src}")

add_custom_command(TARGET utest_kernel
                   POST_BUILD
                   COMMAND $<TARGET_FILE:utest_kernel>)
