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

#ifndef __NX_KERNEL_TEST_EVENTS_H__
#define __NX_KERNEL_TEST_EVENTS_H__

/** Test the event source without any event queues */
void test_event_source_empty(void *status);

/** Test the event source registration system */
void test_event_source_queue_reg(void *status);

/** Test the event source with one event queue */
void test_event_source_single_queue(void *status);

/** Test multiple event sources with one event queue */
void test_event_source_multiple_with_single_queue(void *status);

#endif
