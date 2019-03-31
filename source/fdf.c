/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:43:22 by viwade            #+#    #+#             */
/*   Updated: 2019/03/30 00:57:28 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_v2d	g_size = {20, 20};

t_fdf
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

void
	fdf(t_fdf o)
{
	t_fdf	obj;

	obj.fd = fd;
	verify(obj);
	return ;
}

int
	main(int n, char **v)
{
	if (n == 2)
		fdf(fdf_verify(open(v[1], O_RDONLY)));
	else if (n == 4)
	{
		if (ft_atoi(v[2]) && ft_atoi(v[3]))
			g_size = (t_v2d){ft_atoi(v[2]), ft_atoi(v[3])};
		fdf(fdf_verify(open(v[1], O_RDONLY)));
	}
	else
		ft_putendl("usage: ./fdf <filename> [ xy_size z_size]");
}
