# This is the master project files including all
# subprojects and defines common settings. 

cmake_minimum_required(VERSION 2.8)

# Declare the project name
project(nxdragon C)

# Set version numbers
set(NXDRAGON_VERSION_MAJOR 0)
set(NXDRAGON_VERSION_MINOR 1)
set(NXDRAGON_VERSION_PATCH 0)

option(NXDRAGON_PYTHON3_SUPPORT ON)

# Option for using the built in sound-engine
option(NXDRAGON_SOUND_SUPPORT ON)

include(cmake/nx_platform.cmake)
include(cmake/nx_filters.cmake)

# We want to put all binaries in the same output dir	   
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# And we want all out libs to be in the same folderas the executables
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

configure_file("${PROJECT_SOURCE_DIR}/nxdragon_config.h.in"
			   "${PROJECT_BINARY_DIR}/nxdragon_config.h")

# We need to include this directory to compile with exudia_config.h
include_directories("${PROJECT_BINARY_DIR}")

# Include our source directories
add_subdirectory(src/kernel)
add_subdirectory(src/math)
add_subdirectory(src/utest)

if(NXDRAGON_PYTHON3_SUPPORT)
	add_subdirectory(src/py3bind)
endif()

if(NXDRAGON_SOUND_SUPPORT)
	add_subdirectory(src/sound)
	add_subdirectory(tests/sound)
endif()

# Unit tests 
add_subdirectory(tests/kernel)
add_subdirectory(tests/math)
#add_subdirectory(tests/py3bind)
