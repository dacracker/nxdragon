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

#include "nx_math.h"

/*************************************************************/
nxbool nx_contains(nx_point *points, nxint32 count, nx_point *point)
{
	int index1, index2, result = 0;
	nx_point *p1, *p2;

	/* sanity check */
	if(count < 3)
		return nxfalse;

	for (index1 = 0, index2 = count - 1; index1 < count; index2 = index1++)
	{
		p1 = points + index1;
		p2 = points + index2;
		if(((p1->y > point->y) != (p2->y > point->y)) &&
			(point->x < (p2->x - p1->x) * (point->y - p1->y) / (p2->y - p1->y) + p1->x))
			result = !result;
	}

	return result ? nxtrue : nxfalse;
}