/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:23:57 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/31 17:20:50 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_start_cl(t_mlx *mlx)
{
	mlx->kernel = malloc(sizeof(t_opencl));
	mlx->kernel->ret = clGetPlatformIDs(1, &mlx->kernel->platform_id, &mlx->kernel->ret_num_platform);
	mlx->kernel->ret = clGetDeviceIDs(mlx->kernel->platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &mlx->kernel->device_id, &mlx->kernel->ret_num_devices);
	
	mlx->kernel->context = clCreateContext(NULL, 1, &mlx->kernel->device_id, NULL, NULL, &mlx->kernel->ret);

	mlx->kernel->commant_queue = clCreateCommandQueue(mlx->kernel->context, mlx->kernel->device_id, 0, &mlx->kernel->ret);
}

void	ft_compile_cl(t_mlx *mlx)
{
	cl_program program = NULL;
	cl_kernel kernel = NULL;

	int fd;
	size_t source_size;
	char *source_str;
	int i;

	fd = open("test_kernel.cl", O_RDONLY);
	source_str = (char*)malloc(sizeof(char) * 2500);
	source_size = read(fd, source_str, 2500);
	close(fd);

	program = clCreateProgramWithSource(mlx->kernel->context, 1, (const char**)&source_str, (const size_t*)&source_size, &mlx->kernel->ret);

	mlx->kernel->ret = clBuildProgram(program, 1, &mlx->kernel->device_id, NULL, NULL, NULL);

	kernel = clCreateKernel(program, "test", &mlx->kernel->ret);



	cl_mem mem_obj = NULL;
	//int mem_len = 1;
	t_mlx *mem = (t_mlx*)malloc(sizeof(t_mlx));

	mem_obj = clCreateBuffer(mlx->kernel->context, CL_MEM_READ_WRITE,  sizeof(t_mlx), NULL, &mlx->kernel->ret);

	mlx->kernel->ret = clEnqueueWriteBuffer(mlx->kernel->commant_queue, NULL, CL_TRUE, 0, sizeof(t_mlx), mem, 0, NULL, NULL);

	mlx->kernel->ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), NULL);



	mlx->kernel->ret = clEnqueueNDRangeKernel(mlx->kernel->commant_queue, kernel, 1, NULL, NULL, NULL, 0, NULL, NULL);

	mlx->kernel->ret = clEnqueueReadBuffer(mlx->kernel->commant_queue, mem_obj, CL_TRUE, 0, sizeof(t_mlx), mem, 0, NULL, NULL);

	printf("aaa\n");
}
