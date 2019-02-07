/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:19:58 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/07 18:41:05 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mouse_cent(int x, int y, t_mlx *mlx)
{
	mlx->move_x -= (mlx->w / 2 - x) / (mlx->w / 2 * mlx->zoom) * 1.77;
	mlx->move_y -= (mlx->h / 2 - y) / (mlx->h / 2 * mlx->zoom);
	ft_thread(mlx);
}

void	ft_mouse_zoom_in(int x, int y, t_mlx *mlx)
{
	mlx->move_x -= (mlx->w / 2 - x) / (mlx->w / 2 * mlx->zoom) * 0.35;
	mlx->move_y -= (mlx->h / 2 - y) / (mlx->h / 2 * mlx->zoom) * 0.2;
	ft_thread(mlx);
}

void	ft_mouse_zoom_out(int x, int y, t_mlx *mlx)
{
	mlx->move_x += (mlx->w / 2 - x) / (mlx->w / 2 * mlx->zoom) * 0.35;
	mlx->move_y += (mlx->h / 2 - y) / (mlx->h / 2 * mlx->zoom) * 0.2;
	ft_thread(mlx);
}
