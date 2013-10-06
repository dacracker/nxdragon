cmake_minimum_required(VERSION 2.8)

# This is needed to find our configuration file
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(nxgui_inc 
	nx_init.h
	nx_def.h
	nx_doc.h
	nx_window.h
	nx_window_events.h)
			    
set(nxgui_src nx_window_events.c)

if(NX_PLATFORM_WIN32)
	set(nxgui_platform_src 
		nx_window_win32.c
		nx_init_win32.c)
endif()

if(NX_PLATFORM_UNIX)
	set(nxgui_platform_src
		nx_window_unix.c
		nx_init_unix.c)
endif()

set(nxgui_src 
	${nxgui_src}
	${nxgui_platform_src})
			   
add_library(nxgui SHARED 
			${nxgui_src}
			${nxgui_inc})

if(NX_PLATFORM_UNIX)
	find_package(X11 REQUIRED) 
        target_link_libraries(nxgui ${X11_LIBRARIES})
endif()

set_target_properties(nxgui PROPERTIES 
					  		DEFINE_SYMBOL NXDRAGON_BUILD_GUI)

target_link_libraries(nxgui nxkernel)

nx_filter("${nxgui_src};${nxgui_inc}")
