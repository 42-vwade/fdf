/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 04:40:35 by viwade            #+#    #+#             */
/*   Updated: 2019/07/19 12:48:12 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define PRECISION	3

static FT_STR
	fdf_xyz(p3d_t point)
{
	char *tmp;

	tmp = ft_strjoin_free(ft_strjoin_free(ft_strdup("#"),
		ft_itoa_base((ull_t)((*(uint *)&point.col) << 8) >> 8, 16)),
		ft_strdup(" [ "));
	if (point.pos.x >= 0)
		tmp = ft_strjoin_free(tmp, ft_strdup(" "));
	tmp = ft_strjoin_free(ft_strjoin_free(tmp,
		infinite_double(point.pos.x, PRECISION)), ft_strdup(" , "));
	if (point.pos.y >= 0)
		tmp = ft_strjoin_free(tmp, ft_strdup(" "));
	tmp = ft_strjoin_free(ft_strjoin_free(tmp,
		infinite_double(point.pos.y, PRECISION)), ft_strdup(" , "));
	if (point.pos.z >= 0)
		tmp = ft_strjoin_free(tmp, ft_strdup(" "));
	return (ft_strjoin_free(ft_strjoin_free(tmp,
		infinite_double(point.pos.x, PRECISION)), ft_strdup(" ]")));
}

void
	fdf_print_line(mesh_t m)
{
	size_t	i;
	l3d_t	*l;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(0);
	while (i < m.l_len)
	{
		l = (void*)&m.l[i * sizeof(l3d_t)];
		tmp = ft_strjoin_free(ft_strjoin_free(ft_strjoin_free(
			tmp, ft_strdup("line[")), ft_itoa(i)), ft_strdup("]"));
		if (i < 10)
			tmp = ft_strjoin_free(tmp, ft_strdup(" "));
		tmp = ft_strjoin_free(ft_strjoin_free(ft_strjoin_free(ft_strjoin_free(
			ft_strjoin_free(tmp, ft_strdup("\tpoint_a[ ")), fdf_xyz(l->a[0])),
			ft_strdup(" ]\tpoint_b[ ")), fdf_xyz(l->b[0])), ft_strdup(" ]\n"));
		i++;
	}
	ft_putstr(tmp);
	free(tmp);
}

/*
**		ft_putstr("\t\tcolor[ #");
**		tmp = ft_itoa_base((ull_t)((*(uint *)&m.v[i].col) << 8) >> 8, 16);
**		ft_putstr(tmp);
**		free(tmp);
*/
