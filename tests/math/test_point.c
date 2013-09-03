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

#include "test_point.h"
#include "utest/nx_utest.h"
#include "math/nx_point.h"
#include "math/nx_math.h"

/*************************************************************/
void test_point_init(void *status)
{
    nx_point point;
    nx_point_init(&point);

    nx_assert_equal(point.x, 0);
    nx_assert_equal(point.y, 0);
}

/*************************************************************/
void test_point_assign(void *status)
{
    nx_point point;
    nx_point_init(&point);

    nx_point_assign(&point, 5, -10);
    nx_assert_equal(point.x, 5);
    nx_assert_equal(point.y, -10);
}

/*************************************************************/
void test_point_assign_point(void *status)
{
    nx_point point, point2;
    nx_point_init(&point);
    nx_point_init(&point2);

    nx_point_assign(&point, 1, 1);
    nx_point_assign(&point2, 2, 2);

    nx_point_assign_point(&point, &point2);

    nx_assert_equal(point.x, 2);
    nx_assert_equal(point.y, 2);
    nx_assert_equal(point2.x, 2);
    nx_assert_equal(point2.y, 2);
}

/*************************************************************/
void test_point_distance_to(void *status)
{
    nx_point point, point2;
    nx_point_init(&point);
    nx_point_init(&point2);

    point.x = 4;
    point.y = 3;

    nx_assert_equal(nx_point_distance_to(&point, &point2), 5);
    nx_assert_equal(nx_point_distance_to(&point2, &point), 5);

    point2.x = 4;
    nx_assert_equal(nx_point_distance_to(&point, &point2), 3);
    nx_assert_equal(nx_point_distance_to(&point2, &point), 3);

    point2.y = 1;
    nx_assert_equal(nx_point_distance_to(&point, &point2), 2);
    nx_assert_equal(nx_point_distance_to(&point2, &point), 2);

    point2.y = -3;
    nx_assert_equal(nx_point_distance_to(&point, &point2), 6);
    nx_assert_equal(nx_point_distance_to(&point2, &point), 6);

    point2.x = 0;
    nx_assert_equal(nx_point_distance_to(&point, &point2), 7);
    nx_assert_equal(nx_point_distance_to(&point2, &point), 7);

    point2.x = -4;
    nx_assert_equal(nx_point_distance_to(&point, &point2), 10);
    nx_assert_equal(nx_point_distance_to(&point2, &point), 10);

    point2.y = 0;
    nx_assert_equal(nx_point_distance_to(&point, &point2), 8);
    nx_assert_equal(nx_point_distance_to(&point2, &point), 8);

    point2.y = 3;
    nx_assert_equal(nx_point_distance_to(&point, &point2), 8);
    nx_assert_equal(nx_point_distance_to(&point2, &point), 8);

    point2.x = 0;
    nx_assert_equal(nx_point_distance_to(&point, &point2), 4);
    nx_assert_equal(nx_point_distance_to(&point2, &point), 4);
}

/*************************************************************/
void test_point_translate(void *status)
{
    nx_point point, point2;
    nx_point_init(&point);
    nx_point_init(&point2);

    nx_point_assign(&point, 1, 1);
    nx_point_assign(&point2, 2, 2);
    nx_point_translate(&point, &point2);
    nx_assert_equal(point.x, 3);
    nx_assert_equal(point.y, 3);

    nx_point_assign(&point, 5, 3);
    nx_point_assign(&point2, -3, -1);
    nx_point_translate(&point, &point2);
    nx_assert_equal(point.x, 2);
    nx_assert_equal(point.y, 2);
}

/*************************************************************/
void test_point_swap(void *status)
{
    nx_point point, point2;
    nx_point_init(&point);
    nx_point_init(&point2);

    nx_point_assign(&point, 1, 1);
    nx_point_assign(&point2, 2, 2);
    nx_point_swap(&point, &point2);

    nx_assert_equal(point.x, 2);
    nx_assert_equal(point.y, 2);
    nx_assert_equal(point2.x, 1);
    nx_assert_equal(point2.y, 1);
}

/*************************************************************/
void test_point_abs(void *status)
{
	nx_point point;
    nx_point_init(&point);
	nx_point_assign(&point, -1, -2);

	nx_point_abs(&point);
	nx_assert_equal(point.x, 1);
	nx_assert_equal(point.y, 2);
	
	nx_point_assign(&point, 10, 12);

	nx_point_abs(&point);
	nx_assert_equal(point.x, 10);
	nx_assert_equal(point.y, 12);
}

/*************************************************************/
void test_angle_deg(void *status)
{
    nx_point p1,p2;
    nxint32 deg;

    nx_point_assign(&p1, 1,1);

    nx_point_assign(&p2, 2,1);
    /* deg == 0 */
    deg = angle_deg(&p1, &p2);
    nx_assert_equal(deg, 0);

    nx_point_assign(&p2, 4,3);
    /* deg ~ 33 */
    deg = angle_deg(&p1, &p2);
    nx_assert_equal(deg, 33);

    nx_point_assign(&p2, 2,2);
    /* deg ~ 45 */
    deg = angle_deg(&p1, &p2);
    nx_assert_equal(deg, 44);

    nx_point_assign(&p2, 1,2);
    /* deg == 90 */
    deg = angle_deg(&p1, &p2);
    nx_assert_int(deg, 90, 2);

    nx_point_assign(&p2, 0,2);
    /* deg == 135 */
    deg = angle_deg(&p1, &p2);
    nx_assert_int(deg, 135, 2);

    nx_point_assign(&p2, 0,1);
    /* deg == 180 */
    deg = angle_deg(&p1, &p2);
    nx_assert_int(deg, 180, 2);

    nx_point_assign(&p2, 0,0);
    /* deg == 225 */
    deg = angle_deg(&p1, &p2);
    nx_assert_int(deg, 225, 2);

    nx_point_assign(&p2, 1,0);
    /* deg == 270 */
    deg = angle_deg(&p1, &p2);
    nx_assert_int(deg, 270, 2);

    nx_point_assign(&p2, 2,0);
    /* deg == 315 */
    deg = angle_deg(&p1, &p2);
    nx_assert_equal(deg, 315);
}
