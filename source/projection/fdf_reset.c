/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:44:45 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 15:02:04 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fdf_reset(fdf_t *o)
{
	size_t	i;

	i = 0;
	while (i++ < o->map.mesh.v_len || (i = 0))
		o->map.mesh.v[i - 1].pos = o->map.mesh.ref_v[i - 1].pos;
	o->map.transform.translate = (v3d_t) {0, 0, 0};
	o->map.transform.rotate = (v3d_t) {0, 0, 0};
	o->map.transform.scale = (v3d_t) {1, 1, 1};
	fdf_redraw(o);
}
