#ifndef __NXDRAGON_MATH_MATH_H__
#define __NXDRAGON_MATH_MATH_H__

#include <math.h>

#define nx_max(x,y) x > y ? x : y
#define nx_min(x,y) x < y ? x : y

#define nx_clip(x,min,max) x > max ? max : x < min ? min : x

#endif
