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
  
#include "utest/nx_utest.h"

#include "test_vector2.h"
#include "test_point.h"
#include "test_rect.h"
#include "test_ray2.h"

nx_unit_test tests[] = {  
	/* nx_vector2 */
	&test_vector2_init,
	&test_vector2_assign,
	&test_vector2_assign_vector,
	&test_vector2_distance_to,
	&test_vector2_translate,
	&test_vector2_swap,
	&test_vector2_abs,
	/* nx_point */
	&test_point_init,
	&test_point_assign,
	&test_point_assign_point,
	&test_point_distance_to,
	&test_point_translate,
	&test_point_swap,
	&test_point_abs,
	&test_angle_deg,
	/* nx_rect */
	&test_rect_init,
	&test_rect_contains,
	&test_rect_contains_other,
	&test_rect_intersects,
	&test_rect_translate,
	&test_rect_width,
	&test_rect_height,
	&test_rect_top_left,
	&test_rect_top_right,
	&test_rect_bottom_left,
	&test_rect_bottom_right,
	/* nx_ray2 */
	&test_ray2_init,
	&test_ray2_origin,
	&test_ray2_direction,
	&test_ray2_intersects
};

/*************************************************************/
int main(int args, char** argv)
{
	NX_UNUSED(args); 
	NX_UNUSED(argv);
    
	return nx_run_tests(tests);
}
