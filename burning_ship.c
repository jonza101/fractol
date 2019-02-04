/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:01:57 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/04 15:55:06 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_ship(t_mlx *mlx)
{
	int x;
	int y;
	int i;
	int w;
	int h;

	y = 0;
	h = mlx->h;
	w = (mlx->w / (MAX_THR / 1)) * (mlx->index % (MAX_THR / 1)) + (mlx->w / (MAX_THR / 1));
	while (y < h)
	{
		x = (mlx->w / (MAX_THR / 1)) * (mlx->index % (MAX_THR / 1));
		while (x < w)
		{
			i = 0;
			mlx->pr = 1.77 * (x - mlx->w / 2) / (mlx->w / 2 * mlx->zoom) + mlx->move_x - 0.2;
			mlx->pi = (y - mlx->h / 2) / (mlx->h / 2 * mlx->zoom) + mlx->move_y - 0.3;
			mlx->new_re = 0;
			mlx->new_im = 0;

			while (i < mlx->max_iteration)
			{
				mlx->old_re = mlx->new_re;
				mlx->old_im = mlx->new_im;
				mlx->new_re = (pow(mlx->old_re, 2) - pow(mlx->old_im, 2) + mlx->pr);
				mlx->new_im = 2 * fabsl(mlx->old_re * mlx->old_im) + mlx->pi;
				i++;
				if ((mlx->new_re * mlx->new_re + mlx->new_im * mlx->new_im) > 4)
					break ;
			}
			mlx->data[4 * x + mlx->w * 4 * y] = mlx_get_color_value(mlx->mlx, i * 0xB68EE * (i < mlx->max_iteration));
			x++;
		}
		y++;
	}
	pthread_exit(0);
}
