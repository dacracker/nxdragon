# This is the master project files including all
# subprojects and defines common settings. 

cmake_minimum_required(VERSION 2.8)

# Declare the project name
project(nxdragon C)

# Set version numbers
set(NXDRAGON_VERSION_MAJOR 0)
set(NXDRAGON_VERSION_MINOR 1)
set(NXDRAGON_VERSION_PATCH 0)

# Should Lua support be included? 
option(NXDRAGON_LUA_SUPPORT ON)

# Do you wish to build the provided examples? 
option(NXDRAGON_BUILD_EXAMPLES ON)

include(cmake/nx_platform.cmake)
include(cmake/nx_filters.cmake)

# We want to mark all debug binaries with a _d suffix
set(CMAKE_DEBUG_POSTFIX "_d")

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
add_subdirectory(src/gui)
add_subdirectory(src/math)
add_subdirectory(src/utest)

# Unit tests 
add_subdirectory(tests/kernel)
add_subdirectory(tests/math)

# Language bindings 

if(NXDRAGON_LUA_SUPPORT)
	include(cmake/nx_lua.cmake) # Custom "find lua" cMake module  
	add_subdirectory(bindings/nxlua) # Lua 5.2 bindings 

	if(NXDRAGON_BUILD_EXAMPLES)
		add_subdirectory(examples/lua/parse_file)
	endif()
endif() 

# Example code
if(NXDRAGON_BUILD_EXAMPLES)
	add_subdirectory(examples/gui/simple_window)
endif()
