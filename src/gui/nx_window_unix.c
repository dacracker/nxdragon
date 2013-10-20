/***************************************************************************\
  This file is part of the NxDragon Game Engine.

  Copyright 2013 Patrik Jeppsson, Ulf Johnsson
  
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

#include "nx_window.h"

#include "../kernel/nx_types.h"
#include "../kernel/nx_memory.h"
#include "../kernel/nx_mutex.h"
#include "../kernel/nx_wait_condition.h"
#include "../kernel/nx_event_source.h"
#include "../kernel/nx_thread.h"

#include <stdio.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>

/* There seems to be a bug where gcc does not realize that strdup is defined... */
extern char* strdup (const char *); 

struct nx_window_t {
    Atom wm_delete_window,
         wm_hints;
    Window handle;
    Display *display;
    char *title;
    int width,
        height,
        windowed_width,
        windowed_height,
        screen;
    nxbool frameless;
    nx_event_source *event_source;
    nx_mutex *mutex;
    nx_wait_condition *wait_cond;
    nx_thread *thread;
};

typedef struct {
    unsigned long flags,
                  functions,
                  decorations;
    long inputMode;
    unsigned long status;
} window_hints;

typedef enum nx_window_property_t {
    NX_WINDOW_HEIGHT,
    NX_WINDOW_WIDTH
} nx_window_property;

/*************************************************************/
static void _nx_window_set_frameless(nx_window *window, nxbool on)
{
    window_hints hints;

    /* if user is trying to set the frameless-status to something it already is, we abort */
    if(on == window->frameless)
        return;

    window->frameless = on;

    hints.flags = 2;
    hints.decorations = on ? 0 : 1;

    XChangeProperty(window->display,
                    window->handle,
                    window->wm_hints,
                    window->wm_hints,
                    32,
                    PropModeReplace,
                    (unsigned char *)&hints,
                    5);

    XFlush(window->display);
}

/*************************************************************/
static nxbool _nx_setup_window(nx_window *window)
{
    XSetWindowAttributes attributes;

    /* Try to open the display */
    window->display = XOpenDisplay(0);
    if(window->display == 0)
        return nxfalse;

    window->screen = DefaultScreen(window->display);

    attributes.background_pixel = XBlackPixel(window->display,window->screen);
    attributes.border_pixel = XBlackPixel(window->display,window->screen);
    attributes.override_redirect = 0;

    window->handle = XCreateWindow(window->display,
                                   RootWindow(window->display, window->screen),
                                   0, 0,
                                   window->windowed_width, window->windowed_height,
                                   1,
                                   DefaultDepth(window->display,window->screen),
                                   InputOutput,
                                   DefaultVisual(window->display,window->screen),
                                   CWBackPixel | CWBorderPixel,
                                   &attributes);

    window->wm_hints = XInternAtom(window->display,"_MOTIF_WM_HINTS",True);

    /* Set the title */
    XStoreName(window->display, window->handle, window->title);

    window->wm_delete_window = XInternAtom(window->display, "WM_DELETE_WINDOW", 0);
    XSetWMProtocols(window->display, window->handle, &window->wm_delete_window, 1);

    XSelectInput(window->display, window->handle, ExposureMask | StructureNotifyMask);

    /* Map to the display */
    XMapWindow(window->display, window->handle);

    /* Flush */
    XFlush(window->display);

    return nxtrue;
}

/*************************************************************/
static void _nx_window_thread_proc(nx_thread *thread, nx_window *self)
{
    XEvent event;
    window_closed_event *window_closed_event;
    nxbool running = nxtrue;

    NX_UNUSED(thread);

    /* Create the window itself */
    if(_nx_setup_window(self) != nxtrue)
    {
        nx_wait_condition_wake_one(self->wait_cond);
        return;
    }

    /* Let nx_window_create() proceed since the window has been created */
    nx_wait_condition_wake_one(self->wait_cond);

    while(running == nxtrue)
    {
        XNextEvent(self->display, &event);

        switch(event.type)
        {
        case ClientMessage:
        {
            /* close-event */
            if(event.xclient.data.l[0] == self->wm_delete_window)
            {
                running = nxfalse;
                window_closed_event = _nx_create_window_closed_event(self);
                nx_event_source_emit(self->event_source, &window_closed_event->base);
                break;
            }
        }
        case ConfigureNotify:
        {
            /* This event may occur for att kinds of intents, so we have to check if it is for a rezise */
            if(self->width != event.xconfigure.width)
                self->width = event.xconfigure.width;

            if(self->height != event.xconfigure.height)
                self->height = event.xconfigure.height;

            break;
        }
        }
    }
}

/*************************************************************/
nx_window *nx_window_create(const char *title, int width, int height)
{
    nx_window *window;

    /* Allocate the structure */
    window = nx_malloc(sizeof(nx_window));

    window->handle = 0;
    window->frameless = nxfalse;
    window->title = strdup(title);
    window->width = window->windowed_width = width;
    window->height = window->windowed_height = height;
    window->mutex = nx_mutex_create();
    window->wait_cond = nx_wait_condition_create();
    window->event_source = nx_event_source_create();

    nx_mutex_lock(window->mutex);

    window->thread = nx_thread_begin((nx_thread_proc)&_nx_window_thread_proc, window);

    /* Wait for the window creation process to finish */
    while(window->handle == 0)
        nx_wait_condition_wait(window->wait_cond,
                               window->mutex,
                               -1); /* There's no reason to continue before the window has been created */

    nx_mutex_unlock(window->mutex);

    return window;
}

/*************************************************************/
void nx_window_delete(nx_window *self)
{
	if(nx_thread_is_running(self->thread))
		nx_window_close(self);

    XCloseDisplay(self->display);

	nx_thread_end(self->thread);

	nx_event_source_delete(self->event_source);

	nx_mutex_delete(self->mutex);

	nx_wait_condition_delete(self->wait_cond);

	nx_free(self->title);

	nx_free(self);
}

/*************************************************************/
void nx_window_close(nx_window *self)
{
    XDestroyWindow(self->display, self->handle);
    XFlush(self->display);
}

/*************************************************************/
nx_event_source* nx_window_event_source(nx_window *self)
{
	return self->event_source;
}

/*************************************************************/
int nx_window_width(nx_window *self)
{
    int width;

    nx_mutex_lock(self->mutex);

    width = self->width;

    nx_mutex_unlock(self->mutex);

    return width;
}

/*************************************************************/
int nx_window_height(nx_window *self)
{
    int height;

    nx_mutex_lock(self->mutex);

    height = self->height;

    nx_mutex_unlock(self->mutex);

    return height;
}

/*************************************************************/
void nx_window_resize(nx_window *self, int width, int height)
{
    nx_mutex_lock(self->mutex);

    XResizeWindow(self->display, self->handle, width, height);
    XFlush(self->display);

    nx_mutex_unlock(self->mutex);
}

/*************************************************************/
void nx_window_set_fullscreen(nx_window *self, nxbool on)
{
    /* TODO: implement */
    NX_UNUSED(self);
    NX_UNUSED(on);
}

/*************************************************************/
nxbool nx_window_fullscreen(nx_window *self)
{
    return nxfalse;
}
