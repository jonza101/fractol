/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:17:02 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/06 19:45:37 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include "libft/libft.h"

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

typedef	struct	s_triangle
{
	int			x;
	int			y;
}				t_triangle;

typedef struct  s_mlx
{
    void    	*mlx;
    void    	*win;

    void    	*img;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;

	int			index;
	int			threads;

	int			func_index;
	char		*fractol;
	void		*func[8];

	int			color[32];
	int			color_index;

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
void	ft_newton(t_mlx *mlx);
void	ft_thorn(t_mlx *mlx);
void	ft_triangle_start(t_mlx *mlx);
void	ft_biomorph(t_mlx * mlx);

void	ft_fill_funcs(t_mlx *mlx);
void	ft_fractal_check(t_mlx *mlx);

void	ft_start(t_mlx *mlx);
void	ft_fractal_change(t_mlx *mlx, int dir);

void	ft_color_set(t_mlx *mlx);
void	ft_color_change(t_mlx *mlx, int dir);

void	ft_draw_line(t_mlx *mlx, int xo, int yo, int x, int y, int color);
void	ft_draw_rect(t_mlx *mlx, int x, int y, int width, int height, int color);
void	ft_fill_rect(t_mlx *mlx, int x, int y, int width, int height, int color);

void	ft_thread(t_mlx *mlx);

void	ft_mouse_cent(int x, int y, t_mlx *mlx);
void	ft_mouse_zoom_in(int x, int y, t_mlx *mlx);
void	ft_mouse_zoom_out(int x, int y, t_mlx *mlx);

void	ft_julia_change(int x, int y, t_mlx *mlx);

void	ft_info(t_mlx *mlx);
void	ft_reset_image(t_mlx *mlx);

void	ft_compile_cl(t_mlx *mlx);

void	ft_test();

#endif
