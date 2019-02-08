/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:04:54 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/08 14:36:38 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fill_rect(t_mlx *mlx, int x, int y)
{
	int xo;
	int yo;

	xo = x;
	yo = y;
	while (x < xo + 1)
	{
		y = yo;
		while (y < yo + 1)
		{
			mlx->data[x + y * mlx->w] =
				mlx_get_color_value(mlx->mlx, mlx->rect_color);
			y++;
		}
		x++;
	}
}
