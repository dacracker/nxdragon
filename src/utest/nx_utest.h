/*
  NxDragon Game Engine

  Author: Patrik Jeppsson <dacrackerx64@gmail.com>

  License: This source code is proprietary and may not
       be used without permission from the author. 
*/

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

NX_INTERNAL NX_UTEST_API int _nx_check(nx_test_status *status,NX_BOOL result);

NX_INTERNAL NX_UTEST_API void _nx_report_error(nx_test_status *status,
											   const char* file,
											   const char* func,
											   const int line);

/* Executes all tests in the list */
NX_INTERNAL NX_UTEST_API int _nx_run_tests(nx_unit_test tests[], int count);

/* Public API */
#define nx_run_tests(tests) _nx_run_tests(tests,sizeof(tests)/sizeof(tests[0]));

#define nx_assert(expr) if(_nx_check(status, expr ? NX_TRUE : NX_FALSE) != 0) _nx_report_error(status,__FILE__ ,__FUNCTION__ ,__LINE__);
#define nx_assert_equal(expr1,expr2) nx_assert(expr1 == expr2)
#define nx_assert_greater(expr1,expr2) nx_assert(expr1 > expr2)
#define nx_assert_lesser(expr1,expr2) nx_assert(expr1 < expr2) 
 
#endif
