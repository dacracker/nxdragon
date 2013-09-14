cmake_minimum_required(VERSION 2.8)

include_directories(../../src)

set(utest_sound_src _main.c)

add_executable(utest_sound ${utest_sound_src})
target_link_libraries(utest_sound nxsound nxutest)

nx_filter("${utest_sound_src}")

add_custom_command(TARGET utest_sound
                   POST_BUILD
                   COMMAND $<TARGET_FILE:utest_sound>)
