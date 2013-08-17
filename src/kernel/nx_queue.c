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

#include "nx_queue.h"
#include "nx_compiler.h"

#include <stdlib.h>
#include <string.h>

/*************************************************************/
NX_INLINE int _nx_round_up_to_multiple(int number, int multiple)
{ return (number + multiple - 1) / multiple * multiple;  }

/*************************************************************/
NX_INLINE int _nx_upper_power_of_two(int number)
{
	--number;    

	number |= number >> 1;
	number |= number >> 2;    
	number |= number >> 4;    
	number |= number >> 8;    
	number |= number >> 16;  

	return ++number;
}

/*************************************************************/
static int _nx_extend_capacity(int size)
{
	if(size < 20)
		return _nx_round_up_to_multiple(size,4);
	else if(size < 4084)
		return _nx_upper_power_of_two(size);
	
	return _nx_round_up_to_multiple(size,4096);
}

/*************************************************************/
/* Ensures that at least the given number of items can be 
   stored inside the internal array before a new allocation
   must be made. */
static void _nx_queue_grow(nx_queue *self, int count)
{
	int size = self->size + count; 

	/* return if it's already safe to insert the 
	   requested number of items */
	if(size <= self->capacity)
		return; 

	/* We prefer to move the memory back to the front of
	   the array to doing a reallocation of the entire queue. */
	if(self->front_index > 0)
	{
		memmove(self->array,
				self->array + self->front_index,
				(self->size - self->front_index) * NX_POINTER_SIZE);

		self->size -= self->front_index;
		self->front_index = 0;
		return;
	} 

	/* calculate the new capacity of the list */
	self->capacity = _nx_extend_capacity(size);

	/* resize the internal array */
	self->array = realloc(self->array, 
						  self->capacity * NX_POINTER_SIZE);	
}

/*************************************************************/
void nx_queue_init(nx_queue *self)
{
	self->array = 0;
	self->front_index = 0;
    self->size = 0;
    self->capacity = 0;
}

/*************************************************************/
void nx_queue_delete(nx_queue *self)
{
	free(self->array);
}

/*************************************************************/
void nx_queue_enqueue(nx_queue *self, void *data)
{
	_nx_queue_grow(self,1);

	self->array[self->size++] = data;
}

/*************************************************************/
void* nx_queue_dequeue(nx_queue *self)
{
	void *data;

	if(!nx_queue_size(self))
		return 0;

	data = nx_queue_at(self,0);

	++self->front_index;

	return data;
}

/*************************************************************/
void* nx_queue_at(nx_queue *self, int index)
{
	return self->array[self->front_index + index];
}

/*************************************************************/
void* nx_queue_value(nx_queue *self, int index)
{
	if(index < 0 || index >= nx_queue_size(self))
		return 0;

	return nx_queue_at(self,index);
}

/*************************************************************/
int nx_queue_size(nx_queue *self)
{
	return self->size - self->front_index;
}
