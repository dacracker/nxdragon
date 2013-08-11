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

#include "py3bind/nx_pyengine.h"

/*************************************************************/
int main(int args, char** argv)
{
	nx_py3_init();

	NX_UNUSED(args); 
	NX_UNUSED(argv);

	nx_py3_run_file("simple.py"); 

	nx_py3_shutdown();

	return 0;
}
