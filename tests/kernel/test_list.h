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
  
#ifndef __NX_KERNEL_TEST_LIST_H__
#define __NX_KERNEL_TEST_LIST_H__

/* Test basic initialization and destruction of the list */
void test_list_init_delete(void *status);

/* Test list append functionality plus some size checking */
void test_list_append(void *status);

/* Test list insert functionality */
void test_list_insert(void *status);

/* Tests the functions nx_list_first and nx_list_last */
void test_list_first_last(void *status);

/* Tests the nx_list_value function */
void test_list_value(void *status);

#endif
