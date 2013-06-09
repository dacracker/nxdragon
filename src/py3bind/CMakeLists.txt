cmake_minimum_required(VERSION 2.8)

# Find Python 3
find_package(PythonLibs 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})

add_definitions(-DNXDRAGON_BUILD_PY3BIND)

# This is needed to find our configuration file
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(nxpy3bind_inc 
	nx_pyengine.h
	nx_def.h
	nx_doc.h)
			    
set(nxpy3bind_src 
	nx_pyengine.c)

add_library(nxpy3bind SHARED 
			${nxpy3bind_src}
			${nxpy3bind_inc})

nx_filter("${nxpy3bind_src};${nxpy3bind_inc}")

target_link_libraries(nxpy3bind ${PYTHON_LIBRARY})
