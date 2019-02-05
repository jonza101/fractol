/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spider.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 19:27:38 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/05 15:47:07 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_spider(t_mlx * mlx)
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
		while(x < w)
		{
    		mlx->pr = 1.77 * (x - mlx->w / 2) / (mlx->w / 2 * mlx->zoom) + mlx->move_x;
    		mlx->pi = (y - mlx->h / 2) / (mlx->h / 2 * mlx->zoom) + mlx->move_y;
			mlx->new_re = mlx->pr;
			mlx->new_im = mlx->pi;
			i = 0;
			while (i < mlx->max_iteration)
			{
				mlx->old_re = mlx->pr;
				mlx->old_im = mlx->pi;				
				mlx->t_re = mlx->new_re;
				mlx->t_im = mlx->new_im;
				mlx->pr = (mlx->old_re * mlx->old_re) - (mlx->old_im * mlx->old_im) + mlx->new_re;
				mlx->pi = 2 * mlx->old_re * mlx->old_im + mlx->new_im;				
				mlx->new_re = mlx->t_re / 2 + mlx->pr;
				mlx->new_im = mlx->t_im / 2 + mlx->pi;
				if ((mlx->new_re * mlx->new_re + mlx->new_im * mlx->new_im) > 16)
					break ;
				i += 2;
    		}
			mlx->data[4 * x + mlx->w * 4 * y] = mlx_get_color_value(mlx->mlx, i * 0xB68EE * (i < mlx->max_iteration));
			x++;
		}
		y++;
	}
	pthread_exit(NULL);
}