/***************************************************************************\
  This file is part of the NxDragon Game Engine.

  Copyright 2013 Patrik Jeppsson
  
  NxDragon is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  NxDragon is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with NxDragon. If not, see <http://www.gnu.org/licenses/>.
\***************************************************************************/

#ifndef __NXDRAGON_KERNEL_PLATFORM_H__
#define __NXDRAGON_KERNEL_PLATFORM_H__

/*
	Platform macros
	
	Windows: NX_OS_WIN32
	Windows 64-bit: NX_OS_WIN64
	
	Linux: NX_OS_LINUX
	Linux 64-bit: NX_OS_LINUX64

	Mac OS X: NX_OS_MACX
	Mac OS X 64-bit: NX_OS_MACX64

	FreeBSD: NX_OS_FREEBSD
	FreeBSD 64-bit: NX_OS_FREEBSD64
*/

/* Dection of Microsoft Windows */
#if(defined(_WIN32) || defined(_WINDOWS))
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

/* Detection of Apple OS X */
#if defined(__APPLE__)
#	define NX_OS_MACX
#	ifdef __LP64__
#		define NX_OS_MACX64
#	endif
#endif

/* Detection of FreeBSD */
#if defined(__FreeBSD__)
#	define NX_OS_FREEBSD
#	ifdef __x86_64__
#		define NX_OS_FREEBSD64
#	endif
#endif

#if defined(NX_OS_WIN64) || defined(NX_OS_LINUX64) || defined(NX_OS_MACX64) || defined(NX_OS_FREEBSD64)
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
