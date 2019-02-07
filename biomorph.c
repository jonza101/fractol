/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biomorph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:22:17 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/07 18:03:37 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_bio_temp(t_mlx *mlx, int *i)
{
	*i = 0;
	while ((fabs(mlx->pr) < mlx->max_iteration) &&
		(fabs(mlx->pi) < mlx->max_iteration) &&
			(*i < mlx->max_iteration))
	{
		mlx->new_re = mlx->pr;
		mlx->new_im = mlx->pi;
		mlx->pr = pow(mlx->pr, 3) - 3 * mlx->new_re *
			pow(mlx->new_im, 2) + mlx->c_x;
		mlx->pi = 3 * pow(mlx->new_re, 2) *
			mlx->new_im - pow(mlx->new_im, 3) + mlx->c_y;
		*i += 1;
	}
}

void	ft_biomorph(t_mlx *mlx)
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
			ft_bio_temp(mlx, &i);
			if (!(fabs(mlx->pr) >= 300) && !(fabs(mlx->pi) >= 10000))
				ft_fill_rect(mlx, x, y, 1, 1, i *
					mlx->color[mlx->color_index] * (i < mlx->max_iteration));
		}
	}
	pthread_exit(NULL);
}
