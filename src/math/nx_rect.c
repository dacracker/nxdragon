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
	nx_point_init(&self->start);
	nx_point_init(&self->end);
}

/*************************************************************/
void nx_rect_assign(nx_rect *self, 
					nxint32 start_x,
					nxint32 start_y,
					nxint32 end_x,
					nxint32 end_y)
{
	nx_point_assign(&self->start, start_x, start_y);
	nx_point_assign(&self->end, end_x, end_y);
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
	nx_rect_assign_points(self, &other->start, &other->end);
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
	nxint32 min_x, max_x, min_y, max_y;

	min_x = nx_min(self->start.x, self->end.x);
	max_x = nx_max(self->start.x, self->end.x);
	min_y = nx_min(self->start.y, self->end.y);
	max_y = nx_max(self->start.y, self->end.y);

	return (point->x >= min_x &&
		    point->x <= max_x &&
		    point->y >= min_y &&
		    point->y <= max_y);
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
	nx_point_translate(&self->start, point);
	nx_point_translate(&self->end, point);
}

/*************************************************************/
nxint32 nx_rect_width(nx_rect *self)
{
	if(self->start.x > self->end.x)
		return (self->start.x - self->end.x);

	return (self->end.x - self->start.x);
}

/*************************************************************/
nxint32 nx_rect_height(nx_rect *self)
{
	if(self->start.y > self->end.y)
		return (self->start.y - self->end.y);

	return (self->end.y - self->start.y);
}

/*************************************************************/
void nx_rect_top_left(nx_rect *self, nx_point *point_out)
{
	nx_point_assign_point(point_out, &self->start);
}

/*************************************************************/
void nx_rect_top_right(nx_rect *self, nx_point *point_out)
{
	nx_point_assign(point_out, self->end.x, self->start.y);
}

/*************************************************************/
void nx_rect_bottom_left(nx_rect *self, nx_point *point_out)
{
	nx_point_assign(point_out, self->start.x, self->end.y);
}

/*************************************************************/
void nx_rect_bottom_right(nx_rect *self, nx_point *point_out)
{
	nx_point_assign_point(point_out, &self->end);
}
