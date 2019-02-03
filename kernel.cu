#include "fractol.h"

__kernel void test();

// void	ft_start_cl(t_mlx *mlx)
// {
// 	mlx->kernel = malloc(sizeof(t_opencl));

// 	mlx->kernel->ret = clGetDeviceIDs(NULL, CL_device_ext_GPU, 1, &mlx->kernel->device_id, NULL);

// 	mlx->kernel->context = clCreateContext(0, 1, &mlx->kernel->device_id, NULL, NULL, &mlx->kernel->ret);

// 	mlx->kernel->commant_queue = clCreateCommandQueue(mlx->kernel->context, mlx->kernel->device_id, 0, &mlx->kernel->ret);
	
// 	//mlx->kernel->ret = clGetPlatformIDs(1, &mlx->kernel->platform_id, &mlx->kernel->ret_num_platform);
// }

void	ft_compile_cl(t_mlx *mlx)
{
	cl_program program;
	cl_kernel kernel;

	int fd;
	size_t source_size;
	const char *source_str;
	size_t source_len;
	char *temp;
	int i;

	fd = open("test_kernel.cl", O_RDONLY);
	temp = ft_strnew(1);
	source_str = ft_strnew(1);
	while (1)
	{
		while (get_next_line(fd, &temp) != 0)
		{
			source_str = ft_strjoin(source_str, temp);
			source_str = ft_strjoin(source_str, "\n");
		}
		break ;
	}
	close(fd);

	source_len = ft_strlen(source_str);

	printf("source len_log: %lu\n", source_len);
	printf("%s\n", source_str);


	mlx->kernel = malloc(sizeof(t_opencl));

	if ((mlx->kernel->ret = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &mlx->kernel->device_id, NULL)) != CL_SUCCESS)
	{
		printf("Error0\n");
		exit(0);
	}

	if (!(mlx->kernel->context = clCreateContext(0, 1, &mlx->kernel->device_id, NULL, NULL, &mlx->kernel->ret)))//CL_CONTEXT_PLATFORM
	{
		printf("Error1\n");
		exit(0);
	}

	if (!(mlx->kernel->commant_queue = clCreateCommandQueue(mlx->kernel->context, mlx->kernel->device_id, 0, &mlx->kernel->ret)))
	{
		printf("Error2\n");
		exit(0);
	}

	if (!(program = clCreateProgramWithSource(mlx->kernel->context, 1, (const char**)&source_str, &source_len, &mlx->kernel->ret)))
	{
		printf("Error3\n");
		exit(0);
	}



	size_t len_log;
	size_t len_status;
	size_t len_options;
	char device_info[512];
	char device_ext[512];

	if ((mlx->kernel->ret = clBuildProgram(program, 1, &mlx->kernel->device_id, NULL, NULL, NULL)) != CL_SUCCESS)
	{
		printf("ret %d\n", mlx->kernel->ret);
		//printf("Kernel Error!\n");

		clGetDeviceInfo(mlx->kernel->device_id, CL_DEVICE_NAME, 512, device_info, NULL);
		clGetDeviceInfo(mlx->kernel->device_id, CL_DEVICE_EXTENSIONS, 512, device_ext, NULL);

		printf("\nDEVICE INFO: %s\n", device_info);
		printf("\nDEVICE EXT: %s\n", device_ext);

		clGetProgramBuildInfo(program, mlx->kernel->device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &len_log);
		clGetProgramBuildInfo(program, mlx->kernel->device_id, CL_PROGRAM_BUILD_STATUS, 0, NULL, &len_status);
		clGetProgramBuildInfo(program, mlx->kernel->device_id, CL_PROGRAM_BUILD_OPTIONS, 0, NULL, &len_options);
		
		char *log = (char*)malloc(len_log);
		char *status = (char*)malloc(len_status);
		char *options = (char*)malloc(len_options);

		clGetProgramBuildInfo(program, mlx->kernel->device_id, CL_PROGRAM_BUILD_LOG, len_log, log, NULL);
		clGetProgramBuildInfo(program, mlx->kernel->device_id, CL_PROGRAM_BUILD_STATUS, len_status, status, NULL);
		clGetProgramBuildInfo(program, mlx->kernel->device_id, CL_PROGRAM_BUILD_STATUS, len_options, options, NULL);

		printf("\nLOG: %s\n", log);
		printf("\nSTATUS: %s\n", status);
		printf("\nOPTIONS: %s\n", options);
		exit(0);
	}

	kernel = clCreateKernel(program, "test", &mlx->kernel->ret);



	// cl_mem mem_obj = NULL;
	// //int mem_len = 1;
	// t_mlx *mem = (t_mlx*)malloc(sizeof(t_mlx));

	// mem_obj = clCreateBuffer(mlx->kernel->context, CL_MEM_READ_WRITE,  sizeof(t_mlx), NULL, &mlx->kernel->ret);

	// mlx->kernel->ret = clEnqueueWriteBuffer(mlx->kernel->commant_queue, NULL, CL_TRUE, 0, sizeof(t_mlx), mem, 0, NULL, NULL);

	// //mlx->kernel->ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), NULL);



	// mlx->kernel->ret = clEnqueueNDRangeKernel(mlx->kernel->commant_queue, kernel, 1, NULL, NULL, NULL, 0, NULL, NULL);

	// mlx->kernel->ret = clEnqueueReadBuffer(mlx->kernel->commant_queue, mem_obj, CL_TRUE, 0, sizeof(t_mlx), mem, 0, NULL, NULL);

	printf("aaa\n");
}

// CL_INVALID_PROGRAM if program is not a valid program object.
// CL_INVALID_VALUE if device_list is NULL and num_devices is greater than zero, or if device_list is not NULL and num_devices is zero.
// CL_INVALID_VALUE if pfn_notify is NULL but user_data is not NULL.
// CL_INVALID_DEVICE if OpenCL devices listed in device_list are not in the list of devices associated with program.
// CL_INVALID_BINARY if program is created with clCreateWithProgramWithBinary and devices listed in device_list do not have a valid program binary loaded.
// CL_INVALID_BUILD_OPTIONS if the build options specified by options are invalid.
// CL_INVALID_OPERATION if the build of a program executable for any of the devices listed in device_list by a previous call to clBuildProgram for program has not completed.
// CL_COMPILER_NOT_AVAILABLE if program is created with clCreateProgramWithSource and a compiler is not available i.e. CL_DEVICE_COMPILER_AVAILABLE specified in the table of OpenCL Device Queries for clGetDeviceInfo is set to CL_FALSE.
// CL_BUILD_PROGRAM_FAILURE if there is a failure to build the program executable. This error will be returned if clBuildProgram does not return until the build has completed.
// CL_INVALID_OPERATION if there are kernel objects attached to program.
// CL_OUT_OF_RESOURCES if there is a failure to allocate resources required by the OpenCL implementation on the device.
// CL_OUT_OF_HOST_MEMORY if there is a failure to allocate resources required by the OpenCL implementation on the host.