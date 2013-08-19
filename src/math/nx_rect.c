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
	nx_point_assign_point(&self->end, start_point);
	nx_point_assign_point(&self->end, end_point);
}

/*************************************************************/
void nx_rect_assign_rect(nx_rect *self, nx_rect *other)
{
	nx_rect_assign_points(self, &other->start, &other->end);
}

/*************************************************************/
nxint32 nx_rect_start_x(nx_rect *self)
{
	return self->start.x;
}

/*************************************************************/
nxint32 nx_rect_start_y(nx_rect *self)
{
	return self->start.y;
}

/*************************************************************/
nxint32 nx_rect_end_x(nx_rect *self)
{
	return self->end.x;
}

/*************************************************************/
nxint32 nx_rect_end_y(nx_rect *self)
{
	return self->end.y;
}

/*************************************************************/
void nx_rect_contains(nx_rect *self, nx_point *point)
{
	// TODO: implement
}