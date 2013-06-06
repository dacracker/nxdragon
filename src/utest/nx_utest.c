#include "nx_utest.h"

#include <stdio.h>

/*************************************************************/
void _nx_report_error(nx_test_status *status,
					  const char* file,
					  const char* func,
					  const int line)
{
	NX_UNUSED(status);
	printf("\n**************************************************\n");
	printf("* ASSERTION ERROR: %s:%s(), line %d\n",file,func,line);
	printf("\n**************************************************\n");
}

/*************************************************************/
int _nx_check(nx_test_status *status, NX_BOOL result)
{
	if(result != NX_FALSE)
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
