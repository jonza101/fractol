/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:31:47 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/27 18:25:46 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_mlx *mlx)
{
	int x;
	int y;
	int i;
	int w;

	y = 0;
	if (mlx->index == 0)
		w = mlx->julia[mlx->index]->w / 2;
	else
		w = mlx->julia[mlx->index]->w;
	while (y < mlx->julia[mlx->index]->h)
	{
		x = mlx->julia[mlx->index]->w / 2 * mlx->index;
		while(x < w)
		{
			mlx->julia[mlx->index]->new_re = 1.5 * (x - mlx->julia[mlx->index]->w / 2) / (0.5 * mlx->julia[mlx->index]->zoom * mlx->julia[mlx->index]->w) + mlx->julia[mlx->index]->move_x;
    		mlx->julia[mlx->index]->new_im = (y - mlx->julia[mlx->index]->h / 2) / (0.5 * mlx->julia[mlx->index]->zoom * mlx->julia[mlx->index]->h) + mlx->julia[mlx->index]->move_y;
			i = 0;
			while (i < mlx->julia[mlx->index]->max_iteration)
			{
    			mlx->julia[mlx->index]->old_re = mlx->julia[mlx->index]->new_re;
    			mlx->julia[mlx->index]->old_im = mlx->julia[mlx->index]->new_im;
    			mlx->julia[mlx->index]->new_re = mlx->julia[mlx->index]->old_re * mlx->julia[mlx->index]->old_re - mlx->julia[mlx->index]->old_im * mlx->julia[mlx->index]->old_im + mlx->julia[mlx->index]->c_re;
      			mlx->julia[mlx->index]->new_im = 2 * mlx->julia[mlx->index]->old_re * mlx->julia[mlx->index]->old_im + mlx->julia[mlx->index]->c_im;
      			if((mlx->julia[mlx->index]->new_re * mlx->julia[mlx->index]->new_re + mlx->julia[mlx->index]->new_im * mlx->julia[mlx->index]->new_im) > 4)
					break;
				i++;
    		}
			mlx->data[4 * x + 2880 * 4 * y] = mlx_get_color_value(mlx->mlx, i * (i % mlx->julia[mlx->index]->max_iteration)); //i * (i % mlx->julia[mlx->index]->max_iteration) || i * 0xB68EE * (i < mlx->julia[mlx->index]->max_iteration)
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}