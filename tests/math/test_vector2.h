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
  
#ifndef __NX_MATH_TEST_VECTOR2_H__
#define __NX_MATH_TEST_VECTOR2_H__

/* Test basic initialization and destruction of the vector */
void test_vector2_init(void *status);

/* Tests the function for assigning values to a vector */
void test_vector2_assign(void *status);

/* Tests the function for assigning values to a vector from another vector */
void test_vector2_assign_vector(void *status);

/* Tests that the distanceTo between 2 vectors function works properly. */
void test_vector2_distance_to(void *status);

/* Tests the function for translating one vector with another */
void test_vector2_translate(void *status);

/* Tests the funtion for swapping the values of vectors */
void test_vector2_swap(void *status);

/* Tests the funtion for transforming to the absolute-value of the vector */
void test_vector2_abs(void *status);

#endif
