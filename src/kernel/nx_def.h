/*
  NxDragon Game Engine

  Author: Patrik Jeppsson <dacrackerx64@gmail.com>

  License: This source code is proprietary and may not
       be used without permission from the author. 
*/

#ifndef __NXDRAGON_KERNEL_DEF_H__
#define __NXDRAGON_KERNEL_DEF_H__

#include "nx_platform.h"

#ifdef NXDRAGON_BUILD_KERNEL
#	define NX_KERNEL_API NX_EXPORT
#else
#	define NX_KERNEL_API NX_IMPORT
#endif

/* Use to supress "unused variable" compiler warnings */
#define NX_UNUSED(x) (void)x;

/* 
   Functions, structs etc that are marked with this macro may 
   NOT be called from client code
*/
#define NX_INTERNAL 

#endif
