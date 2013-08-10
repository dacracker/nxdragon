#ifndef __NX_KERNEL_TEST_LIST_H__
#define __NX_KERNEL_TEST_LIST_H__

/* Test basic initialization and destruction of the list */
void test_list_init_delete(void *status);

/* Test list append functionality plus some size checking */
void test_list_append(void *status);

/* Test list insert functionality */
void test_list_insert(void *status);

#endif
