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

#include <stdlib.h>

/*************************************************************/
void test_rect_init(void *status)
{
	nxint32 index;
	nx_rect *rect = (nx_rect*)malloc(sizeof(nx_rect));
	nx_rect_init(rect);

	for(index = 0; index < 4; ++index)
	{
		nx_assert_equal(rect->points[index].x, 0);
		nx_assert_equal(rect->points[index].y, 0);
	}

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
