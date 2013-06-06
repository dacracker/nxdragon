#include "test_atomic.h"

#include "kernel/nx_atomic.h"
#include "utest/nx_utest.h"

/*************************************************************/
void test_atomic_inc(void *status)
{
	int value = 0,
		counter = 0;
	
	while(counter < 5)
		nx_assert_equal(nx_atomic_inc(&value),++counter);

	nx_assert_equal(counter,nx_atomic_read(&value));
}

/*************************************************************/
void test_atomic_dec(void *status)
{
	int value = 5,
		counter = 5;

	while(counter > 0)
		nx_assert_equal(nx_atomic_dec(&value),--counter);

	nx_assert_equal(counter,nx_atomic_read(&value));
}
