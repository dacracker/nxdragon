cmake_minimum_required(VERSION 2.8)

# This is needed to find our configuration file
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(nxkernel_inc 
	nx_def.h
	nx_compiler.h
	nx_platform.h
	nx_bool.h
	nx_atomic.h
	nx_types.h
	nx_linkedlist.h
	nx_list.h
	nx_doc.h)
			    
set(nxkernel_src 
	nx_linkedlist.c
	nx_list.c)

if(NX_PLATFORM_WIN32)
	set(nxkernel_platform_src 
		nx_atomic_win32.c)
endif()

if(NX_PLATFORM_MACOSX)
	set(nxkernel_platform_src 
		nx_atomic_osx.c)
endif()

if(NX_PLATFORM_UNIX)
	set(nxkernel_platform_src 
		nx_atomic_unix.c)
endif()

set(nxkernel_src 
	${nxkernel_src}
	${nxkernel_platform_src})
			   
add_library(nxkernel SHARED 
			${nxkernel_src}
			${nxkernel_inc})

set_target_properties(nxkernel PROPERTIES 
					  		   DEFINE_SYMBOL NXDRAGON_BUILD_KERNEL)

nx_filter("${nxkernel_src};${nxkernel_inc}")
