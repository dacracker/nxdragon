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

#include "nx_rect.h"
#include "nx_math.h"

/*************************************************************/
void nx_rect_init(nx_rect *self)
{
	nx_point_init(&self->points[0]);
	nx_point_init(&self->points[1]);
	nx_point_init(&self->points[2]);
	nx_point_init(&self->points[3]);
}

/*************************************************************/
void nx_rect_assign(nx_rect *self, 
					nxint32 start_x,
					nxint32 start_y,
					nxint32 end_x,
					nxint32 end_y)
{
	nx_point_assign(&self->points[0], start_x, start_y);
	nx_point_assign(&self->points[2], end_x, end_y);

	nx_point_assign(&self->points[1], start_x, end_y);
	nx_point_assign(&self->points[3], end_x, start_y);
}

/*************************************************************/
void nx_rect_assign_points(nx_rect *self, 
						   nx_point *start_point,
						   nx_point *end_point)
{
	nx_rect_assign(self, start_point->x, start_point->y, end_point->x, end_point->y);
}

/*************************************************************/
void nx_rect_assign_rect(nx_rect *self, nx_rect *other)
{
	nx_rect_assign_points(self, &other->points[0], &other->points[2]);
}

/*************************************************************/
nxbool nx_rect_contains(nx_rect *self, nxint32 x, nxint32 y)
{
	nx_point point;
	nx_point_assign(&point, x, y);

	return nx_rect_contains_point(self, &point);
}

/*************************************************************/
nxbool nx_rect_contains_point(nx_rect *self, nx_point *point)
{
    return nx_contains(self->points, 4, point);
}

/*************************************************************/
nxbool nx_rect_intersects(nx_rect *self, nx_rect *other)
{
	/* TODO: implement */
    return nxfalse;
}

/*************************************************************/
void nx_rect_translate(nx_rect *self, nxint32 x, nxint32 y)
{
	nx_point point;
	nx_point_assign(&point, x, y);

	nx_rect_translate_point(self, &point);
}

/*************************************************************/
void nx_rect_translate_point(nx_rect *self, nx_point *point)
{
	int index;
	for(index = 0; index < 4; ++index)
		nx_point_translate(&self->points[index], point);
}
