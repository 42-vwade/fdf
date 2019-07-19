/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_vertex_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:18:14 by viwade            #+#    #+#             */
/*   Updated: 2019/07/18 20:34:30 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void
	fdf_create_vertex_array(p3d_t **dst, size_t size)
{

	dst[0] = NULL;
	if (!(dst[0] = (t_point *)malloc(sizeof(t_point) * size)))
		ft_error("fdf-error: could not allocate vertex array");
	ft_bzero(dst[0], sizeof(t_point) * size);
}
