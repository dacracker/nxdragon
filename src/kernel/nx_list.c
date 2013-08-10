/*
	NxDragon Game Engine

	Author: Patrik Jeppsson <dacrackerx64@gmail.com>

	License: This source code is proprietary and may not
			 be used without permission from the author. 
*/
			 
#include "nx_list.h"

#include "../math/nx_math.h"

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
static void _nx_list_grow(nx_list *self, int count)
{
	int size = nx_list_size(self) + count; 

	/* return if it's already safe to insert the 
	   requested number of items */
	if(size <= self->capacity)
		return; 

	/* calcualte the new capacity of the list */
	self->capacity = _nx_extend_capacity(size);

	/* resize the internal array */
	self->array = realloc(self->array, 
						  self->capacity * NX_POINTER_SIZE);	
}

/*************************************************************/
void nx_list_init(nx_list *self)
{
	self->size = self->capacity = 0; 
	self->array = 0;
}

/*************************************************************/
void nx_list_delete(nx_list *self)
{
	free(self->array);
}

/*************************************************************/
void nx_list_insert(nx_list *self, int position, void *data)
{
	/* make sure there's enough memory avalible to store the new item */
	_nx_list_grow(self,1);

	// Translate position into a valid position within the list, if necessary
	position = nx_clip(position,0,nx_list_size(self));

	/* move the items following the requested position out of the way */
	memmove(self->array + position + 1,
			self->array + position,
			NX_POINTER_SIZE * (nx_list_size(self) - position));

	self->array[position] = data;
	++self->size;
}

/*************************************************************/
void nx_list_append(nx_list *self, void *data)
{
	/* make sure there's enough memory avalible to store the new item */
	_nx_list_grow(self,1);

	/* Now append the new item at the end of the list */
	self->array[self->size++] = data;
}

/*************************************************************/
void nx_list_remove_at(nx_list *self, int position)
{
	memmove(self->array + position,
			self->array + position + 1,
			NX_POINTER_SIZE * (nx_list_size(self) - (position + 1)));

	--self->size;
}
