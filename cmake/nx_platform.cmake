# Detect the current platform
# TODO: Check if this is the correct way to do it..

if(CMAKE_HOST_UNIX)
	if(CMAKE_HOST_APPLE)
	  set(NX_PLATFORM_MACOSX 1)
	else()
	  set(NX_PLATFORM_UNIX 1)
	endif()
endif()

if(CMAKE_HOST_WIN32)
	set(NX_PLATFORM_WIN32 1)
	
	# Always use Warning level 4 when using Visual Studio
	if(MSVC)
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
		set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /ZI")
		add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	endif()
endif()

if(CMAKE_COMPILER_IS_GNUCC)
	set(CMAKE_C_FLAGS "-Wall -pedantic -std=c99 -finline-small-functions -Wunused-function ${CMAKE_C_FLAGS}")
endif()
