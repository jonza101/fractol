/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:10:59 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/29 15:26:39 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_mlx *mlx)
{
	int x;
	int y;
	int i;
	int w;
	int h;

	y = 810 * (mlx->index / (MAX_THR / 2));
	h = 810 * (mlx->index / (MAX_THR / 2)) + 810;
	w = 360 * (mlx->index % (MAX_THR / 2)) + 360;
	while (y < h)
	{
		x = 360 * (mlx->index % (MAX_THR / 2));
		while(x < w)
		{
			mlx->new_re = 1.5 * (x - mlx->w / 2) / (0.5 * mlx->zoom * mlx->w) + mlx->move_x;
    		mlx->new_im = (y - mlx->h / 2) / (0.5 * mlx->zoom * mlx->h) + mlx->move_y;
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
			mlx->data[4 * x + 2880 * 4 * y] = mlx_get_color_value(mlx->mlx, i * (i % mlx->max_iteration)); //i * (i % mlx->max_iteration) || i * 0xB68EE * (i < mlx->max_iteration)
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
