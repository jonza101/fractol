/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:59:56 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/07 18:40:34 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot_temp(t_mlx *mlx, int *i)
{
	mlx->new_re = 0;
	mlx->new_im = 0;
	mlx->old_re = 0;
	mlx->old_im = 0;
	*i = 0;
	while (*i < mlx->max_iteration)
	{
		mlx->old_re = mlx->new_re;
		mlx->old_im = mlx->new_im;
		mlx->new_re = mlx->old_re * mlx->old_re -
			mlx->old_im * mlx->old_im + mlx->pr;
		mlx->new_im = 2 * mlx->old_re * mlx->old_im + mlx->pi;
		if ((mlx->new_re * mlx->new_re + mlx->new_im * mlx->new_im) > 4)
			break ;
		*i += 1;
	}
}

void	ft_mandelbrot(t_mlx *mlx)
{
	int x;
	int xo;
	int y;
	int i;
	int w;

	y = -1;
	xo = (mlx->w / MAX_THR) * (mlx->index % MAX_THR);
	w = (mlx->w / MAX_THR) * (mlx->index % MAX_THR) + (mlx->w / MAX_THR);
	while (++y < mlx->h)
	{
		x = xo - 1;
		while (++x < w)
		{
			mlx->pr = 1.77 * (x - mlx->w / 2) /
				(mlx->w / 2 * mlx->zoom) + mlx->move_x;
			mlx->pi = (y - mlx->h / 2) /
				(mlx->h / 2 * mlx->zoom) + mlx->move_y;
			ft_mandelbrot_temp(mlx, &i);
			mlx->data[x + mlx->w * y] = mlx_get_color_value(mlx->mlx, i *
				mlx->color[mlx->color_index] * (i < mlx->max_iteration));
		}
	}
	pthread_exit(NULL);
}
