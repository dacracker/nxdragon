cmake_minimum_required(VERSION 2.8)

# This is needed to find our configuration file
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(nxutest_inc 
	nx_utest.h)
			    
set(nxutest_src 
	nx_utest.c)

add_library(nxutest SHARED 
			${nxutest_src}
			${nxutest_inc})

set_target_properties(nxutest PROPERTIES 
					  		  DEFINE_SYMBOL NXDRAGON_BUILD_UTEST)

nx_filter("${nxutest_src};${nxutest_inc}")
