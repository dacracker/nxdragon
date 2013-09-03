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
  
#ifndef __NX_MATH_TEST_POINT_H__
#define __NX_MATH_TEST_POINT_H__

/* Test basic initialization and destruction of the point */
void test_point_init(void *status);

/* Tests the function for assigning values to a point */
void test_point_assign(void *status);

/* Tests the function for assigning values to a point from another point */
void test_point_assign_point(void *status);

/* Tests that the distanceTo between 2 points function works properly. */
void test_point_distance_to(void *status);

/* Tests the function for translating one point with another */
void test_point_translate(void *status);

/* Tests the funtion for swapping the values of points */
void test_point_swap(void *status);

/* Tests the funtion for transforming to the absolute-value of the point */
void test_point_abs(void *status);

/* Test the angle_deg function */
void test_angle_deg(void *status);

#endif
