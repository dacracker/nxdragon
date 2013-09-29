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

#include "nx_window.h"

#include "../kernel/nx_types.h"
#include "../kernel/nx_memory.h"
#include "../kernel/nx_mutex.h"
#include "../kernel/nx_wait_condition.h"
#include "../kernel/nx_event_source.h"
#include "../kernel/nx_thread.h"

#include <stdio.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

struct nx_window_t {
	HWND handle;
	LPCSTR className;
	char *title; 
	int width,
		height; 
	nx_event_source *event_source;
	nx_mutex *mutex; 
	nx_wait_condition *wait_cond;
	nx_thread *thread;
};

/*************************************************************/
LRESULT CALLBACK _nx_win32_proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	nx_window *window = (nx_window*)GetWindowLongPtr(hwnd,GWLP_USERDATA);

	switch(message)
	{
	case WM_CREATE:
		SetWindowLongPtr(hwnd,GWLP_USERDATA,(LONG_PTR)((CREATESTRUCT*)lparam)->lpCreateParams);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);

		{
			window_closed_event *window_closed_event = _nx_create_window_closed_event(window);

			nx_event_source_emit(window->event_source,&window_closed_event->base);
		}

		break;
	case WM_DESTROY:
		PostQuitMessage(0);

		break; 
	default:
		return DefWindowProc(hwnd,message,wparam,lparam);
	}

	return 0;
}

/*************************************************************/
static nxbool _nx_setup_window(WNDCLASSEX *wcex, nx_window *window)
{
	window->handle = CreateWindowEx(WS_EX_APPWINDOW,
									wcex->lpszClassName,
									window->title,
									WS_OVERLAPPEDWINDOW,
									CW_USEDEFAULT,
									CW_USEDEFAULT,
									window->width,
									window->height,
									0,
									0,
									GetModuleHandle(0),
									window);

	if(!window->handle)
	{
		window->handle = (HWND)-1;
		return nxfalse;
	}

	/* Present the Window on screen */
	ShowWindow(window->handle,SW_SHOW);
	UpdateWindow(window->handle);

	return nxtrue;
}

/*************************************************************/
static nxbool _nx_setup_wcex(WNDCLASSEX *wcex)
{
	static int _window_count = 0;

	char *class_name = nx_malloc(64 * sizeof(char));
	sprintf_s(class_name,64 * sizeof(char),"nxdragon_window_class_%d",++_window_count); 

	wcex->cbSize = sizeof(WNDCLASSEX);
	wcex->lpszClassName = class_name; 
	wcex->style = CS_HREDRAW | CS_VREDRAW;
	wcex->cbClsExtra = 0;
	wcex->cbWndExtra = 0;
	wcex->hInstance = GetModuleHandle(0);
	wcex->hIcon = LoadIcon(0, IDI_APPLICATION);
	wcex->hCursor = LoadCursor(0,IDC_ARROW);
	wcex->hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wcex->lpszMenuName = 0;
	wcex->hIconSm = LoadIcon(0, IDI_APPLICATION);

	wcex->lpfnWndProc = &_nx_win32_proc;

	return RegisterClassEx(wcex) != 0 ? nxtrue : nxfalse; 
}

/*************************************************************/
void _nx_delete_wcex(WNDCLASSEX *wcex)
{
	UnregisterClass(wcex->lpszClassName,GetModuleHandle(0));
	nx_free((void*)wcex->lpszClassName);
}

/*************************************************************/
static void _nx_window_thread_proc(nx_thread *thread, nx_window *self)
{
	WNDCLASSEX wcex;
	MSG message;

	NX_UNUSED(thread);

	/* Create the window class*/
	if(_nx_setup_wcex(&wcex) != nxtrue)
	{
		nx_wait_condition_wake_one(self->wait_cond);
		return; 
	}

	/* Create the window itself  */
	if(_nx_setup_window(&wcex,self) != nxtrue)
	{
		nx_wait_condition_wake_one(self->wait_cond);
		return;
	}

	/* Let nx_window_create() proceed since the window has been created */
	nx_wait_condition_wake_one(self->wait_cond);

	/* Start the message loop */
	while(GetMessage(&message,0,0,0) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	/* Time to destroy the window class */
	_nx_delete_wcex(&wcex);
}

/*************************************************************/
nx_window *nx_window_create(const char *title, int width, int height)
{
	nx_window *window;

	window = nx_malloc(sizeof(nx_window));

	if(!window)
		return 0;

	ZeroMemory(window,sizeof(nx_window));

	window->title = _strdup(title); 
	window->width = width;
	window->height = height; 
	window->mutex = nx_mutex_create();
	window->wait_cond = nx_wait_condition_create();
	window->event_source = nx_event_source_create();

	nx_mutex_lock(window->mutex);

	window->thread = nx_thread_begin((nx_thread_proc)&_nx_window_thread_proc,
									 window);

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
	PostMessage(self->handle, WM_CLOSE, 0, 0); 
}

/*************************************************************/
nx_event_source* nx_window_event_source(nx_window *self)
{
	return self->event_source;
}
