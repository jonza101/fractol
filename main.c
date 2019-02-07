/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:16:25 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/07 19:06:50 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_mes()
{
	ft_putstr("Usage: ./fractol [fractal]\nAvailable fractals:\n - Mandelbrot (m)\n - Julia (j)\n - Spider (s)\n - Burning Ship (bs)\n - Thorn (t)\n - Biomorph (b)\n");
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
}

void	ft_thread(t_mlx *mlx)
{
	t_mlx		**copy;
	pthread_t	thread[MAX_THR];

	int i = 0;
	copy = (t_mlx**)malloc(sizeof(t_mlx*) * MAX_THR);
	while (i < MAX_THR)
	{
		copy[i] = (t_mlx*)malloc(sizeof(t_mlx));
		copy[i] = ft_memcpy(copy[i], mlx, sizeof(t_mlx));
		copy[i]->index = i;
		copy[i]->w = 1920;
		copy[i]->h = 1080;
		if ((pthread_create(&thread[i], NULL, (void*)mlx->func[mlx->func_index], (void*)copy[i])) != 0)
		{
			ft_putstr("Thread error!\n");
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i < MAX_THR)
	{
		if ((pthread_join(thread[i], NULL)) != 0)
		{
			ft_putstr("Thread error!\n");
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i < MAX_THR)
	{
		free(copy[i]);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
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
		ft_reset_image(mlx);
		ft_thread(mlx);
	}
	if (button == 5)
	{
		(mlx->point_zoom == 1) ? ft_mouse_zoom_out(x, y, mlx) : 1;
		mlx->zoom /= 1.25;
		ft_reset_image(mlx);
		ft_thread(mlx);
	}
	if (button == 3)
		mlx->point_zoom = !mlx->point_zoom;
	return (0);
}

int     key_press(int keycode, t_mlx *mlx)
{
	mlx->w = 1920;
	mlx->h = 1080;
    if (keycode == 53)
        exit(0);
	if (keycode == 15)
	{
		ft_start(mlx);
		ft_reset_image(mlx);
		ft_thread(mlx);
	}
	if (keycode == 24)
	{
		mlx->max_iteration += 10;
		ft_reset_image(mlx);
		ft_thread(mlx);
	}
	if (keycode == 27)
	{
		mlx->max_iteration -= 10;
		mlx->max_iteration = (mlx->max_iteration <= 0) ? 10 : mlx->max_iteration;
		ft_reset_image(mlx);
		ft_thread(mlx);
	}
	if (keycode == 123)
	{
		mlx->move_x -= 0.25 / mlx->zoom;
		ft_reset_image(mlx);
		ft_thread(mlx);
	}
	if (keycode == 124)
	{
		mlx->move_x += 0.25 / mlx->zoom;
		ft_reset_image(mlx);
		ft_thread(mlx);
		
	}
	if (keycode == 125)
	{
		mlx->move_y += 0.25 / mlx->zoom;
		ft_reset_image(mlx);
		ft_thread(mlx);
	}
	if (keycode == 126)
	{
		mlx->move_y -= 0.25 / mlx->zoom;
		ft_reset_image(mlx);
		ft_thread(mlx);
	}
	if (keycode == 43)
		ft_fractal_change(mlx, -1);
	if (keycode == 47)
		ft_fractal_change(mlx, 1);
	if (keycode == 78)
		ft_color_change(mlx, -1);
	if (keycode == 69)
		ft_color_change(mlx, 1);

	if (keycode == 0)
	{
		mlx->c_re -= 0.0005;
		mlx->c_x -= 0.0025;
		ft_reset_image(mlx);
		ft_thread(mlx);
	}
	if (keycode == 2)
	{
		mlx->c_re += 0.0005;
		mlx->c_x += 0.0025;
		ft_reset_image(mlx);
		ft_thread(mlx);
	}
	if (keycode == 1)
	{
		mlx->c_im -= 0.0005;
		mlx->c_y -= 0.0025;
		ft_reset_image(mlx);
		ft_thread(mlx);
	}
	if (keycode == 13)
	{
		mlx->c_im += 0.0005;
		mlx->c_y += 0.0025;
		ft_reset_image(mlx);
		ft_thread(mlx);
	}
    return (0);
}

int     main(int argc, char const *argv[])
{
    t_mlx	*mlx;

	if (argc != 2)
		ft_error_mes();
    mlx = malloc(sizeof(t_mlx));
	mlx->fractol = ft_strdup(argv[1]);
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "TEST");
	mlx->img = mlx_new_image(mlx->mlx, 1920, 1080);
	mlx->data = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);

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
    mlx_loop(mlx);
    return 0;
}
