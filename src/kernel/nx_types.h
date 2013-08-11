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
