# Detect the current platform
# TODO: Check if this is the correct way to do it..

# Detect compiler 
if(MSVC)
	set(NX_CC_MSVC 1)
endif()

if(CMAKE_COMPILER_IS_GNUCC)
	set(NX_CC_GCC 1)
endif()


if(CMAKE_HOST_UNIX)
	if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	  set(NX_PLATFORM_MACOSX 1)
	else()
	  set(NX_PLATFORM_UNIX 1)

	  if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	  	set(NX_PLATFORM_LINUX 1)
	  elseif(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
	  	set(NX_PLATFORM_FREEBSD 1)
	  endif()
	endif()
endif()

if(CMAKE_HOST_WIN32)
	set(NX_PLATFORM_WIN32 1)
	
	# Always use Warning level 4 when using Visual Studio
	if(NX_CC_MSVC)
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
		set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /ZI")
		add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	endif()
endif()

if(NX_CC_GCC)
	set(CMAKE_C_FLAGS "-Wall -pedantic -std=c90 -Wno-long-long -finline-small-functions -Wunused-function ${CMAKE_C_FLAGS}")
endif()
