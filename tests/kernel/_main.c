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
  
#include "utest/nx_utest.h"

#include "test_atomic.h"
#include "test_list.h"
#include "test_timer.h"
#include "test_queue.h" 

static nx_unit_test tests[] = {  

  /* nx_atomic */
  &test_atomic_inc,
  &test_atomic_dec,

  /* nx_list */
  &test_list_init_delete,
  &test_list_append,
  &test_list_insert,
  &test_list_first_last,
  &test_list_value,

  /* nx_timer */
  &test_ticks,

  /* nx_queue */
  &test_queue_init,
  &test_queue_enqueue_dequeue,
  &test_queue_bounds 
};

/*************************************************************/
int main(int args, char** argv)
{
  NX_UNUSED(args); 
  NX_UNUSED(argv);
    
	return nx_run_tests(tests);
}
