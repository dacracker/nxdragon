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

#ifndef __NX_GUI_WINDOW_H__
#define __NX_GUI_WINDOW_H__

#include "nx_def.h"
#include "nx_window_events.h"

#include "../kernel/nx_types.h"

/** \ingroup NxGui
  * \defgroup nx_window nx_window
  * \brief Window base object 
  * This object represents a basic window. It's main functionality
  * is to provide a cross-platform API for creating basic window
  * and to provide a event source for them. Every nx_window instace
  * will run it's message queue in it's own background thread. 
  * @{
  */

typedef struct nx_window_t nx_window;

/** Creates a new window */
NX_GUI_API nx_window *nx_window_create(const char *title, int width, int height);

/** Deletes the window */
NX_GUI_API void nx_window_delete(nx_window *self); 

/** Closes a window */
NX_GUI_API void nx_window_close(nx_window *self);

/** Returns the window's event source */
NX_GUI_API struct nx_event_source_t* nx_window_event_source(nx_window *self);

/** Resizes the window */
NX_GUI_API void nx_window_resize(nx_window *self, nxint32 width, nxint32 height);

/** Either removes or adds a frame to the window, depending on 'on' */
NX_GUI_API void nx_window_set_frameless(nx_window *self, nxbool on);

/** Returns nxtrue it the window is frameless */
NX_GUI_API nxbool nx_window_frameless(nx_window *self);

/** @} @} */

#endif
