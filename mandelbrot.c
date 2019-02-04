/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:59:56 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/04 14:58:36 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_mlx *mlx)
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
		while(x < w)
		{
    		mlx->pr = 1.77 * (x - mlx->w / 2) / (mlx->w / 2 * mlx->zoom) + mlx->move_x;
    		mlx->pi = (y - mlx->h / 2) / (mlx->h / 2 * mlx->zoom) + mlx->move_y;
    		mlx->new_re = 0;
			mlx->new_im = 0;
			mlx->old_re = 0;
			mlx->old_im = 0;
			i = 0;
			while (i < mlx->max_iteration)
			{
    			mlx->old_re = mlx->new_re;
    			mlx->old_im = mlx->new_im;
    			mlx->new_re = mlx->old_re * mlx->old_re - mlx->old_im * mlx->old_im + mlx->pr;
      			mlx->new_im = 2 * mlx->old_re * mlx->old_im + mlx->pi;
      			if((mlx->new_re * mlx->new_re + mlx->new_im * mlx->new_im) > 4)
					break;
				i++;
    		}
			mlx->data[4 * x + mlx->w * 4 * y] = mlx_get_color_value(mlx->mlx, i * 0xB68EE * (i < mlx->max_iteration)); //i * (i % mlx->max_iteration) || i * 0xB68EE * (i < mlx->max_iteration)
			x++;
		}
		y++;
	}
	pthread_exit(NULL);
}
