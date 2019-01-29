/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:36:56 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/27 15:11:27 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	ft_opencl_start(t_mlx *mlx)
// {
// 	mlx->opencl->ret = clGetPlatformIDs(1, &mlx->opencl->platform_id, &mlx->opencl->ret_num_platform);
// 	mlx->opencl->ret = clGetDeviceIDs(mlx->opencl->platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &mlx->opencl->device_id, &mlx->opencl->ret_num_devices);
// 	mlx->opencl->context = clCreateContext(NULL, 1, &mlx->opencl->device_id, NULL, NULL, &mlx->opencl->ret);
// 	mlx->opencl->commant_queue = clCreateCommandQueue(mlx->opencl->context, mlx->opencl->device_id, 0, &mlx->opencl->ret);
// }

void	ft_thread()
{
	int i;
	
	i = 0;
	while(i < 20000000)
	{
		i++;
	}
}

int		main()
{
	pthread_t thread[4];
	int status;
	int status_addr;

	int x = 0;
	while (x < 4)
	{
		status = pthread_create(&thread[x], NULL, (void*)ft_thread, NULL);
		x++;
	}
	if (status != 0)
	{
		printf("error!\n");
		exit (0);
	}
	int i = 0;
	while (i < 20000000)
	{
		i++;
	}
	// ft_thread();
	// ft_thread();
	// ft_thread();
	// ft_thread();
	x = 0;
	while (x < 4)
	{
		status = pthread_join(thread[x], NULL);
		x++;
	}
	return 0;
}