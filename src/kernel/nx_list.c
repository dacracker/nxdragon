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

	if(size < 4084)
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

	/* calculate the new capacity of the list */
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
int nx_list_size(const nx_list *self)
{ 
	return self->size; 
}

/*************************************************************/
nxbool nx_list_empty(const nx_list *self)
{ 
	return nx_list_size(self) > 0 ? nxfalse : nxtrue; 
}

/*************************************************************/
nxbool nx_list_contains(const nx_list *self, void *value)
{
	int index = 0;

	while(index < nx_list_size(self))
	{
		if(nx_list_at(self,index) == value)
			return nxtrue;

		++index;
	}

	return nxfalse;
}

/*************************************************************/
void nx_list_insert(nx_list *self, int position, void *data)
{
	/* make sure there's enough memory avalible to store the new item */
	_nx_list_grow(self,1);

	/* Translate position into a valid position within the list, if necessary */
	position = nx_clip(position,0,nx_list_size(self));

	/* move the items following the requested position out of the way */
	memmove(self->array + position + 1,
			self->array + position,
			NX_POINTER_SIZE * (nx_list_size(self) - position));

	self->array[position] = data;
	++self->size;
}

/*************************************************************/
void nx_list_prepend(nx_list *self,void *data)
{ 
	nx_list_insert(self,0,data); 
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

/*************************************************************/
void* nx_list_at(const nx_list *self,int position)
{ 
	return self->array[position]; 
}

/*************************************************************/
void* nx_list_value(const nx_list *self, int position)
{ 
	return (position >= 0 && position < nx_list_size(self)) ? nx_list_at(self,position) : 0; 
}

/*************************************************************/
void* nx_list_first(const nx_list *self)
{ 
	return nx_list_at(self,0); 
}

/*************************************************************/
void* nx_list_last(const nx_list *self)
{ 
	return nx_list_at(self,nx_list_size(self)-1); 
}

/*************************************************************/
void nx_list_remove_first(nx_list *self)
{ 
	nx_list_remove_at(self,0); 
}

/*************************************************************/
void nx_list_remove_last(nx_list *self)
{ 
	nx_list_remove_at(self,nx_list_size(self)-1); 
}
