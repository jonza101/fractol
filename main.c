/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:16:25 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/04 18:48:40 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_info(t_mlx *mlx)
{
	printf("\nh %d\n", mlx->h);
	printf("w %d\n", mlx->w);
	printf("zoom %f\n", mlx->zoom);
	printf("move_x %f\n", mlx->move_x);
	printf("move_y %f\n", mlx->move_y);
	printf("iter %d\n", mlx->max_iteration);
	printf("mlx->julia_change_trigger %d\n", mlx->julia_change_trigger);
	printf("c_re %f\n", mlx->c_re);
	printf("c_im %f\n\n", mlx->c_im);
}

void	ft_start(t_mlx *mlx)
{
	mlx->w = 1920;
	mlx->h = 1080;
	mlx->zoom = 0.5;
	mlx->move_x = 0;
	mlx->move_y = 0;
	mlx->c_re = -0.7;
	mlx->c_im = 0.27015;
	mlx->max_iteration = 100;
	mlx->julia_change_trigger = 0;
}

void	ft_thread(t_mlx *mlx)
{
	t_mlx		**copy;
	pthread_t	thread[MAX_THR];
	int status;

	int i = 0;
	copy = (t_mlx**)malloc(sizeof(t_mlx*) * MAX_THR);
	while (i < MAX_THR)
	{
		copy[i] = (t_mlx*)malloc(sizeof(t_mlx));
		copy[i] = ft_memcpy(copy[i], mlx, sizeof(t_mlx));
		copy[i]->index = i;
		copy[i]->w = 1920;
		copy[i]->h = 1080;
		if ((pthread_create(&thread[i], NULL, (void*)ft_spider, (void*)copy[i])) != 0)
		{
			printf("Thread error!\n");
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i < MAX_THR)
	{
		if ((pthread_join(thread[i], NULL)) != 0)
		{
			printf("Thread error!\n");
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

int		mouse_move(int x, int y, t_mlx *mlx)
{

	if (mlx->julia_change_trigger == 1)
	{
		ft_julia_change(x, y, mlx);
		ft_thread(mlx);
		ft_info(mlx);
	}
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	mlx->w = 1920;
	mlx->h = 1080;
	if (button == 1)
		ft_mouse_cent(x, y, mlx);
	if (button == 4)
	{
		//ft_mouse_zoom_in(x, y, mlx);
		mlx->zoom *= 1.25;
		ft_thread(mlx);
	}
	if (button == 5)
	{
		//ft_mouse_zoom_out(x, y, mlx);
		mlx->zoom /= 1.25;
		ft_thread(mlx);
	}
	// if (button == 3)
	// 	mlx->julia_change_trigger = !mlx->julia_change_trigger;
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
		ft_thread(mlx);
	}
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
		mlx->move_x -= 0.25 / mlx->zoom;
		ft_thread(mlx);
	}
	if (keycode == 124)
	{
		mlx->move_x += 0.25 / mlx->zoom;
		ft_thread(mlx);
		
	}
	if (keycode == 125)
	{
		mlx->move_y += 0.25 / mlx->zoom;
		ft_thread(mlx);
	}
	if (keycode == 126)
	{
		mlx->move_y -= 0.25 / mlx->zoom;
		ft_thread(mlx);
	}
	if (keycode == 34)
		ft_info(mlx);
    return (0);
}

int     main(int argc, char const *argv[])
{
    t_mlx *mlx;

    mlx = malloc(sizeof(t_mlx));
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "TEST");
	mlx->img = mlx_new_image(mlx->mlx, 1920, 1080);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);
	
	ft_start(mlx);
	ft_thread(mlx);

	//ft_triangle_start(mlx);

	// ft_start_cl(mlx);
	// ft_compile_cl(mlx);

	//ft_test();

	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
    mlx_hook(mlx->win, 2, 1, key_press, mlx);
	mlx_hook(mlx->win, 4, 1, mouse_press, mlx);
	mlx_hook(mlx->win, 6, 1, mouse_move, mlx);
    mlx_loop(mlx);
    return 0;
}
