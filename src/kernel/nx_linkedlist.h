/*
  NxDragon Game Engine

  Author: Patrik Jeppsson <dacrackerx64@gmail.com>

  License: This source code is proprietary and may not
       be used without permission from the author. 
*/

#ifndef __NXDRAGON_KERNEL_LINKEDLIST_H__
#define __NXDRAGON_KERNEL_LINKEDLIST_H__

#include "nx_def.h"
#include "nx_compiler.h"
#include "nx_bool.h"

/** \defgroup nx_linkedlist nx_linkedlist
  * A generic linked list. New items can
  * be inserted at the beginning and at
  * the end of the list at O(1). 
  * @{
  */

typedef struct nx_linkedlist_node_t {
	struct nx_linkedlist_node_t *next; /* link to the next item in the list */
	struct nx_linkedlist_node_t *prev; /* link to the previous item in the list */
	void *data;						   /* the data itself */
} nx_linkedlist_node;

typedef struct nx_linkedlist_t {
	nx_linkedlist_node *first;	/** first node */
	nx_linkedlist_node *last;	/** last node */
  int size;         /** the number of elements in the list */
} nx_linkedlist;

/** Creates a new linked list */
NX_KERNEL_API void nx_linkedlist_init(nx_linkedlist *self);

/** Deletes a linked list */
NX_KERNEL_API void nx_linkedlist_delete(nx_linkedlist *self);

/** Appends a new item at the end of the list */
NX_KERNEL_API void nx_linkedlist_append(nx_linkedlist *self, void *data); 

/** Prepends a new item at the beginning of the list */
NX_KERNEL_API void nx_linkedlist_prepend(nx_linkedlist *self, void *data);

/** Returns the value at the give position, the index must be a valid position in the list (index < nx_linkedlist_size()) */
NX_KERNEL_API nx_linkedlist_node* nx_linkedlist_at(nx_linkedlist *self, int index);

/** Executes the given function for each item in the list */
NX_KERNEL_API void nx_linkedlist_foreach(nx_linkedlist *self,void (*pred)(void*));

/** Removes the first node from the list */
NX_KERNEL_API void nx_linkedlist_remove_first(nx_linkedlist *self);

/** Removes the node at the given position. The position must be valid within the list */
NX_KERNEL_API void nx_linkedlist_remove_at(nx_linkedlist *self, int position);

/** Removes the last node from the list */
NX_KERNEL_API void nx_linkedlist_remove_last(nx_linkedlist *self);

/** Returns the first item in the list */
NX_INLINE nx_linkedlist_node* nx_linkedlist_first(nx_linkedlist *self)
{ return self->first; }

/** Returns the last item in the list */
NX_INLINE nx_linkedlist_node* nx_linkedlist_last(nx_linkedlist *self)
{ return self->last; }

/** Returns the number of elements in the list */
NX_INLINE int nx_linkedlist_size(nx_linkedlist *self)
{ return self->size; }

/** Returns the number of elements in the list */
NX_INLINE NX_BOOL nx_linkedlist_empty(nx_linkedlist *self)
{ return self->size > 0 ? NX_FALSE : NX_TRUE; }

/** @} */
#endif
