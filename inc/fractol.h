/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:17:02 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/08 18:00:48 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"

# include <pthread.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# define MAX_THR 16

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;

	void		*img;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;

	int			index;
	int			threads;

	int			func_index;
	char		*fractol;
	void		*func[8];
	char		*fractal_name;

	int			color[32];
	int			color_index;

	int			point_zoom;

	int			h;
	int			w;

	int			max_iteration;
	double		zoom;
	double		move_x;
	double		move_y;

	double		c_re;
	double		c_im;
	double		pr;
	double		pi;
	double		new_re;
	double		new_im;
	double		old_re;
	double		old_im;
	double		t_re;
	double		t_im;
	double		c_x;
	double		c_y;

	int			rect_color;

	int			julia_change_trigger;
	int			bio_change_trigger;
}				t_mlx;

void			ft_mandelbrot(t_mlx *mlx);
void			ft_julia(t_mlx *mlx);
void			ft_ship(t_mlx *mlx);
void			ft_spider(t_mlx *mlx);
void			ft_newton(t_mlx *mlx);
void			ft_thorn(t_mlx *mlx);
void			ft_biomorph(t_mlx *mlx);

void			ft_julia_change(int x, int y, t_mlx *mlx);
void			ft_bio_change(int x, int y, t_mlx *mlx);

void			ft_fill_funcs(t_mlx *mlx);
void			ft_fractal_check(t_mlx *mlx);

void			ft_start(t_mlx *mlx);
void			ft_fractal_change(t_mlx *mlx, int dir);

void			ft_color_set(t_mlx *mlx);
void			ft_color_change(t_mlx *mlx, int dir);

void			ft_fill_rect(t_mlx *mlx, int x, int y);

void			ft_thread(t_mlx *mlx);

void			ft_mouse_cent(int x, int y, t_mlx *mlx);
void			ft_mouse_zoom_in(int x, int y, t_mlx *mlx);
void			ft_mouse_zoom_out(int x, int y, t_mlx *mlx);

void			ft_reset_image(t_mlx *mlx);

void			ft_error_mes(void);

void			ft_key_press_temp(int keycode, t_mlx *mlx);
void			ft_temp_change(int button, t_mlx *mlx);

#endif
