/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:13:53 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/08 15:43:40 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_thread_temp(pthread_t *thread, t_mlx **copy)
{
	int i;

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
}

void	ft_thread(t_mlx *mlx)
{
	int			i;
	t_mlx		*copy[MAX_THR];
	pthread_t	thread[MAX_THR];

	i = 0;
	while (i < MAX_THR)
	{
		copy[i] = (t_mlx*)malloc(sizeof(t_mlx));
		copy[i] = ft_memcpy(copy[i], mlx, sizeof(t_mlx));
		copy[i]->index = i;
		copy[i]->w = 1920;
		copy[i]->h = 1080;
		if ((pthread_create(&thread[i], NULL,
			(void*)mlx->func[mlx->func_index], (void*)copy[i])) != 0)
		{
			ft_putstr("Thread error!\n");
			exit(0);
		}
		i++;
	}
	ft_thread_temp(thread, copy);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
