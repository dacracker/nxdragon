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

#include "test_vector2.h"
#include "utest/nx_utest.h"
#include "math/nx_vector2.h"
#include "math/nx_math.h"

/*************************************************************/
void test_vector2_init(void *status)
{
    nx_vector2 vector;
    nx_vector2_init(&vector);

    nx_assert_equal(vector.x, 0.0f);
    nx_assert_equal(vector.y, 0.0f);
}

/*************************************************************/
void test_vector2_assign(void *status)
{
    nx_vector2 vector;
    nx_vector2_init(&vector);

    nx_vector2_assign(&vector, 5.0f, -10.1f);
    nx_assert_equal(vector.x, 5.0f);
    nx_assert_equal(vector.y, -10.1f);
}

/*************************************************************/
void test_vector2_assign_vector(void *status)
{
    nx_vector2 vector, vector2;
    nx_vector2_init(&vector);
    nx_vector2_init(&vector2);

    nx_vector2_assign(&vector, 1, 1);
    nx_vector2_assign(&vector2, 2, 2);

    nx_vector2_assign_vector(&vector, &vector2);

    nx_assert_equal(vector.x, 2.0f);
    nx_assert_equal(vector.y, 2.0f);
    nx_assert_equal(vector2.x, 2.0f);
    nx_assert_equal(vector2.x, 2.0f);
}

/*************************************************************/
void test_vector2_distance_to(void *status)
{
    nx_vector2 vector, vector2;
    nx_vector2_init(&vector);
    nx_vector2_init(&vector2);

    vector.x = 4;
    vector.y = 3;

    nx_assert_equal(nx_vector2_distance_to(&vector, &vector2), 5.0f);
    nx_assert_equal(nx_vector2_distance_to(&vector2, &vector), 5.0f);

    vector2.x = 4;
    nx_assert_equal(nx_vector2_distance_to(&vector, &vector2), 3.0f);
    nx_assert_equal(nx_vector2_distance_to(&vector2, &vector), 3.0f);

    vector2.y = 1;
    nx_assert_equal(nx_vector2_distance_to(&vector, &vector2), 2.0f);
    nx_assert_equal(nx_vector2_distance_to(&vector2, &vector), 2.0f);

    vector2.y = -3;
    nx_assert_equal(nx_vector2_distance_to(&vector, &vector2), 6.0f);
    nx_assert_equal(nx_vector2_distance_to(&vector2, &vector), 6.0f);

    vector2.x = 0;
    nx_assert_equal(nx_vector2_distance_to(&vector, &vector2), 7.2111025f);
    nx_assert_equal(nx_vector2_distance_to(&vector2, &vector), 7.2111025f);

    vector2.x = -4;
    nx_assert_equal(nx_vector2_distance_to(&vector, &vector2), 10.0f);
    nx_assert_equal(nx_vector2_distance_to(&vector2, &vector), 10.0f);

    vector2.y = 0;
    nx_assert_equal(nx_vector2_distance_to(&vector, &vector2), 8.5440037f);
    nx_assert_equal(nx_vector2_distance_to(&vector2, &vector), 8.5440037f);

    vector2.y = 3;
    nx_assert_equal(nx_vector2_distance_to(&vector, &vector2), 8.0f);
    nx_assert_equal(nx_vector2_distance_to(&vector2, &vector), 8.0f);

    vector2.x = 0;
    nx_assert_equal(nx_vector2_distance_to(&vector, &vector2), 4.0f);
    nx_assert_equal(nx_vector2_distance_to(&vector2, &vector), 4.0f);
}

/*************************************************************/
void test_vector2_translate(void *status)
{
    nx_vector2 vector, vector2;
    nx_vector2_init(&vector);
    nx_vector2_init(&vector2);

    nx_vector2_assign(&vector, 1, 1);
    nx_vector2_assign(&vector2, 2, 2);
    nx_vector2_translate(&vector, &vector2);
    nx_assert_equal(vector.x, 3.0f);
    nx_assert_equal(vector.y, 3.0f);

    nx_vector2_assign(&vector, 5.5, 3);
    nx_vector2_assign(&vector2, -3, -1.1f);
    nx_vector2_translate(&vector, &vector2);
    nx_assert_equal(vector.x, 2.5f);
    nx_assert_equal(vector.y, 1.9f);
}

/*************************************************************/
void test_vector2_swap(void *status)
{
    nx_vector2 vector, vector2;
    nx_vector2_init(&vector);
    nx_vector2_init(&vector2);

    nx_vector2_assign(&vector, 1, 1);
    nx_vector2_assign(&vector2, 2, 2);
    nx_vector2_swap(&vector, &vector2);

    nx_assert_equal(vector.x, 2.0f);
    nx_assert_equal(vector.y, 2.0f);
    nx_assert_equal(vector2.x, 1.0f);
    nx_assert_equal(vector2.y, 1.0f);
}
