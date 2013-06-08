#include "test_list.h"

#include "kernel/nx_list.h"

#include "utest/nx_utest.h"

/*************************************************************/
void test_list_init_delete(void *status)
{
	nx_list list;

	nx_list_init(&list);

	/* Make sure all elements are properly initialized */
	nx_assert_equal(list.array,0);
	nx_assert_equal(list.size,0);
	nx_assert_equal(list.capacity,0);
	nx_assert_equal(nx_list_empty(&list),NX_TRUE);

	nx_list_delete(&list);
}

/*************************************************************/
void test_list_append(void *status)
{
	nx_list list;
	int counter = 0;

	nx_list_init(&list);

	nx_assert_equal(list.size,0);

	/* Append some values */
	while(counter < 120)
		nx_list_append(&list,(void*)++counter);

	/* Is the size of the list correct? */
	nx_assert_equal(nx_list_size(&list),counter);
	nx_assert_equal(nx_list_empty(&list),NX_FALSE);

	while(counter-- > 0)
		nx_assert_equal((int)nx_list_at(&list,counter),counter+1);

	nx_list_delete(&list);
}
