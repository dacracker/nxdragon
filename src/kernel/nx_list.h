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

#ifndef __NXDRAGON_KERNEL_LIST_H__
#define __NXDRAGON_KERNEL_LIST_H__

#include "nx_def.h"
#include "nx_bool.h"

/** \ingroup NxKernel
  * \defgroup nx_list nx_list
  * \brief generic list container 
  *
  * A generic list. This list provides
  * a memory effective and fast list structure
  * with instanst access to any element in the list.
  * The list is optimized for insertions at the end
  * of the list. Prepends are possible but always
  * requires a reallocation of the list. 
  * @{
  */

typedef struct nx_list_t {
	void **array; /** Array containing all the items */
	int size,	  /** The number of allocated items in the list */
		capacity; /** The number of items that can be stored in the list before a reallocation needs to take place (PRIVATE) */
} nx_list;

/** Initializes the list to default values */
NX_KERNEL_API void nx_list_init(nx_list *self);

/** Deletes the data in the list object, the list should be considered 
	uninitialized after this funtion call  */
NX_KERNEL_API void nx_list_delete(nx_list *self);

/** Returns the current size of the list */
NX_KERNEL_API int nx_list_size(const nx_list *self);

/** Return value indicates if the list is empty or not */
NX_KERNEL_API nxbool nx_list_empty(const nx_list *self);

/** Returns nxtrue if the list contains the value, nxfalse if not */
NX_KERNEL_API nxbool nx_list_contains(const nx_list *self, void *value);

/** Inserts the data at the given position, which must be valid within the list.
	Performs a resize of the internal array if necessary. */
NX_KERNEL_API void nx_list_insert(nx_list *self,int position, void *data);

/** Prepends a new item at the front of the list, performas a resize
	of the internal array if necessary. */
NX_KERNEL_API void nx_list_prepend(nx_list *self,void *data);

/** Appends a new value at the end of the list, performs a resize of 
    the internal array if necessary */
NX_KERNEL_API void nx_list_append(nx_list *self, void *data);

/** Returns the item stored at the given position, the position must be 
	valid within the list */
NX_KERNEL_API void* nx_list_at(const nx_list *self,int position);

/** Safe version of nx_list_at() that will return 0 if the position is invalid */
NX_KERNEL_API void* nx_list_value(const nx_list *self, int position);

/** Returns the first item in the list, this function is unsafe if the list is empty */
NX_KERNEL_API void* nx_list_first(const nx_list *self);

/** Returns the last item in the list, this function is unsafe if the list is empty */
NX_KERNEL_API void* nx_list_last(const nx_list *self);

/** Removes the item at the given position from the list. The position must be valid  */
NX_KERNEL_API void nx_list_remove_at(nx_list *self, int position);

/** Removes the first item from the list, this function is unsafe if the list is empty */
NX_KERNEL_API void nx_list_remove_first(nx_list *self);

/** Removes the last item from the list, this function is unsafe if the list is empty */
NX_KERNEL_API void nx_list_remove_last(nx_list *self);

/** @} @} */
#endif
