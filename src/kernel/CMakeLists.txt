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
	nx_queue.h
	nx_doc.h
	nx_timer.h
	nx_event.h
	nx_event_source.h
	nx_event_queue.h
	nx_mutex.h
	nx_memory.h
	nx_library.h
	nx_thread.h)
			    
set(nxkernel_src 
	nx_linkedlist.c
	nx_list.c
	nx_queue.c
	nx_event.c
	nx_event_source.c
	nx_event_queue.c)

if(NX_PLATFORM_WIN32)
	set(nxkernel_platform_src 
		nx_atomic_win32.c
		nx_timer_win32.c
		nx_mutex_win32.c
		nx_library_win32.c
		nx_thread_win32.c)
endif()

if(NX_PLATFORM_MACOSX)
	set(nxkernel_platform_src 
		nx_atomic_osx.c
        nx_timer_unix.c
    	nx_mutex_unix.c
    	nx_library_unix.c)
endif()

if(NX_PLATFORM_UNIX)
	set(nxkernel_platform_src 
		nx_atomic_unix.c
		nx_timer_unix.c
		nx_mutex_unix.c
		nx_library_unix.c)
endif()

set(nxkernel_src 
	${nxkernel_src}
	${nxkernel_platform_src})
			   
add_library(nxkernel SHARED 
			${nxkernel_src}
			${nxkernel_inc})

set_target_properties(nxkernel PROPERTIES 
					  		   DEFINE_SYMBOL NXDRAGON_BUILD_KERNEL)

if(NX_PLATFORM_MACOSX)
	target_link_libraries(nxkernel pthread)
endif()

if(NX_PLATFORM_UNIX)
	add_definitions(-D_GNU_SOURCE)
	target_link_libraries(nxkernel rt pthread dl)
endif()

nx_filter("${nxkernel_src};${nxkernel_inc}")
