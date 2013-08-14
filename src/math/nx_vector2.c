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

#include "nx_vector2.h"
#include "nx_math.h"

/*************************************************************/
void nx_vector2_init(nx_vector2 *self)
{
    self->x = 0.0f;
    self->y = 0.0f;
}

/*************************************************************/
void nx_vector2_assign(nx_vector2 *self, nxreal x, nxreal y)
{
    self->x = x;
    self->y = y;
}

/*************************************************************/
void nx_vector2_assign_vector(nx_vector2 *self, nx_vector2 *other)
{
    self->x = other->x;
    self->y = other->y;
}

/*************************************************************/
nxreal nx_vector2_distance_to(nx_vector2 *self, nx_vector2 *other)
{
    nxreal dx = self->x - other->x;
    nxreal dy = self->y - other->y;

    return nx_sqrtf(nx_powf(dx, 2.0f) + nx_powf(dy, 2.0f));
}

/*************************************************************/
void nx_vector2_translate(nx_vector2 *self, nx_vector2 *other)
{
    self->x += other->x;
    self->y += other->y;
}

/*************************************************************/
void nx_vector2_swap(nx_vector2 *self, nx_vector2 *other)
{
    nxreal temp;

    temp = self->x;
    self->x = other->x;
    other->x = temp;

    temp = self->y;
    self->y = other->y;
    other->y = temp;
}
