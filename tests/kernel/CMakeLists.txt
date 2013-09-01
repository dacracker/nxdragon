cmake_minimum_required(VERSION 2.8)

include_directories(../../src)

if(NX_CC_GCC)
	# These warnings can be safely ignored in the this test module
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast")
endif()

set(utest_kernel_src _main.c
					 test_atomic.h
					 test_atomic.c
					 test_list.h
					 test_list.c
					 test_timer.h
					 test_timer.c
					 test_queue.h
					 test_queue.c
					 test_events.h
					 test_events.c)

add_executable(utest_kernel ${utest_kernel_src})
target_link_libraries(utest_kernel nxkernel nxutest)

nx_filter("${utest_kernel_src}")

add_custom_command(TARGET utest_kernel
                   POST_BUILD
                   COMMAND $<TARGET_FILE:utest_kernel>)
