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

/*************************************************************/
void test_vector2_init(void *status)
{
    nx_vector2 vector;
    nx_vector2_init(&vector);

    nx_assert_equal(vector.x, 0.0f);
    nx_assert_equal(vector.y, 0.0f);
}
