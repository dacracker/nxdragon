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

#include "test_ray2.h"

#include "utest/nx_utest.h"
#include "math/nx_ray2.h"
#include "math/nx_point.h"

/*************************************************************/
void test_ray2_init(void *status)
{
	nx_ray2 ray;
	nx_ray2_init(&ray);

	nx_assert_equal(ray.direction.x, 0);
	nx_assert_equal(ray.direction.y, 0);

	nx_assert_equal(ray.origin.x, 0);
	nx_assert_equal(ray.origin.y, 0);
}

/*************************************************************/
void test_ray2_origin(void *status)
{
	nx_ray2 ray;
	nx_point point;
	const nx_point *dir;
	nx_point_assign(&point, 2,3);

	nx_ray2_assign(&ray, &point, &point);

	dir = nx_ray2_direction(&ray);

	nx_assert_equal(dir->x, 2);
	nx_assert_equal(dir->y, 3);

	nx_point_assign(&point, 5,4);

	nx_ray2_set_direction(&ray, &point);

	dir = nx_ray2_direction(&ray);

	nx_assert_equal(dir->x, 5);
	nx_assert_equal(dir->y, 4);
}

/*************************************************************/
void test_ray2_direction(void *status)
{
	nx_ray2 ray;
	nx_point point;
	const nx_point *org;
	nx_point_assign(&point, 2,3);

	nx_ray2_assign(&ray, &point, &point);

	org = nx_ray2_origin(&ray);

	nx_assert_equal(org->x, 2);
	nx_assert_equal(org->y, 3);

	nx_point_assign(&point, 5,4);

	nx_ray2_set_origin(&ray, &point);

	org = nx_ray2_origin(&ray);

	nx_assert_equal(org->x, 5);
	nx_assert_equal(org->y, 4);
}

/*************************************************************/
void test_ray2_intersects(void *status)
{
	nx_ray2 ray;
	nx_point origin, direction;
	nx_point figure[4];

	nx_point_assign(&origin, 1,1);
	nx_point_assign(&direction, 2,2);
	nx_ray2_assign(&ray, &origin, &direction);

	nx_point_assign(&figure[0], 0,2);
	nx_point_assign(&figure[1], 4,2);
	nx_point_assign(&figure[2], 4,3);
	nx_point_assign(&figure[3], 0,3);

	nx_assert_equal(nx_ray2_intersects(&ray, figure, 4), nxtrue);

	nx_point_assign(&direction, 2,4);
	nx_ray2_assign(&ray, &origin, &direction);

	nx_assert_equal(nx_ray2_intersects(&ray, figure, 4), nxtrue);

	nx_point_assign(&direction, -1,2);
	nx_ray2_assign(&ray, &origin, &direction);

	nx_assert_equal(nx_ray2_intersects(&ray, figure, 4), nxfalse);

	nx_point_assign(&direction, 5,2);
	nx_ray2_assign(&ray, &origin, &direction);

	nx_assert_equal(nx_ray2_intersects(&ray, figure, 4), nxfalse);

	nx_point_assign(&direction, 5,3);
	nx_ray2_assign(&ray, &origin, &direction);

	nx_assert_equal(nx_ray2_intersects(&ray, figure, 4), nxtrue);

	nx_point_assign(&direction, 1,3);
	nx_ray2_assign(&ray, &origin, &direction);

	nx_assert_equal(nx_ray2_intersects(&ray, figure, 4), nxtrue);

	nx_point_assign(&direction, 0,1);
	nx_ray2_assign(&ray, &origin, &direction);

	nx_assert_equal(nx_ray2_intersects(&ray, figure, 4), nxfalse);
}
