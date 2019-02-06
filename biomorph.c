/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biomorph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:22:17 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/06 19:38:18 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_biomorph(t_mlx * mlx)
{
	int x;
	int xo;
	int y;
	int i;
	int w;
	double cx = 0.5;
	double cy = 0;

	y = 0;
	xo = (mlx->w / MAX_THR) * (mlx->index % MAX_THR);
	w = (mlx->w / MAX_THR) * (mlx->index % MAX_THR) + (mlx->w / MAX_THR);
	while (y < mlx->h)
	{
		x = xo;
		while(x < w)
		{
    		mlx->pr = 1.77 * (x - mlx->w / 2) / (mlx->w / 2 * mlx->zoom) + mlx->move_x;
    		mlx->pi = (y - mlx->h / 2) / (mlx->h / 2 * mlx->zoom) + mlx->move_y;
			i = 0;
			while ((fabs(mlx->pr) < mlx->max_iteration) && (fabs(mlx->pi) < mlx->max_iteration) && (i < mlx->max_iteration))
			{
				mlx->new_re = mlx->pr;
				mlx->new_im = mlx->pi;
				mlx->pr = pow(mlx->pr, 3) - 3 * mlx->new_re * pow(mlx->new_im, 2) + cx;
				mlx->pi = 3 * pow(mlx->new_re, 2) * mlx->new_im - pow(mlx->new_im, 3) + cy;
				i++;
			}
			if (!(fabs(mlx->pr) >= 300) && !(fabs(mlx->pi) >= 10000))
				ft_fill_rect(mlx, x, y, 1, 1, i * mlx->color[mlx->color_index] * (i < mlx->max_iteration));
			x++;
		}
		y++;
	}
	pthread_exit(NULL);
}