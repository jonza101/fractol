#pragma OPENCL EXTENSION cl_amd_printf : enable

__kernel void test()
{
	long i = 0;
	printf("ffff\n");
	while (i < 100000000)
		i++;
}
