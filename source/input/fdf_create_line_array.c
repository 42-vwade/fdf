/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_line_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:18:14 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 16:38:26 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void
	fdf_create_line_array(l3d_t **dst, size_t size)
{
	dst[0] = NULL;
	if (!(dst[0] = (l3d_t*)malloc(sizeof(l3d_t) * size)))
		ft_error("fdf-error: could not allocate vertex lattice");
	ft_bzero(dst[0], sizeof(l3d_t) * size);
}
