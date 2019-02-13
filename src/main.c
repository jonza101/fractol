/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:16:25 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/08 15:59:51 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->bio_change_trigger == 1)
		ft_bio_change(x, y, mlx);
	if (mlx->julia_change_trigger == 1)
		ft_julia_change(x, y, mlx);
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	mlx->w = 1920;
	mlx->h = 1080;
	if (button == 1)
	{
		ft_reset_image(mlx);
		ft_mouse_cent(x, y, mlx);
	}
	if (button == 4)
	{
		(mlx->point_zoom == 1) ? ft_mouse_zoom_in(x, y, mlx) : 1;
		mlx->zoom *= 1.25;
	}
	if (button == 5)
	{
		mlx->zoom /= 1.25;
		(mlx->point_zoom == 1) ? ft_mouse_zoom_out(x, y, mlx) : 1;
	}
	ft_temp_change(button, mlx);
	if (button == 3)
		mlx->point_zoom = !mlx->point_zoom;
	ft_reset_image(mlx);
	ft_thread(mlx);
	return (0);
}

int		key_press(int keycode, t_mlx *mlx)
{
	mlx->w = 1920;
	mlx->h = 1080;
	if (keycode == 53)
		exit(0);
	if (keycode == 15)
		ft_start(mlx);
	if (keycode == 24)
		mlx->max_iteration += 10;
	if (keycode == 27)
	{
		mlx->max_iteration -= 10;
		mlx->max_iteration = (mlx->max_iteration <= 0)
			? 10 : mlx->max_iteration;
	}
	ft_key_press_temp(keycode, mlx);
	ft_reset_image(mlx);
	ft_thread(mlx);
	return (0);
}

int		main(int argc, char const *argv[])
{
	t_mlx	*mlx;

	if (argc != 2)
		ft_error_mes();
	mlx = malloc(sizeof(t_mlx));
	mlx->fractol = ft_strdup(argv[1]);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "TEST");
	mlx->img = mlx_new_image(mlx->mlx, 1920, 1080);
	mlx->data = (int*)mlx_get_data_addr(mlx->img,
		&mlx->bpp, &mlx->size_line, &mlx->endian);
	ft_fill_funcs(mlx);
	ft_fractal_check(mlx);
	ft_start(mlx);
	ft_color_set(mlx);
	mlx->color_index = 0;
	mlx->point_zoom = 0;
	(mlx->func_index < 0) ? ft_error_mes() : 1;
	ft_thread(mlx);
	mlx_hook(mlx->win, 2, 1, key_press, mlx);
	mlx_hook(mlx->win, 4, 1, mouse_press, mlx);
	mlx_hook(mlx->win, 6, 1, mouse_move, mlx);
	mlx_loop(mlx);
	return (0);
}
