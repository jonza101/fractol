/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:04:54 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/07 19:11:37 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int		ft_draw_temp(t_mlx *mlx, int xo, int yo, int x, int y)
// {
// 	// mlx->angle_x = abs(x - xo);
// 	// mlx->angle_y = abs(y - yo);
// }

void	ft_draw_line(t_mlx *mlx, int xo, int yo, int x, int y, int color)
{
	int error;

	mlx->angle_x = abs(x - xo);
	mlx->angle_y = abs(y - yo);
	error = mlx->angle_x - mlx->angle_y;
	if (x <  xo)
		mlx->delta_x = -1;
	else
		mlx->delta_x = 1;
	if (y < yo)
		mlx->delta_y = -1;
	else
		mlx->delta_y = 1;
	if (xo >= 0 && xo < mlx->w && yo >= 0 && yo < mlx->h)
			mlx->data[xo + yo * mlx->w] = mlx_get_color_value(mlx->mlx, color);
	while (xo != x || yo != y)
	{
		if (xo >= 0 && xo < mlx->w && yo >= 0 && yo < mlx->h)
			mlx->data[xo + yo * mlx->w] = mlx_get_color_value(mlx->mlx, color);
		if (error * 2 > -mlx->angle_y)
		{
			error -= mlx->angle_y;
			xo += mlx->delta_x;
		}
		else if (error * 2 < mlx->angle_x)
		{
			error += mlx->angle_x;
			yo += mlx->delta_y;
		}
		else
			break ;
	}
}

void	ft_fill_rect(t_mlx *mlx, int x, int y, int width, int height, int color)
{
	int xo;
	int yo;

	xo = x;
	yo = y;
	while (x < xo + width)
	{
		y = yo;
		while (y < yo + height)
		{
			mlx->data[x + y * mlx->w] = mlx_get_color_value(mlx->mlx, color);
			y++;
		}
		x++;
	}
}
