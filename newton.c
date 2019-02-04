/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:38:12 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/04 16:58:41 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_newton(t_mlx *mlx)
{
	int x;
	int y;
	int i;
	int w;
	int h;
	double p;

	y = 0;
	h = mlx->h;
	w = (mlx->w / (MAX_THR / 1)) * (mlx->index % (MAX_THR / 1)) + (mlx->w / (MAX_THR / 1));
	while (y < h)
	{
		x = (mlx->w / (MAX_THR / 1)) * (mlx->index % (MAX_THR / 1));
		while(x < w)
		{
    		i = 0;
			mlx->pr = 1.77 * (x - mlx->w / 2) / (mlx->w / 2 * mlx->zoom) + mlx->move_x;
			mlx->pi = (y - mlx->h / 2) / (mlx->h / 2 * mlx->zoom) + mlx->move_y;

			mlx->new_re = mlx->pr;
			mlx->new_im = mlx->pi;

			while ((pow(mlx->pr, 2) + pow(mlx->pi, 2)) < mlx->max_iteration)
			{
				mlx->old_re = mlx->pr;
				mlx->old_im = mlx->pi;

				p = pow(pow(mlx->old_re, 2) + pow(mlx->old_im, 2), 2);

				mlx->pr = 2 / 3 * mlx->old_re + (pow(mlx->old_re, 2) - pow(mlx->old_im, 2)) / (3 * p);
				mlx->pi = 2 / 3 * mlx->old_im * (1 - mlx->old_re / p);

				mlx->new_re = fabs(mlx->old_re - mlx->pr);
				mlx->new_im = fabs(mlx->old_im - mlx->pi);

				i++;
			}
			ft_draw_rect(mlx, x, y, 1, 1, (i * 25) % 255);
			x++;
		}
		y++;
	}
	pthread_exit(NULL);
}
