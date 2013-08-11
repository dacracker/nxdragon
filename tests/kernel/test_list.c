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

#include "test_list.h"

#include "kernel/nx_list.h"

#include "utest/nx_utest.h"

/*************************************************************/
void test_list_init_delete(void *status)
{
	nx_list list;
	nx_list_init(&list);

	/* Make sure all elements are properly initialized */
	nx_assert_equal(list.array,0);
	nx_assert_equal(list.size,0);
	nx_assert_equal(list.capacity,0);
	nx_assert_equal(nx_list_empty(&list),NX_TRUE);

	nx_list_delete(&list);
}

/*************************************************************/
void test_list_append(void *status)
{
	nx_list list;
	int counter = 0;

	nx_list_init(&list);

	nx_assert_equal(list.size,0);
	nx_assert_equal(nx_list_empty(&list),NX_TRUE);

	/* Append some values */
	while(counter < 120)
		nx_list_append(&list,(void*)++counter);

	/* Is the size of the list correct? */
	nx_assert_equal(nx_list_size(&list),counter);
	nx_assert_equal(nx_list_empty(&list),NX_FALSE);

	while(counter-- > 0)
		nx_assert_equal((int)nx_list_at(&list,counter),counter+1);

	nx_list_delete(&list);
}

/*************************************************************/
void test_list_insert(void *status)
{
	nx_list list;
	void* test_values[] = { (void*)52, 
							(void*)31,
							(void*)74 };

	nx_list_init(&list);

	nx_list_insert(&list,50,test_values[0]);

	nx_assert_equal(nx_list_at(&list,0),test_values[0]);

	nx_list_insert(&list,0,test_values[1]);

	nx_assert_equal(nx_list_at(&list,0),test_values[1]);
	nx_assert_equal(nx_list_at(&list,1),test_values[0]);

	nx_list_insert(&list,1,test_values[2]);

	nx_assert_equal(nx_list_at(&list,0),test_values[1]);
	nx_assert_equal(nx_list_at(&list,1),test_values[2]);
	nx_assert_equal(nx_list_at(&list,2),test_values[0]);

	nx_list_delete(&list);
}

/*************************************************************/
void test_list_first_last(void *status)
{
	nx_list list;
	void* test_values[] = { (void*)24, 
							(void*)71,
							(void*)29 };

	nx_list_init(&list);

	nx_list_append(&list,test_values[0]);
	nx_list_append(&list,test_values[1]);
	nx_list_append(&list,test_values[2]);

	nx_assert_equal(nx_list_first(&list),test_values[0]);
	nx_assert_equal(nx_list_last(&list),test_values[2]);

	nx_list_delete(&list);
}

/*************************************************************/
void test_list_value(void *status)
{
	nx_list list;
	int index,
		test_values_size;

	void* test_values[] = { (void*)24, 
							(void*)71,
							(void*)29 };

	test_values_size = sizeof(test_values)/sizeof(test_values[0]);

	index = -5;

	nx_list_init(&list);

	nx_list_append(&list,test_values[0]);
	nx_list_append(&list,test_values[1]);
	nx_list_append(&list,test_values[2]);

	while(index++ < 5)
	{
		if((index >= 0) && (index < test_values_size))
		{
			nx_assert_equal(nx_list_value(&list,index),test_values[index]);
		}
		else
		{
			nx_assert_equal(nx_list_value(&list,index),(void*)0);
		}
	}

	nx_list_delete(&list);
}
