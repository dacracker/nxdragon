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

#include "nx_linkedlist.h"

#include <stdlib.h>

/*************************************************************/
static nx_linkedlist_node* nx_create_node(nx_linkedlist_node *prev,
										  nx_linkedlist_node *next,
										  void *data)
{
	nx_linkedlist_node *const node = malloc(sizeof(nx_linkedlist_node));
	
	if((node->prev = prev) != 0)
		prev->next = node;

	if((node->next = next) != 0)
		next->prev = node;

	node->data = data;

	return node;
}

/*************************************************************/
void nx_linkedlist_init(nx_linkedlist *self)
{	
	self->size = 0;
	self->first = self->last = 0;
}

/*************************************************************/
void nx_linkedlist_delete(nx_linkedlist *self)
{
	nx_linkedlist_node *itr = nx_linkedlist_first(self),
					   *current;

	/* free each node but don't the delete the 
	   data itself, that's not our job */
	while(itr != 0)
	{
		current = itr;
		itr = itr->next;
		free(current);
	}
}

/*************************************************************/
void nx_linkedlist_append(nx_linkedlist *self, void *data)
{
	if(!self->size)
		self->first = self->last = nx_create_node(0,0,data);
	else
		self->last = nx_create_node(self->last,0,data);

	++self->size;
}

/*************************************************************/
void nx_linkedlist_prepend(nx_linkedlist *self, void *data)
{
	if(!self->size)
		self->first = self->last = nx_create_node(0,0,data);
	else
		self->first = nx_create_node(0,self->first,data);

	++self->size;
}

/*************************************************************/
nx_linkedlist_node* nx_linkedlist_at(nx_linkedlist *self, int index)
{
	nx_linkedlist_node *itr = nx_linkedlist_first(self);
	int i = 0;

	/* 
	   Potentionally unsafe, it's the caller's 
	   responsibility to make sure "i" is within bounds 
	*/
	while(i++ < index)
		itr = itr->next;

	return itr;
}

/*************************************************************/
void nx_linkedlist_foreach(nx_linkedlist *self,void (*pred)(void*))
{
	nx_linkedlist_node *itr = nx_linkedlist_first(self);

	while(itr != 0)
	{
		pred(itr->data);
		itr = itr->next;
	}
}

/*************************************************************/
void nx_linkedlist_remove_first(nx_linkedlist *self)
{
	nx_linkedlist_node *first;

	if(self->size == 0)
		return;

	first = nx_linkedlist_first(self);

	if(nx_linkedlist_size(self) == 1)
		self->first = self->last = 0;
	else
		self->first = self->first->next;

	--self->size;

	free(first);
}

/*************************************************************/
void nx_linkedlist_remove_at(nx_linkedlist *self, int position)
{
	nx_linkedlist_node *node = nx_linkedlist_at(self,position);

	if(nx_linkedlist_size(self) == 1)
		self->first = self->last = 0;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	--self->size;

	free(node);
}

/*************************************************************/
void nx_linkedlist_remove_last(nx_linkedlist *self)
{
	nx_linkedlist_node *last;

	if(self->size == 0)
		return;

	last = nx_linkedlist_last(self);

	if(nx_linkedlist_size(self) == 1)
		self->first = self->last = 0;
	else
		self->last = self->last->prev;

	--self->size;

	free(last);
}

/*************************************************************/
nx_linkedlist_node* nx_linkedlist_first(nx_linkedlist *self)
{ 
	return self->first; 
}

/*************************************************************/
nx_linkedlist_node* nx_linkedlist_last(nx_linkedlist *self)
{ 
	return self->last; 
}

/*************************************************************/
int nx_linkedlist_size(nx_linkedlist *self)
{ 
	return self->size; 
}

/*************************************************************/
nxbool nx_linkedlist_empty(nx_linkedlist *self)
{ 
	return self->size > 0 ? nxfalse : nxtrue; 
}
