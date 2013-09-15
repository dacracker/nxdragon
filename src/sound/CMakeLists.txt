cmake_minimum_required(VERSION 2.8)

# Find OpenAL
find_package(OpenAL REQUIRED)
include_directories(${OPENAL_INCLUDE_DIR})

# This is needed to find our configuration file
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# header-files
set(nxsound_inc
	nx_doc.h
	nx_def.h
	nx_sound.h
	nx_wav.h)

# source-files			    
set(nxsound_src
	nx_sound.c
	nx_wav.c)
			   
add_library(nxsound SHARED ${nxsound_src} ${nxsound_inc})

target_link_libraries(nxsound ${OPENAL_LIBRARY})

set_target_properties(nxsound PROPERTIES 
					  		  DEFINE_SYMBOL NXDRAGON_BUILD_SOUND)

nx_filter("${nxsound_src};${nxsound_inc}")
