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

#ifndef __NX_UTEST_UNITTEST_H__
#define __NX_UTEST_UNITTEST_H__

#include "../kernel/nx_def.h"
#include "../kernel/nx_bool.h"

#ifdef NXDRAGON_BUILD_UTEST
#	define NX_UTEST_API NX_EXPORT
#else
#	define NX_UTEST_API NX_IMPORT
#endif

typedef struct nx_test_status_t {
	unsigned int failure_count,
				 assert_fail_count,
				 total_count;
} nx_test_status;

/* Signature for the unit tests */
typedef void (*nx_unit_test)(void *status);

NX_INTERNAL NX_UTEST_API int _nx_check(nx_test_status *status, nxbool result);

NX_INTERNAL NX_UTEST_API void _nx_report_error(nx_test_status *status,
											   const char* file,
											   const char* func,
											   const int line);

/* Executes all tests in the list */
NX_INTERNAL NX_UTEST_API int _nx_run_tests(nx_unit_test tests[], int count);

/* Public API */
#define nx_run_tests(tests) _nx_run_tests(tests,sizeof(tests)/sizeof(tests[0]));

#define nx_assert(expr) if(_nx_check(status, expr ? nxtrue : nxfalse) != 0) _nx_report_error(status,__FILE__ ,__FUNCTION__ ,__LINE__);
#define nx_assert_equal(expr1,expr2) nx_assert(expr1 == expr2)
#define nx_assert_greater(expr1,expr2) nx_assert(expr1 > expr2)
#define nx_assert_lesser(expr1,expr2) nx_assert(expr1 < expr2) 
 
#endif
