/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 19:30:43 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/07 19:07:27 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fill_funcs(t_mlx *mlx)
{
	mlx->func[0] = ft_mandelbrot;
	mlx->func[1] = ft_julia;
	mlx->func[2] = ft_spider;
	mlx->func[3] = ft_ship;
	mlx->func[4] = ft_thorn;
	mlx->func[5] = ft_biomorph;
}

void	ft_fractal_check(t_mlx *mlx)
{
	mlx->func_index = -1;
	if (ft_strcmp(mlx->fractol, "Mandelbrot") == 0
		|| ft_strcmp(mlx->fractol, "m") == 0)
		mlx->func_index = 0;
	if (ft_strcmp(mlx->fractol, "Julia") == 0
		|| ft_strcmp(mlx->fractol, "j") == 0)
		mlx->func_index = 1;
	if (ft_strcmp(mlx->fractol, "Spider") == 0
		|| ft_strcmp(mlx->fractol, "s") == 0)
		mlx->func_index = 2;
	if (ft_strcmp(mlx->fractol, "Burning Ship") == 0
		|| ft_strcmp(mlx->fractol, "bs") == 0)
		mlx->func_index = 3;
	if (ft_strcmp(mlx->fractol, "Thorn") == 0
		|| ft_strcmp(mlx->fractol, "t") == 0)
		mlx->func_index = 4;
	if (ft_strcmp(mlx->fractol, "Biomorph") == 0
		|| ft_strcmp(mlx->fractol, "b") == 0)
		mlx->func_index = 5;
}

void	ft_fractal_change(t_mlx *mlx, int dir)
{
	mlx->func_index += dir;
	if (mlx->func_index > 5)
		mlx->func_index = 0;
	if (mlx->func_index < 0)
		mlx->func_index = 5;
	ft_reset_image(mlx);
	ft_start(mlx);
	ft_thread(mlx);
}
