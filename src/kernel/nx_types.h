/*
	NxDragon Game Engine

	Author: Patrik Jeppsson <dacrackerx64@gmail.com>

	License: This source code is proprietary and may not
			 be used without permission from the author. 
*/

#ifndef __NXDRAGON_KERNEL_TYPES_H__
#define __NXDRAGON_KERNEL_TYPES_H__

#include "nx_compiler.h"
#include "nx_bool.h"

/* 8-bit integer types */
typedef char nxint8;
typedef unsigned char nxuint8;

/* 16-bit integer types */
typedef short nxint16;
typedef unsigned short nxuint16;

/* 32-bit integer types */
typedef int nxint32;
typedef unsigned int nxuint32;

/* 64-bit integer types */
#ifdef NX_CC_MSVC
	typedef __int64 nxint64;
	typedef unsigned __int64 nxuint64;
#else
	typedef long long exint64;
	typedef unsigned long long nxuint64;
#endif

/* floating point types */
typedef float nxreal;

/* Generic type to represent OS-specific handles to e.g threads */
typedef void* nxhandle; 

#endif
