#ifndef __NXPY3BIND_DEF_H__
#define __NXPY3BIND_DEF_H__

#include "../kernel/nx_def.h"

#ifdef NXDRAGON_BUILD_PY3BIND 
#	define NX_PY3BIND_API NX_EXPORT
#else
#	define NX_PY3BIND_API NX_IMPORT
#endif

#endif
