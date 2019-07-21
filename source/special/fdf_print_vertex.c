/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_vertex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 04:40:35 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 18:07:42 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define PRECISION	4

static void
	fdf_xyz(p3d_t point)
{
	char *tmp;

	ft_putstr("#");
	tmp = ft_itoa_base((ull_t)((*(uint *)&point.col) << 8) >> 8, 16);
	ft_putstr(tmp);
	free(tmp);
	ft_putstr(" [ ");
	if (point.pos.x >= 0)
		ft_putstr(" ");
	print_double(point.pos.x, PRECISION);
	ft_putstr(" , ");
	if (point.pos.y >= 0)
		ft_putstr(" ");
	print_double(point.pos.y, PRECISION);
	ft_putstr(" , ");
	if (point.pos.z >= 0)
		ft_putstr(" ");
	print_double(point.pos.z, PRECISION);
	ft_putstr(" ]");
}

void
	fdf_print_vertex(mesh_t m)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = 0;
	while ((i <= 100 && i < m.v_len) || !write(1, "...\n", 4))
	{
		ft_putstr("v[");
		ft_putnbr(i);
		ft_putstr("]\t\t");
		fdf_xyz(m.ref_v[i++]);
		ft_putendl(0);
	}
}
