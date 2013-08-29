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

/** @} @} */
#endif
