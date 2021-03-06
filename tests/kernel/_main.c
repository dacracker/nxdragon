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
#include "kernel/nx_init.h"

#include "test_atomic.h"
#include "test_list.h"
#include "test_timer.h"
#include "test_queue.h" 
#include "test_events.h"

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
	&test_timer_start_stop,

	/* nx_queue */
	&test_queue_init,
	&test_queue_enqueue_dequeue,
	&test_queue_bounds, 

	/* nx_events */
	&test_event_source_empty,
	&test_event_source_queue_reg,
	&test_event_source_single_queue,
	&test_event_source_multiple_with_single_queue
};

/*************************************************************/
int main(int args, char** argv)
{
	int result; 
	NX_UNUSED(args); 
	NX_UNUSED(argv);

	nx_kernel_init();

	result = nx_run_tests(tests);
    
	nx_kernel_shutdown(); 

	return result; 
}
