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

#include "nx_ray2.h"

#include "nx_math.h"

#include "../kernel/nx_def.h"

/*************************************************************/
void nx_ray2_init(nx_ray2 *self)
{
    nx_point_init(&self->origin);
    nx_point_init(&self->direction);
}

/*************************************************************/
void nx_ray2_assign(nx_ray2 *self, const nx_point *origin, const nx_point *direction)
{
    nx_point_assign_point(&self->origin, origin);
    nx_point_assign_point(&self->direction, direction);
}

/*************************************************************/
void nx_ray2_set_direction(nx_ray2 *self, const nx_point *direction)
{
	nx_point_assign_point(&self->direction, direction);
}

/*************************************************************/
void nx_ray2_set_origin(nx_ray2 *self, const nx_point *origin)
{
	nx_point_assign_point(&self->origin, origin);
}

/*************************************************************/
const nx_point* nx_ray2_direction(const nx_ray2 *self)
{
	return &self->direction;
}

/*************************************************************/
const nx_point* nx_ray2_origin(const nx_ray2 *self)
{
	return &self->origin;
}

/*************************************************************/
nxbool nx_ray2_intersects(const nx_ray2 *self, 
                          const nx_point *object, 
                          const int count)
{
    nxreal selfAngle, angle1, angle2;
    const nx_point *p1, *p2;
    nxint32 index;

    /* sanity check */
    if(count < 2)
        return nxfalse;

    selfAngle = nx_angle_rad(&self->origin, &self->direction);
    
    p1 = &object[count-1];
    angle1 = nx_angle_rad(&self->origin, p1);
    
    for(index = 0; index < count; ++index)
    {
        p2 = &object[index];
        angle2 = nx_angle_rad(&self->origin, p2);

        if(nx_in_range(selfAngle, (nx_min(angle1, angle2)), (nx_max(angle1, angle2))))
            return nxtrue;

        p1 = p2;
        angle1 = angle2;
    }
    

    return nxfalse;
}

/*************************************************************/
nxbool nx_ray2_intersection(const nx_ray2 *self, 
                            const nx_point *object, 
                            const int count,
                            nx_point *point)
{
    /* TODO */
    NX_UNUSED(self);
    NX_UNUSED(object);
    NX_UNUSED(count);
    NX_UNUSED(point);

    return nxfalse;
}

/*************************************************************/
void nx_ray2_extend(const nx_ray2 *self, const nxint32 units, nx_point *result)
{
	nxreal angle;
	nxint32 adjacent, opposite;

	/* x-axis parallel */
	if(self->origin.y == self->direction.y)
	{
		result->y = self->origin.y;
		result->x = (self->origin.x < self->direction.x) ? self->origin.x + units :
														   self->origin.x - units;

		return;
	}
	
	/* y-axis parallel */
	if(self->origin.x == self->direction.x)
	{
		result->x = self->origin.x;
		result->y = (self->origin.y < self->direction.y) ? self->origin.y + units :
														   self->origin.y - units;
		return;
	}
	
	/*	sin(d) = Opposite / Hypotenuse
		cos(d) = Adjacent / Hypotenuse
		tan(d) = Opposite / Adjacent */
	angle = nx_angle_rad(&self->origin, &self->direction);
	opposite = (nxint32)(nx_sinf(angle) * units);
	adjacent = (nxint32)(nx_cosf(angle) * units);

	result->x = self->origin.x + adjacent;
	result->y = self->origin.y + opposite;
}

/*************************************************************/
void nx_ray2_translate(nx_ray2 *self, const nx_point *point)
{
	nx_point_translate(&self->origin, point);
	nx_point_translate(&self->direction, point);
}
