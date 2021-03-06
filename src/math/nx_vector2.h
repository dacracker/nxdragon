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

#ifndef __NXDRAGON_MATH_VECTOR2_H__
#define __NXDRAGON_MATH_VECTOR2_H__

#include "nx_def.h"
#include "../kernel/nx_types.h"

/** \ingroup NxMath
  * \defgroup nx_vector2 nx_vector2
  * \brief 2d vector without direction
  *
  * TODO 
  * @{
  */

typedef struct nx_vector2_t {
    nxreal x, /** x-component */
           y; /** y-component */
} nx_vector2;

/** Initializes the vector to (0,0). */
NX_MATH_API void nx_vector2_init(nx_vector2 *self);

/** Assigns the vector to (x,y). */
NX_MATH_API void nx_vector2_assign(nx_vector2 *self, nxreal x, nxreal y);

/** Assigns the vector the value of another vector. */
NX_MATH_API void nx_vector2_assign_vector(nx_vector2 *self, nx_vector2 *other);

/** Messures the distance between 2 vectors. */
NX_MATH_API nxreal nx_vector2_distance_to(nx_vector2 *self, nx_vector2 *other);

/** Translates a vector to another vector. */
NX_MATH_API void nx_vector2_translate(nx_vector2 *self, nx_vector2 *other);

/** Swaps the position of one vector with another. Both vectors will change value with each other. */
NX_MATH_API void nx_vector2_swap(nx_vector2 *self, nx_vector2 *other);

/** Converts this vector to its absoulute value. */
NX_MATH_API void nx_vector2_abs(nx_vector2 *self);

/** @} @} */
#endif
