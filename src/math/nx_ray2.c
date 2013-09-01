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
nxbool intersects(const nx_ray2 *self, nx_point *object)
{
	/* TODO */
	return nxfalse;
}

/*************************************************************/
nxbool intersection(const nx_ray2 *self, nx_point *point)
{
	/* TODO */
	return nxfalse;
}