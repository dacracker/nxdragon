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

#include "../kernel/nx_bool.h"

/** \ingroup NxMath
  * \defgroup nx_ray2 nx_ray2
  * \brief A 2d ray.
  *
  * TODO
  * @{
  */

typedef struct nx_ray2_t {
    nx_point origin,
             direction;
} nx_ray2;

/** Initializes the ray. */
NX_MATH_API void nx_ray2_init(nx_ray2 *self);

/** Initializes the ray. */
NX_MATH_API void nx_ray2_assign(nx_ray2 *self, 
                                const nx_point *origin, 
                                const nx_point *direction);

/** Sets the direction. */
NX_MATH_API void nx_ray2_set_direction(nx_ray2 *self, const nx_point *direction);

/** Sets the origin. */
NX_MATH_API void nx_ray2_set_origin(nx_ray2 *self, const nx_point *origin);

/** Returns the rays direction. */
NX_MATH_API const nx_point* nx_ray2_direction(const nx_ray2 *self);

/** Returns the rays origin. */
NX_MATH_API const nx_point* nx_ray2_origin(const nx_ray2 *self);

/** Returns nxtrue if any of the sides created by the points in object is intersected. */
NX_MATH_API nxbool nx_ray2_intersects(const nx_ray2 *self, 
                                      const nx_point *object, 
                                      const int count);

/** Returns nxtrue if there is an intersection, in that case 'point' will be assigned the intersection value. */
NX_MATH_API nxbool nx_ray2_intersection(const nx_ray2 *self, 
                                        const nx_point *object, 
                                        const int count, 
                                        nx_point *point);

/** Extends the ray by given units and sets the resulting position in 'result'. */
NX_MATH_API void nx_ray2_extend(const nx_ray2 *self,
							    const nxint32 units,
							    nx_point *result);

/** Translates the ray to given position. */
NX_MATH_API void nx_ray2_translate(nx_ray2 *self,
							       const nx_point *point);

/** @} @} */
#endif
