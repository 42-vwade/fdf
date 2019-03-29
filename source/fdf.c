/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:43:22 by viwade            #+#    #+#             */
/*   Updated: 2019/03/28 17:56:58 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_v2d	g_size = {20, 20};

int
	verify(t_fdf o)
{
	char	*line;

	while (get_next_line(o.fd, &line))
	{
		ft_strsplit(line, ' ');
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
