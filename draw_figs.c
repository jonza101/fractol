/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:04:54 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/04 16:49:09 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_line(t_mlx *mlx, int xo, int yo, int x, int y, int color)
{
	int angle_x;
	int angle_y;
	int error;
	int delta_x;
	int delta_y;

	angle_x = abs(x - xo);
	angle_y = abs(y - yo);
	error = angle_x - angle_y;
	if (x <  xo)
		delta_x = -1;
	else
		delta_x = 1;
	if (y < yo)
		delta_y = -1;
	else
		delta_y = 1;
	if (xo >= 0 && xo < mlx->w && yo >= 0 && yo < mlx->h)
			mlx->data[4 * xo + 4 * yo * mlx->w] = mlx_get_color_value(mlx->mlx, color);
	while (xo != x || yo != y)
	{
		if (xo >= 0 && xo < mlx->w && yo >= 0 && yo < mlx->h)
			mlx->data[4 * xo + 4 * yo * mlx->w] = mlx_get_color_value(mlx->mlx, color);
		if (error * 2 > -angle_y)
		{
			error -= angle_y;
			xo += delta_x;
		}
		else if (error * 2 < angle_x)
		{
			error += angle_x;
			yo += delta_y;
		}
		else
			break ;
	}
}

void	ft_draw_rect(t_mlx *mlx, int x, int y, int width, int height, int color)
{
	ft_draw_line(mlx, x, y, x + width, y, color);
	ft_draw_line(mlx, x + width, y, x + width, y + height, color);
	ft_draw_line(mlx, x + width, y + height, x, y + height, color);
	ft_draw_line(mlx, x, y + height, x, y, color);
}
