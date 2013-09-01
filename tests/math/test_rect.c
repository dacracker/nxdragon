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

#include "test_rect.h"
#include "utest/nx_utest.h"
#include "math/nx_rect.h"
#include "math/nx_point.h"

/*************************************************************/
void test_rect_init(void *status)
{
	nx_rect *rect = (nx_rect*)malloc(sizeof(nx_rect));
	nx_rect_init(rect);

	nx_assert_equal(rect->start.x, 0);
	nx_assert_equal(rect->start.y, 0);

	nx_assert_equal(rect->end.x, 0);
	nx_assert_equal(rect->end.y, 0);

	free(rect);
}

/*************************************************************/
void test_rect_contains(void *status)
{
	nx_rect rect;
	nx_rect_init(&rect);
	nx_rect_assign(&rect, 2,2,5,5);

	nx_assert_equal(nx_rect_contains(&rect, 0, 0), nxfalse);
	nx_assert_equal(nx_rect_contains(&rect, 1, 1), nxfalse);
	nx_assert_equal(nx_rect_contains(&rect, 4, 3), nxtrue);
	nx_assert_equal(nx_rect_contains(&rect, 5, 6), nxfalse);
	nx_assert_equal(nx_rect_contains(&rect, 6, 5), nxfalse);
	nx_assert_equal(nx_rect_contains(&rect, 4, 4), nxtrue);

	nx_rect_assign(&rect, 2,2,-2,-2);
	nx_assert_equal(nx_rect_contains(&rect, 0, 0), nxtrue);
	nx_assert_equal(nx_rect_contains(&rect, 1, 1), nxtrue);
	nx_assert_equal(nx_rect_contains(&rect, -1, -1), nxtrue);
	nx_assert_equal(nx_rect_contains(&rect, -1, 1), nxtrue);
	nx_assert_equal(nx_rect_contains(&rect, 1, -1), nxtrue);
	nx_assert_equal(nx_rect_contains(&rect, 2, 3), nxfalse);
	nx_assert_equal(nx_rect_contains(&rect, 3, 2), nxfalse);
	nx_assert_equal(nx_rect_contains(&rect, -2, -3), nxfalse);
	nx_assert_equal(nx_rect_contains(&rect, -3, -2), nxfalse);
}

/*************************************************************/
void test_rect_contains_other(void *status)
{
	nx_rect rect, rect2;
	nx_rect_assign(&rect, 2,2,5,5);
	nx_rect_assign(&rect2, 3,3,4,4);

	nx_assert_equal(nx_rect_contains_other(&rect, &rect2), nxtrue);
	
	nx_rect_assign(&rect2, 3,3,6,6);
	nx_assert_equal(nx_rect_contains_other(&rect, &rect2), nxfalse);

	nx_rect_assign(&rect2, 1,1,3,3);
	nx_assert_equal(nx_rect_contains_other(&rect, &rect2), nxfalse);

	nx_rect_assign(&rect2, 6,6,7,7);
	nx_assert_equal(nx_rect_contains_other(&rect, &rect2), nxfalse);
}

/*************************************************************/
void test_rect_intersects(void *status)
{
	nx_rect rect, rect2;
	nx_rect_assign(&rect, 2,2,5,5);
	nx_rect_assign(&rect2, 4,4,6,6);

	nx_assert_equal(nx_rect_intersects(&rect, &rect2), nxtrue);

	nx_rect_assign(&rect2, 0,0,1,1);
	nx_assert_equal(nx_rect_intersects(&rect, &rect2), nxfalse);

	nx_rect_assign(&rect, -2,-2,2,2);
	nx_assert_equal(nx_rect_intersects(&rect, &rect2), nxtrue);

	nx_rect_assign(&rect2, -1,-1,1,1);
	nx_assert_equal(nx_rect_intersects(&rect, &rect2), nxtrue);

	nx_rect_assign(&rect, 2,2,-2,-2);
	nx_assert_equal(nx_rect_intersects(&rect, &rect2), nxtrue);

	nx_rect_assign(&rect2, -4,-4,-3,-3);
	nx_assert_equal(nx_rect_intersects(&rect, &rect2), nxfalse);

	nx_rect_assign(&rect2, 3,3,4,4);
	nx_assert_equal(nx_rect_intersects(&rect, &rect2), nxfalse);
}

/*************************************************************/
void test_rect_translate(void *status)
{
	nx_rect rect;
	nx_point point;

	nx_rect_init(&rect);
	nx_rect_assign(&rect, 0,0,5,5);
	nx_point_init(&point);
	nx_point_assign(&point, 3, 3);

	nx_assert_equal(nx_rect_contains(&rect, 6,6), nxfalse);
	nx_assert_equal(nx_rect_contains(&rect, 1,1), nxtrue);
	
	nx_rect_translate(&rect, point.x, point.y);

	nx_assert_equal(nx_rect_contains(&rect, 6,6), nxtrue);
	nx_assert_equal(nx_rect_contains(&rect, 1,1), nxfalse);

	nx_point_assign(&point, -2, -2);

	nx_rect_translate_point(&rect, &point);

	nx_assert_equal(nx_rect_contains(&rect, 2,2), nxtrue);
	nx_assert_equal(nx_rect_contains(&rect, 5,5), nxtrue);
	nx_assert_equal(nx_rect_contains(&rect, -1,-1), nxfalse);
	nx_assert_equal(nx_rect_contains(&rect, 7,7), nxfalse);
}

/*************************************************************/
void test_rect_width(void *status)
{
	nx_rect rect;

	nx_rect_assign(&rect, 0,0,5,5);
	nx_assert_equal(nx_rect_width(&rect), 5);

	nx_rect_assign(&rect, -1,-1,5,5);
	nx_assert_equal(nx_rect_width(&rect), 6);
}

/*************************************************************/
void test_rect_height(void *status)
{
	nx_rect rect;

	nx_rect_assign(&rect, 0,0,5,5);
	nx_assert_equal(nx_rect_height(&rect), 5);

	nx_rect_assign(&rect, -1,-1,5,5);
	nx_assert_equal(nx_rect_height(&rect), 6);
}

/*************************************************************/
void test_rect_top_left(void *status)
{
	nx_rect rect;
	nx_point point;

	nx_rect_assign(&rect, 1,1,10,5);

	nx_rect_top_left(&rect, &point);
	nx_assert_equal(point.x, 1);
	nx_assert_equal(point.y, 1);
}

/*************************************************************/
void test_rect_top_right(void *status)
{
	nx_rect rect;
	nx_point point;

	nx_rect_assign(&rect, 1,1,10,5);

	nx_rect_top_right(&rect, &point);
	nx_assert_equal(point.x, 10);
	nx_assert_equal(point.y, 1);
}

/*************************************************************/
void test_rect_bottom_left(void *status)
{
	nx_rect rect;
	nx_point point;

	nx_rect_assign(&rect, 1,1,10,5);

	nx_rect_bottom_left(&rect, &point);
	nx_assert_equal(point.x, 1);
	nx_assert_equal(point.y, 5);
}

/*************************************************************/
void test_rect_bottom_right(void *status)
{
	nx_rect rect;
	nx_point point;

	nx_rect_assign(&rect, 1,1,10,5);

	nx_rect_bottom_right(&rect, &point);
	nx_assert_equal(point.x, 10);
	nx_assert_equal(point.y, 5);
}
