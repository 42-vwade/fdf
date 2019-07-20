/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 06:25:15 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 07:54:24 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define VBLUE	0x00c0FF
#define VDAWN	0xFF6000
#define V_WH	0xFFFFFF
#define U_DF(v,c)	(uint)(((V_WH * (1.0 - SQ(v))) + (SQ(v) * c))) << 8
#define ASNC(a,v)	*(uint*)&a.col = *(uint*)&v.col
#define ASNH(a,v,c)	*(uint*)&a.col = (uint)((U_DF((double)v,c)) >> 8)

void	fdf_color_mode(fdf_t *o)
{
	size_t	i;

	i = 0;
	o->modes = 2;
	o->mode %= o->modes;
	if (!o->mode)
		while (i++ < o->map.mesh.v_len)
			ASNC(o->map.mesh.v[i - 1], o->map.mesh.ref_v[i - 1]);
	else if (o->mode == 1)
		while (i < o->map.mesh.v_len)
			IF_E(o->map.mesh.v[i++].pos.z < 0,
			ASNH(o->map.mesh.v[i - 1], o->map.mesh.v[i - 1].pos.z, VBLUE),
			ASNH(o->map.mesh.v[i - 1], o->map.mesh.v[i - 1].pos.z, VDAWN));
}
