/*
	NxDragon Game Engine

	Author: Patrik Jeppsson <dacrackerx64@gmail.com>

	License: This source code is proprietary and may not
			 be used without permission from the author. 
*/

#ifndef __NEXUS_KERNEL_PLATFORM_H__
#define __NEXUS_KERNEL_PLATFORM_H__

/*
	Platform macros
	
	Windows: NX_OS_WIN32
	Windows 64-bit: NX_OS_WIN64
	
	Linux: NX_OS_LINUX
	Linux 64-bit: NX_OS_LINUX64

	Mac OS X: NX_OS_MACX
	Mac OS X 64-bit: NX_OS_MACX64

*/

/* Dection of Microsoft Windows */
#if(defined(WIN32) || defined(_WINDOWS))
#	define NX_OS_WIN32 
#	if (defined(_WIN64) || defined(_M_X64))
#		define NX_OS_WIN64
#	endif
#endif

/* Detection of GNU/Linux */
#if(defined(__linux) || defined(__linux__))
#	define NX_OS_LINUX
#	ifdef __x86_64__
#		define NX_OS_LINUX64
#	endif
#endif

/* Detection of Apple Mac OS X */
#if defined(__APPLE__)
#	define NX_OS_MACX
#	ifdef __LP64__
#		define NX_OS_MACX64
#	endif
#endif

#if defined(NX_OS_WIN64) || defined(NX_OS_LINUX64) || defined(NX_OS_MACX64)
#	define NX_OS_ARCH64
#else
#	define NX_OS_ARCH32
#endif

#if defined(NX_OS_ARCH64)
#		define NX_POINTER_SIZE 8
#	else
#		define NX_POINTER_SIZE 4
#endif

/* Library defines for exporting symbols (needed for Windows) */
#ifdef NX_OS_WIN32
#	define NX_EXPORT __declspec(dllexport)
#	define NX_IMPORT __declspec(dllimport)
#else
#	define NX_EXPORT
#	define NX_IMPORT
#endif

#endif
