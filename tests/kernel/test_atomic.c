/***************************************************************************\
  This file is part of the NxDragon Game Engine.

  Copyright 2013 Patrik Jeppsson
  
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

#include "test_atomic.h"

#include "kernel/nx_atomic.h"
#include "utest/nx_utest.h"

/*************************************************************/
void test_atomic_inc(void *status)
{
	int value = 0,
		counter = 0;
	
	while(counter < 5)
		nx_assert_equal(nx_atomic_inc(&value),++counter);

	nx_assert_equal(counter,nx_atomic_value(&value));
}

/*************************************************************/
void test_atomic_dec(void *status)
{
	int value = 5,
		counter = 5;

	while(counter > 0)
		nx_assert_equal(nx_atomic_dec(&value),--counter);

	nx_assert_equal(counter,nx_atomic_value(&value));
}
