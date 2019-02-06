/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:59:56 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/06 19:38:14 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_triangle(t_mlx *mlx, t_triangle *a, t_triangle *b, t_triangle *c, int iter)
{
	t_triangle *d;
	t_triangle *v1;
	t_triangle *v2;

	d = (t_triangle*)malloc(sizeof(t_triangle));
	v1 = (t_triangle*)malloc(sizeof(t_triangle));
	v2 = (t_triangle*)malloc(sizeof(t_triangle));
	
	if (iter == 0)
		return ;

	v1->x = b->x - a->x;
	v1->y = b->y - a->y;

	v2->x = c->x - a->x;
	v2->y = c->y - c->y;

	d->x = a->x + (v1->x + v2->x) / 3;
	d->y = a->y + (v1->y + v2->y) / 3;

	ft_draw_line(mlx, a->x, a->y, d->x, d->y, mlx->color[mlx->color_index]);
	ft_draw_line(mlx, b->x, b->y, d->x, d->y, mlx->color[mlx->color_index]);
	ft_draw_line(mlx, c->x, c->y, d->x, d->y, mlx->color[mlx->color_index]);

	ft_triangle(mlx, a, b, c, iter - 1);
	ft_triangle(mlx, b, c, d, iter - 1);
	ft_triangle(mlx, a, c, d, iter - 1);
}

void	ft_triangle_start(t_mlx *mlx)
{
	t_triangle *a;
	t_triangle *b;
	t_triangle *c;

	a = (t_triangle*)malloc(sizeof(t_triangle));
	b = (t_triangle*)malloc(sizeof(t_triangle));
	c = (t_triangle*)malloc(sizeof(t_triangle));
	a->x = (mlx->w * 0.75) / 1 - mlx->move_x * 100;
	a->y = (mlx->h * 0.75) / 1 - mlx->move_y * 100;
	b->x = (mlx->w / 4) / 1 - mlx->move_x * 100;
	b->y = (mlx->h * 0.75) / 1 - mlx->move_y * 100;
	c->x = (mlx->w / 2) / 1 - mlx->move_x * 100;
	c->y = (mlx->h / 4) / 1 - mlx->move_y * 100;

	ft_draw_line(mlx, a->x, a->y, b->x, b->y, 0xFF00FF);
	ft_draw_line(mlx, b->x, b->y, c->x, c->y, 0xFF00FF);
	ft_draw_line(mlx, a->x, a->y, c->x, c->y, 0xFF00FF);

	ft_triangle(mlx, a, b, c, mlx->max_iteration);
	free(a);
	free(b);
	free(c);
}
