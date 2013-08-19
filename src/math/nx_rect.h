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

/** \ingroup NxMath
  * \defgroup nx_rect nx_rect
  * \brief A rectangle representation.
  *
  * TODO 
  * @{
  */

typedef struct nx_rect_t {
    nx_point start, /** start-posistion of the rect */
			 end; /** end position of the rect */
} nx_rect;

/**  */
NX_MATH_API void nx_rect_init(nx_rect *self);

/**  */
NX_MATH_API void nx_rect_assign(nx_rect *self, 
								nxint32 start_x,
								nxint32 start_y,
								nxint32 end_x,
								nxint32 end_y);

/**  */
NX_MATH_API void nx_rect_assign_points(nx_rect *self, 
									   nx_point *start_point,
									   nx_point *end_point);

/**  */
NX_MATH_API void nx_rect_assign_rect(nx_rect *self, nx_rect *other);

/** Returns the start points x-coordinate. */
NX_MATH_API nxint32 nx_rect_start_x(nx_rect *self);

/** Returns the start points y-coordinate. */
NX_MATH_API nxint32 nx_rect_start_y(nx_rect *self);

/** Returns the end points x-coordinate. */
NX_MATH_API nxint32 nx_rect_end_x(nx_rect *self);

/** Returns the end points y-coordinate. */
NX_MATH_API nxint32 nx_rect_end_y(nx_rect *self);

/**  */
NX_MATH_API void nx_rect_contains(nx_rect *self, nx_point *point);

/** @} @} */
#endif
