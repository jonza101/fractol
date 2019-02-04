/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:19:58 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/04 18:26:56 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	ft_mouse_cent(int x, int y, t_mlx *mlx)
{
	mlx->move_x -= (mlx->w / 2 - x) / (mlx->w / 2 * mlx->zoom) * 1.77;
	mlx->move_y -= (mlx->h / 2 - y) / (mlx->h / 2 * mlx->zoom);
	ft_thread(mlx);
}

// void	ft_mouse_zoom_in(int x, int y, t_mlx *mlx)
// {
// 	mlx->move_x -= (mlx->w / 2 - x) / (mlx->w / 2 * mlx->zoom) / 1.25;
// 	mlx->move_y -= (mlx->h / 2 - y) / (mlx->h / 2 * mlx->zoom) * 0.25;
// 	ft_thread(mlx);
// }

// void	ft_mouse_zoom_out(int x, int y, t_mlx *mlx)
// {
// 	mlx->move_x -= (mlx->w / 2 - x) / (mlx->w / 2 * mlx->zoom) / 1.25;
// 	mlx->move_y += (mlx->h / 2 - y) / (mlx->h / 2 * mlx->zoom) * 0.25;
// 	ft_thread(mlx);
// }

void	ft_julia_change(int x, int y, t_mlx *mlx)
{
	if (x < mlx->w / 2)
	{
		mlx->c_re += 0.01;
		mlx->c_im += 0.001;
	}
	else
	{
		mlx->c_re -= 0.01;
		mlx->c_im -= 0.001;
	}
}
