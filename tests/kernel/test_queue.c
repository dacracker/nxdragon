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

#include "test_queue.h"

#include "kernel/nx_queue.h"

#include "utest/nx_utest.h"

/*************************************************************/
void test_queue_init(void *status)
{
	nx_queue queue;
	nx_queue_init(&queue);

	nx_assert_equal(queue.array,0);
	nx_assert_equal(queue.size,0);
	nx_assert_equal(queue.capacity,0);
	nx_assert_equal(queue.front_index,0);

	nx_queue_delete(&queue);
}

/*************************************************************/
void test_queue_enqueue_dequeue(void *status)
{
	nx_queue queue;
	void* test_values[] = { (void*)0,
							(void*)1,
							(void*)2,
							(void*)3,};
	int index = 0,
		test_values_size = sizeof(test_values)/sizeof(test_values[0]);

	nx_queue_init(&queue);

	nx_assert_equal(nx_queue_size(&queue),0);

	while(index < test_values_size)
		nx_queue_enqueue(&queue,test_values[index++]);

	index = 0;

	nx_assert_equal(nx_queue_size(&queue),test_values_size);

	nx_assert_equal(nx_queue_dequeue(&queue),test_values[0]);
	nx_assert_equal(nx_queue_dequeue(&queue),test_values[1]);

	nx_assert_equal(nx_queue_size(&queue),test_values_size - 2);

	index = 0;

	while(index < test_values_size)
		nx_queue_enqueue(&queue,test_values[index++]);

	nx_assert_equal(nx_queue_size(&queue),(test_values_size*2) - 2);

	nx_assert_equal(nx_queue_dequeue(&queue),(void*)test_values[2]);
	nx_assert_equal(nx_queue_dequeue(&queue),(void*)test_values[3]);

	index = 0;

	while(index < test_values_size)
	{
		nx_assert_equal(nx_queue_at(&queue,index),test_values[index]);
		++index;
	}

	nx_queue_delete(&queue);
}

/*************************************************************/
void test_queue_bounds(void *status)
{
	nx_queue queue;
	void* test_values[] = { (void*)0,
							(void*)1,
							(void*)2,
							(void*)3,};
	int index = 0,
		test_values_size = sizeof(test_values)/sizeof(test_values[0]);

	nx_queue_init(&queue);

	while(index < test_values_size)
	{
		nx_queue_enqueue(&queue,test_values[index]);
		nx_assert_equal(nx_queue_value(&queue,index),test_values[index]);
		++index;
	}

	nx_assert_equal(nx_queue_value(&queue,-45),(void*)0);
	nx_assert_equal(nx_queue_value(&queue,-1),(void*)0);
	nx_assert_equal(nx_queue_value(&queue,test_values_size),(void*)0);
	nx_assert_equal(nx_queue_value(&queue,test_values_size+89),(void*)0);

	index = 0;

	/* It should be perfectly safe to call too many times */
	while(index < (test_values_size*2))
	{
		nx_queue_dequeue(&queue);

		++index;
	}

	nx_assert_equal(nx_queue_size(&queue),0);

	nx_queue_delete(&queue);
}
