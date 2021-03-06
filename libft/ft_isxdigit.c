/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:34:06 by zjeyne-l          #+#    #+#             */
/*   Updated: 2018/11/28 15:51:38 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isxdigit(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102))
		return (1);
	return (0);
}
