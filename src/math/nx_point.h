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

#ifndef __NXDRAGON_MATH_POINT_H__
#define __NXDRAGON_MATH_POINT_H__

#include "nx_def.h"
#include "../kernel/nx_types.h"

/** \ingroup NxMath
  * \defgroup nx_point nx_point
  * \brief A 2d point.
  *
  * TODO 
  * @{
  */

typedef struct nx_point_t {
    nxint32 x, /** x-component */
            y; /** y-component */
} nx_point;

/** Initializes the point to (0,0). */
NX_MATH_API void nx_point_init(nx_point *self);

/** Assigns the point to (x,y). */
NX_MATH_API void nx_point_assign(nx_point *self, nxint32 x, nxint32 y);

/** Assigns the point the value of another point. */
NX_MATH_API void nx_point_assign_point(nx_point *self, nx_point *other);

/** Messures the distance between two points. */
NX_MATH_API nxint32 nx_point_distance_to(nx_point *self, nx_point *other);

/** Translates a point to another point. */
NX_MATH_API void nx_point_translate(nx_point *self, nx_point *other);

/** Swaps the position of one point with another. Both points will change value with each other. */
NX_MATH_API void nx_point_swap(nx_point *self, nx_point *other);

/** Converts this point to its absoulute value. */
NX_MATH_API void nx_point_abs(nx_point *self);

/** @} @} */
#endif
