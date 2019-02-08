/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:29:26 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/08 15:12:12 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_mes(void)
{
	ft_putstr("Usage: ./fractol [fractal]\nAvailable fractals:\n");
	ft_putstr(" - Mandelbrot (m)\n - Julia (j)\n - Spider (s)\n");
	ft_putstr(" - Burning Ship (bs)\n - Thorn (t)\n - Biomorph (b)\n");
	exit(0);
}

void	ft_reset_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, mlx->w, mlx->h);
	mlx_clear_window(mlx->mlx, mlx->win);
}

void	ft_start(t_mlx *mlx)
{
	mlx->w = 1920;
	mlx->h = 1080;
	mlx->zoom = (mlx->func_index == 1) ? 0.75 : 0.5;
	mlx->move_x = (mlx->func_index == 2) ? -0.5 : 0;
	mlx->move_y = 0;
	mlx->c_re = -0.7;
	mlx->c_im = 0.27015;
	mlx->c_x = 0.5;
	mlx->c_y = 0;
	mlx->max_iteration = 100;
	mlx->julia_change_trigger = 0;
	mlx->bio_change_trigger = 0;
}

void	ft_key_press_temp(int keycode, t_mlx *mlx)
{
	if (keycode == 123)
		mlx->move_x -= 0.25 / mlx->zoom;
	if (keycode == 124)
		mlx->move_x += 0.25 / mlx->zoom;
	if (keycode == 125)
		mlx->move_y += 0.25 / mlx->zoom;
	if (keycode == 126)
		mlx->move_y -= 0.25 / mlx->zoom;
	if (keycode == 43)
		ft_fractal_change(mlx, -1);
	if (keycode == 47)
		ft_fractal_change(mlx, 1);
	if (keycode == 78)
		ft_color_change(mlx, -1);
	if (keycode == 69)
		ft_color_change(mlx, 1);
}

void	ft_temp_change(int button, t_mlx *mlx)
{
	if (button == 2)
	{
		if (mlx->func_index == 5)
			mlx->bio_change_trigger = !mlx->bio_change_trigger;
		if (mlx->func_index == 1)
			mlx->julia_change_trigger = !mlx->julia_change_trigger;
	}
}
