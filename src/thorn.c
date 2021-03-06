/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thorn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:02:26 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/07 18:48:22 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_thorn_temp(t_mlx *mlx, int *i)
{
	mlx->new_re = 1;
	mlx->new_im = 1;
	*i = 0;
	while (((mlx->pr * mlx->pr) + (mlx->pi * mlx->pi) < mlx->max_iteration))
	{
		mlx->old_re = mlx->pr;
		mlx->old_im = mlx->pi;
		mlx->pr = mlx->old_re / cos(mlx->old_im) + mlx->new_re;
		mlx->pi = mlx->old_im / cos(mlx->old_re) + mlx->old_im;
		*i += 1;
	}
}

void	ft_thorn(t_mlx *mlx)
{
	int x;
	int xo;
	int y;
	int i;
	int w;

	y = 0;
	xo = (mlx->w / MAX_THR) * (mlx->index % MAX_THR);
	w = (mlx->w / MAX_THR) * (mlx->index % MAX_THR) + (mlx->w / MAX_THR);
	while (y < mlx->h)
	{
		x = xo;
		while (x < w)
		{
			mlx->pr = 1.77 * (x - mlx->w / 2) /
				(mlx->w / 2 * mlx->zoom) + mlx->move_x;
			mlx->pi = (y - mlx->h / 2) / (mlx->h / 2 * mlx->zoom) + mlx->move_y;
			ft_thorn_temp(mlx, &i);
			mlx->data[x + y * mlx->w] = mlx_get_color_value(mlx->mlx, i *
				mlx->color[mlx->color_index] * (i < mlx->max_iteration));
			x++;
		}
		y++;
	}
	pthread_exit(NULL);
}
