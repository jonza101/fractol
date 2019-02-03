/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:17:02 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/03 19:37:51 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include "get_next_line/get_next_line.h"

#include <pthread.h>
#include <math.h>
#include <stdio.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

#include "OpenCL/cl.h"
#include "OpenCL/opencl.h"

#include <stdlib.h>

#define MAX_THR 16

typedef	struct	s_opencl
{
	cl_int				ret;
	cl_platform_id		platform_id;
	cl_uint				ret_num_platform;
	cl_device_id		device_id;
	cl_uint				ret_num_devices;
	cl_context			context;
	cl_command_queue	commant_queue;
}				t_opencl;

typedef struct  s_mlx
{
    void    	*mlx;
    void    	*win;

    void    	*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;

	int			index;
	int			threads;

	int			h;
	int			w;

	int			max_iteration;
	int			prev_iter;
	double		zoom;
	double		move_x;
	double		move_y;

	double		c_re;
	double		c_im;
	double		pr;
	double		pi;
	double		new_re;
	double		new_im;
	double		old_re;
	double		old_im;
	double		t_re;
	double		t_im;

	int			julia_change_trigger;

	t_opencl	*kernel;
}               t_mlx;

void	ft_mandelbrot(t_mlx *mlx);
void	ft_julia(t_mlx *mlx);
void	ft_ship(t_mlx *mlx);
void	ft_spider(t_mlx * mlx);

void	ft_thread(t_mlx *mlx);

void	ft_mouse_cent(int x, int y, t_mlx *mlx);
void	ft_mouse_zoom_in(int x, int y, t_mlx *mlx);
void	ft_mouse_zoom_out(int x, int y, t_mlx *mlx);

void	ft_julia_change(int x, int y, t_mlx *mlx);

void	ft_info(t_mlx *mlx);

//void	ft_start_cl(t_mlx *mlx);
void	ft_compile_cl(t_mlx *mlx);

void	ft_test();

#endif
