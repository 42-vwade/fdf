/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_vertex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 04:40:35 by viwade            #+#    #+#             */
/*   Updated: 2019/07/19 12:49:48 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define PRECISION	4

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
	fdf_print_vertex(mesh_t m)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(0);
	while (i++ < m.v_len)
		tmp = ft_strjoin_free(ft_strjoin_free(ft_strjoin_free(ft_strjoin_free(
			ft_strjoin_free(tmp, ft_strdup("v[")), ft_itoa(i - 1)),
				ft_strdup("]\t\t")), fdf_xyz(m.v[i - 1])), ft_strdup("\n"));
	ft_putstr(tmp);
	free(tmp);
}
