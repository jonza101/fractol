/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:10:59 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/06 19:38:34 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_mlx *mlx)
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
			mlx->new_re = 1.77 * (x - mlx->w / 2) / (mlx->zoom * mlx->w / 2) + mlx->move_x;
    		mlx->new_im = (y - mlx->h / 2) / (mlx->zoom * mlx->h / 2) + mlx->move_y;
			i = 0;
			while (i < mlx->max_iteration)
			{
    			mlx->old_re = mlx->new_re;
    			mlx->old_im = mlx->new_im;
    			mlx->new_re = mlx->old_re * mlx->old_re - mlx->old_im * mlx->old_im + mlx->c_re;
      			mlx->new_im = 2 * mlx->old_re * mlx->old_im + mlx->c_im;
      			if((mlx->new_re * mlx->new_re + mlx->new_im * mlx->new_im) > 4)
					break;
				i++;
    		}
			mlx->data[x + mlx->w * y] = mlx_get_color_value(mlx->mlx, i * mlx->color[mlx->color_index] * (i < mlx->max_iteration));
			x++;
		}
		y++;
	}
	pthread_exit(0);
}
