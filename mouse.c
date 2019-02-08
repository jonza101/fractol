/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:19:58 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/08 17:44:32 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mouse_cent(int x, int y, t_mlx *mlx)
{
	mlx->move_x -= (mlx->w / 2 - x) / (mlx->w / 2 * mlx->zoom) * 1.77;
	mlx->move_y -= (mlx->h / 2 - y) / (mlx->h / 2 * mlx->zoom);
}

void	ft_mouse_zoom_in(int x, int y, t_mlx *mlx)
{
	mlx->move_x -= (mlx->w / 2 - x) / (mlx->w / 2 * mlx->zoom) * 0.35;
	mlx->move_y -= (mlx->h / 2 - y) / (mlx->h / 2 * mlx->zoom) * 0.2;
}

void	ft_mouse_zoom_out(int x, int y, t_mlx *mlx)
{
	mlx->move_x += (mlx->w / 2 - x) / (mlx->w / 2 * mlx->zoom) * 0.35;
	mlx->move_y += (mlx->h / 2 - y) / (mlx->h / 2 * mlx->zoom) * 0.2;
}

void	ft_bio_change(int x, int y, t_mlx *mlx)
{
	mlx->c_x = ((double)x - 960.0) / 480.0;
	mlx->c_y = ((double)y - 540.0) / 270.0;
	ft_reset_image(mlx);
	ft_thread(mlx);
}

void	ft_julia_change(int x, int y, t_mlx *mlx)
{
	mlx->c_re = ((double)x - 960.0) / 480.0;
	mlx->c_im = ((double)y - 540.0) / 270.0;
	ft_reset_image(mlx);
	ft_thread(mlx);
}
