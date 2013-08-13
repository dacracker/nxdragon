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

#include "nx_utest.h"

#include <stdio.h>

/*************************************************************/
void _nx_report_error(nx_test_status *status,
					  const char* file,
					  const char* func,
					  const int line)
{
	NX_UNUSED(status);
	printf("\n**************************************************\n"
		   "* ASSERTION ERROR: %s:%s(), line %d\n",file,func,line);
	printf("\n**************************************************\n");
}

/*************************************************************/
int _nx_check(nx_test_status *status, nxbool result)
{
	if(result != nxfalse)
		return 0;

	++status->assert_fail_count;

	return -1;
}

/*************************************************************/
int _nx_run_tests(nx_unit_test tests[], int count)
{
	nx_test_status teststat;
	int index = 0;

	teststat.total_count = count;
	teststat.failure_count = 0;

	printf("Running unit tests...");

	while(index < count)
	{
		teststat.assert_fail_count = 0;

		tests[index++](&teststat);

		if(teststat.assert_fail_count != 0)
			++teststat.failure_count;
	}

	if(teststat.failure_count != 0)
	{
		printf("\n**************************************************\n");
		printf("* %d of %d test(s) FAILED",teststat.failure_count, teststat.total_count);
		printf("\n**************************************************\n");

		return -1;
	}

	printf("\n**************************************************\n");
	printf("* %d test(s) returned OK!", teststat.total_count);
	printf("\n**************************************************\n");

	return 0;
}
