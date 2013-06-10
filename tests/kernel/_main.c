#include "utest/nx_utest.h"

#include "test_atomic.h"
#include "test_list.h"

/*************************************************************/
int main(int args, char** argv)
{
	nx_unit_test tests[] = { /* nx_atomic */
							 &test_atomic_inc,
							 &test_atomic_dec,

							 /* nx_list */
							 &test_list_init_delete,
							 &test_list_append };

	NX_UNUSED(args); 
	NX_UNUSED(argv);
    
	return nx_run_tests(tests);
}
