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
  
#ifndef __NX_MATH_TEST_RECT_H__
#define __NX_MATH_TEST_RECT_H__

/* Test basic initialization and destruction of the rectangle */
void test_rect_init(void *status);

/* */
void test_rect_contains(void *status);

/* */
void test_rect_contains_other(void *status);

/* */
void test_rect_intersects(void *status);

/* */
void test_rect_translate(void *status);

/* */
void test_rect_width(void *status);

/* */
void test_rect_height(void *status);

/* */
void test_rect_top_left(void *status);

/* */
void test_rect_top_right(void *status);

/* */
void test_rect_bottom_left(void *status);

/* */
void test_rect_bottom_right(void *status);

#endif
