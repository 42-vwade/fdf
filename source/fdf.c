/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:43:22 by viwade            #+#    #+#             */
/*   Updated: 2019/04/06 00:34:12 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
t_v2d	g_size = {20, 20};

static t_fdf
	verify(int fd)
{
	t_fdf	o;

	while (get_next_line(o.fd, &o.str))
	{
		while (ft_iswhitespace(o.str[0]))
			o.str++;
		while (*o.str)
		{
			if (ft_isdigit(o.str[0]))
				;
		}
		ft_strsplit(o.str, ' ');
	}
	return (0);
}
*/

void
	fdf(t_fdf o)
{
	t_mlx	mlx;

	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, 200, 200, "TEST WINDOW -- MLXy");
	o.fd = 1;

	//verify(obj);
	return ;
}
