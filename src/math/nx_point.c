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

#include "nx_point.h"
#include "nx_math.h"

/*************************************************************/
void nx_point_init(nx_point *self)
{
    self->x = 0;
    self->y = 0;
}

/*************************************************************/
void nx_point_assign(nx_point *self, nxint32 x, nxint32 y)
{
    self->x = x;
    self->y = y;
}

/*************************************************************/
void nx_point_assign_point(nx_point *self, const nx_point *other)
{
    self->x = other->x;
    self->y = other->y;
}

/*************************************************************/
nxint32 nx_point_distance_to(nx_point *self, const nx_point *other)
{
    nxint32 dx = self->x - other->x;
    nxint32 dy = self->y - other->y;

    return nx_sqrti(nx_pow2(dx) + nx_pow2(dy));
}

/*************************************************************/
void nx_point_translate(nx_point *self, const nx_point *other)
{
    self->x += other->x;
    self->y += other->y;
}

/*************************************************************/
void nx_point_swap(nx_point *self, nx_point *other)
{
    nxint32 temp_x, temp_y;

    temp_x = self->x;
    self->x = other->x;
    other->x = temp_x;

    temp_y = self->y;
    self->y = other->y;
    other->y = temp_y;
}

/*************************************************************/
void nx_point_abs(nx_point *self)
{
	/* TODO: maybe this can be optimized with something like:
	         if(((int)self->x >> (sizeof(nxint32)*8 - 1)) & 1)
			 It seems to work for most values, but I don't think
			 it handles overflows correctly :/
	*/
	if(self->x < 0)
		self->x = -self->x;

	if(self->y < 0)
		self->y = -self->y;
}

/*************************************************************/
nxbool nx_contains(nx_point *points, nxint32 count, nx_point *point)
{
  int index1, index2, result = 0;
  nx_point *p1, *p2;

  /* sanity check */
  if(count < 3)
    return nxfalse;

  for (index1 = 0, index2 = count - 1; index1 < count; index2 = index1++)
  {
    p1 = points + index1;
    p2 = points + index2;
    if(((p1->y > point->y) != (p2->y > point->y)) &&
      (point->x < (p2->x - p1->x) * (point->y - p1->y) / (p2->y - p1->y) + p1->x))
      result = !result;
  }

  return result ? nxtrue : nxfalse;
}
