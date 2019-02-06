/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:08:31 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/06 19:35:53 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_color_set(t_mlx *mlx)
{
	mlx->color[0] = 0xB68EE;
	mlx->color[1] = 0xFFA07A;
	mlx->color[2] = 0xDC143C;
	mlx->color[3] = 0xCD5C5C;
	mlx->color[4] = 0xF08080;
	mlx->color[5] = 0xFFC0CB;
	mlx->color[6] = 0x4B0082;
	mlx->color[7] = 0xFF4500;
	mlx->color[8] = 0xFF7F50;
	mlx->color[9] = 0xFFFACD;
	mlx->color[10] = 0xBDB76B;
	mlx->color[11] = 0xE6E6FA;
	mlx->color[12] = 0xEE82EE;
	mlx->color[13] = 0xFFF0F5;
	mlx->color[14] = 0xA0522D;
	mlx->color[15] = 0xF4A460;
	mlx->color[16] = 0xA52A2A;
	mlx->color[17] = 0xC0C0C0;
	mlx->color[18] = 0xBC8F8F;
	mlx->color[19] = 0x5F9EA0;
	mlx->color[20] = 0x9ACD32;
	mlx->color[21] = 0x98FB98;
	mlx->color[22] = 0xDB7093;
	mlx->color[23] = 0x9400D3;
	mlx->color[24] = 0xFFB6C1;
	mlx->color[25] = 0xE0FFFF;
	mlx->color[26] = 0xF5F5DC;
	mlx->color[27] = 0xBFF442;
	mlx->color[28] = 0x228B22;
	mlx->color[29] = 0x00FA9A;
	mlx->color[30] = 0xFFE4E1;
	mlx->color[31] = 0x9370DB;
}

void	ft_color_change(t_mlx *mlx, int dir)
{
	mlx->color_index += dir;
	if (mlx->color_index > 31)
		mlx->color_index = 0;
	if (mlx->color_index < 0)
		mlx->color_index = 31;
	ft_reset_image(mlx);
	ft_thread(mlx);
}
