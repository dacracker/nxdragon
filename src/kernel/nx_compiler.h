/*
    NxDragon Game Engine

    Author: Patrik Jeppsson <dacrackerx64@gmail.com>

    License: This source code is proprietary and may not
             be used without permission from the author. 
*/

#ifndef __NXDRAGON_KERNEL_COMPILER_H__
#define __NXDRAGON_KERNEL_COMPILER_H__

/* Compiler macros */
#ifdef _MSC_VER /* Using Microsoft Visual C++ */
#	define NX_CC_MSVC
#endif

/* Using GNU GCC or Mingw? */
#ifdef __GNUC__ 
#	define NX_CC_GNU
#endif

/* Using clang? */
#ifdef __clang__
#	define NX_CC_CLANG
#endif

/* Is C90 supported by this compiler? */
#if defined(__STDC_VERSION__)
#	define NX_STD_C90
	/* Is C99 supported by this compiler? */
#	if(__STDC_VERSION__ >= 199901L)
#		define NX_STD_C99
#	    define NX_INLINE static inline /* A modern compiler should support inline properly */    
#		if(__STDC_VERSION__ >= 201112L)
#			define NX_STD_C11	/* This compiler supports C11, fancy! */
#		endif
#	else
#		define NX_INLINE static /* inline isn't a keyword in pre-C99 standards */	
#	endif
#else
#	define NX_INLINE static /* inline isn't a keyword in pre-C99 standards */
#endif

/* Detect if the compiler supports C++ */
#ifdef __cplusplus
#	define NX_STD_CPP
#endif

#endif
