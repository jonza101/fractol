/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:16:25 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/29 15:39:14 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_thread(t_mlx *mlx)
{
	t_mlx		*copy[MAX_THR];
	pthread_t	thread[MAX_THR];
	int status;

	int i = 0;
	while (i < MAX_THR)
	{
		copy[i] = malloc(sizeof(t_mlx));
		ft_memcpy(copy[i], mlx, sizeof(t_mlx));
		copy[i]->index = i;
		status = pthread_create(&thread[i], NULL, (void*)ft_julia, (void*)copy[i]);
		i++;
	}
	// i = 0;
	// while (i < MAX_THR)
	// {
	// 	status = pthread_join(thread[i], NULL);
	// 	i++;
	// }
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	// if (button == 1)
	// {
	// 	mlx->move_x += 2880 / (x - 2880) / mlx->zoom;
	// 	mlx->move_y += 1620 / (1620 - y) / mlx->zoom;
	// 	printf("%f\n", mlx->move_x);
	// 	ft_mandelbrot(mlx);
	// }
	if (button == 4)
	{
		mlx->zoom += mlx->zoom / 2;
		// if (mlx->i_mand == 1)
		// 	ft_mandelbrot(mlx);
		// if (mlx->i_julia == 1)
		ft_thread(mlx);
	}
	if (button == 5)
	{
		mlx->zoom /= 1.25;
		if (mlx->i_mand == 1)
			ft_mandelbrot(mlx);
		if (mlx->i_julia == 1)
			ft_thread(mlx);
	}
	return (0);
}

int     key_press(int keycode, t_mlx *mlx)
{
    if (keycode == 53)
        exit(0);
	if (keycode == 24)
	{
		mlx->max_iteration += 10;
		ft_thread(mlx);
	}
	if (keycode == 27)
	{
		mlx->max_iteration -= 10;
		if (mlx->max_iteration <= 0)
			mlx->max_iteration = 10;
		ft_thread(mlx);
	}
	if (keycode == 123)
	{
		mlx->move_x -= 0.5 / mlx->zoom;
		if (mlx->i_mand == 1)
			ft_mandelbrot(mlx);
		else
			ft_thread(mlx);
	}
	if (keycode == 124)
	{
		mlx->move_x += 0.5 / mlx->zoom;
		if (mlx->i_mand == 1)
			ft_mandelbrot(mlx);
		else
			ft_thread(mlx);
		
	}
	if (keycode == 125)
	{
		mlx->move_y += 0.5 / mlx->zoom;
		if (mlx->i_mand)
			ft_mandelbrot(mlx);
		else
			ft_thread(mlx);
	}
	if (keycode == 126)
	{
		mlx->move_y -= 0.5 / mlx->zoom;
		if (mlx->i_mand == 1)
			ft_mandelbrot(mlx);
		else
			ft_thread(mlx);
	}
	if (keycode == 34)
		printf("iter info: %d\n", mlx->max_iteration);
    return (0);
}

void	ft_start(t_mlx *mlx)
{
	mlx->h = 1620;
	mlx->w = 2880;
	mlx->zoom = 0.75;
	mlx->move_x = 0;
	mlx->move_y = 0;
	mlx->c_re = -0.7;
	mlx->c_im = 0.27015;
	mlx->max_iteration = 150;
	mlx->index = 0;
	mlx->i_julia = 1;
	mlx->i_mand = 0;
}

int     main(int argc, char const *argv[])
{
    t_mlx *mlx;

    mlx = malloc(sizeof(t_mlx));
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, 2880, 1620, "TEST");
	mlx->img = mlx_new_image(mlx->mlx, 2880, 1620);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);
	
	ft_start(mlx);
	ft_thread(mlx);

    mlx_hook(mlx->win, 2, 1, key_press, mlx);
	mlx_hook(mlx->win, 4, 1, mouse_press, mlx);
    mlx_loop(mlx);
    return 0;
}
