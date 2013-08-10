cmake_minimum_required(VERSION 2.8)

# Find Python 3
find_package(PythonInterp 3 REQUIRED)
find_package(PythonLibs 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})

# This is needed to find our configuration file
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(nxpy3bind_inc 
	nx_pyengine.h
	nx_pymodule.h
	nx_def.h
	nx_doc.h
	nx_pykernel_atomic.h
	nx_pykernel_list.h)
			    
set(nxpy3bind_src 
	nx_pyengine.c
	nx_pymodule.c
	nx_pykernel_atomic.c
	nx_pykernel_list.c)

set(SETUP_PY "${CMAKE_BINARY_DIR}/setup.py")
set(OUTPUT_PY "${CMAKE_BINARY_DIR}/build/timestamp")

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in" "${SETUP_PY}")

add_custom_command(OUTPUT ${OUTPUT_PY}
				   COMMAND ${PYTHON_EXECUTABLE} ${SETUP_PY} build --build-base=${LIBRARY_OUTPUT_PATH}
				   COMMAND ${CMAKE_COMMAND} -E touch ${OUTPUT_PY})

add_custom_target(py3bind ALL DEPENDS ${OUTPUT_PY}
				  SOURCES ${nxpy3bind_src} ${nxpy3bind_inc})

nx_filter("${nxpy3bind_src};${nxpy3bind_inc}")
