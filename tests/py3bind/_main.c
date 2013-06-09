#include "utest/nx_utest.h"

#include "py3bind/nx_pyengine.h"

/*************************************************************/
int main(int args, char** argv)
{
	nx_py3_init();

	NX_UNUSED(args); 
	NX_UNUSED(argv);

	nx_py3_run_script("print('Hello Python!');");

	nx_py3_run_file("simple.py");

	nx_py3_shutdown();

	return 0;
}
