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

#ifndef __NXDRAGON_MATH_MATH_H__
#define __NXDRAGON_MATH_MATH_H__

#include "nx_def.h"
#include "../kernel/nx_types.h"

#define nx_max(x,y) x > y ? x : y
#define nx_min(x,y) x < y ? x : y

#define nx_clip(x,min,max) x > max ? max : x < min ? min : x

/** Calculates the square-root of an integer value. */
NX_MATH_API nxint32 nx_sqrt(nxint32 value);

/** Calculates the square-root of a float value. */
NX_MATH_API nxreal nx_sqrtf(nxreal value);

/** Calculates the value of 'base' raised to the power 'power' for integers. */
NX_MATH_API nxint32 nx_pow(nxint32 base, nxint32 power);

/** Calculates the value of 'base' raised to the power 'power' for floats. */
NX_MATH_API nxreal nx_powf(nxreal base, nxreal power);

#endif
