cmake_minimum_required(VERSION 2.8)

# This is needed to find our configuration file
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(nxmath_inc 
	nx_doc.h
	nx_def.h
	nx_math.h)

set(nxmath_src 
	nx_math.c)

add_library(nxmath SHARED ${nxmath_inc} ${nxmath_src})

set_target_properties(nxmath PROPERTIES 
					  		 DEFINE_SYMBOL NXDRAGON_BUILD_MATH)

nx_filter("${nxmath_src};${nxmath_inc}")

