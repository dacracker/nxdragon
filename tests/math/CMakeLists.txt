cmake_minimum_required(VERSION 2.8)

include_directories(../../src)

set(utest_math_src _main.c
				   test_vector2.h
				   test_vector2.c
				   test_point.h
				   test_point.c
				   test_rect.h
				   test_rect.c)

add_executable(utest_math ${utest_math_src})
target_link_libraries(utest_math nxmath nxutest)

nx_filter("${utest_math_src}")

add_custom_command(TARGET utest_math
                   POST_BUILD
                   COMMAND $<TARGET_FILE:utest_math>)
