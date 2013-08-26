/***************************************************************************\
  This file is part of the NxDragon Game Engine.

  Copyright 2013 Patrik Jeppsson, Ulf Johnsson
  
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

#ifndef __NXDRAGON_MATH_MATH_H__
#define __NXDRAGON_MATH_MATH_H__

#include "nx_def.h"
#include "nx_point.h"

#include "../kernel/nx_types.h"

#include <math.h>

#define nx_max(x,y) x > y ? x : y
#define nx_min(x,y) x < y ? x : y

#define nx_clip(x,min,max) x > max ? max : x < min ? min : x

/** Calculates the square-root of a double value. */
#define nx_sqrt(value) sqrt(value)

/** Calculates the square-root of a float value. */
#define nx_sqrtf(value) (nxreal)sqrt(value)

/** Calculates the square-root of an integer value. */
#define nx_sqrti(value) (nxint32)sqrt(value)

/** Calculates the value of 'base' raised to the power 'power' for doubles. */
#define nx_pow(base, power) pow(base, power)

/** Calculates the value of 'base' raised to the power 'power' for floats. */
#define nx_powf(base, power) (nxreal)pow(base, power)

/** Calculates the value of 'base' raised to the power 'power' for integers. */
#define nx_powi(base, power) (nxint32)pow(base, power)

/** Raises a value to the power of 2. */
#define nx_pow2(value) value*value

/** Computes cosine of a double value. */
#define nx_cos(value) cos(value)

/** Computes cosine of a float value. */
#define nx_cosf(value) (nxreal)cos(value)

/** Computes cosine of an integer value. */
#define nx_cosi(value) (nxint32)cos(value)

/** Computes sine of a double value. */
#define nx_sin(value) sin(value)

/** Computes sine of a float value. */
#define nx_sinf(value) (nxreal)sin(value)

/** Computes sine of an integer value. */
#define nx_sini(value) (nxint32)sin(value)

/** Computes tangent of a double value. */
#define nx_tan(value) tan(value)

/** Computes tangent of a float value. */
#define nx_tanf(value) (nxreal)tan(value)

/** Computes tangent of an integer value. */
#define nx_tani(value) (nxint32)tan(value)

#endif
