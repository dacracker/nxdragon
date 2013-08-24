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

#ifndef __NXDRAGON_MATH_RECT_H__
#define __NXDRAGON_MATH_RECT_H__

#include "nx_def.h"
#include "nx_point.h"
#include "../kernel/nx_types.h"
#include "../kernel/nx_bool.h"

/** \ingroup NxMath
  * \defgroup nx_rect nx_rect
  * \brief A rectangle representation.
  *
  * TODO 
  * @{
  */

typedef struct nx_rect_t {
    nx_point points[4];
} nx_rect;

/** Initializes the rectangle to 0. */
NX_MATH_API void nx_rect_init(nx_rect *self);

/** Assigns the rectangle the given values. */
NX_MATH_API void nx_rect_assign(nx_rect *self, 
								nxint32 start_x,
								nxint32 start_y,
								nxint32 end_x,
								nxint32 end_y);

/** Assigns the rectangle values based on the given points. */
NX_MATH_API void nx_rect_assign_points(nx_rect *self, 
									   nx_point *start_point,
									   nx_point *end_point);

/** Assigns the rectangle the same values as the other given rectangle. */
NX_MATH_API void nx_rect_assign_rect(nx_rect *self, nx_rect *other);

/** Returns nxtrue if the given coordinate is contained within the rectangle. */
NX_MATH_API nxbool nx_rect_contains(nx_rect *self, nxint32 x, nxint32 y);

/** @} @} */
#endif
