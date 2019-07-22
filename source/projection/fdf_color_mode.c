/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 06:25:15 by viwade            #+#    #+#             */
/*   Updated: 2019/07/21 17:36:06 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define M_R(c)	((0xFF0000 & c) >> 16)
#define M_G(c)	((0xFF00 & c) >> 8)
#define M_B(c)	(0xFF & c)
#define V_SC(v)	(1/SQ(ABS(v) + 1))
#define U_DR(v,c,z)	(uint)(((M_R(z)*V_SC(v)+(1.0-V_SC(v))*M_R(c)))) << 16
#define U_DG(v,c,z)	(uint)(((M_G(z)*V_SC(v)+(1.0-V_SC(v))*M_G(c)))) << 8
#define U_DB(v,c,z)	(uint)(((M_B(z)*V_SC(v)+(1.0-V_SC(v))*M_B(c))))
#define U_DF(v,c,z)	(uint)((U_DR(v,c,z))+(U_DG(v,c,z))+(U_DB(v,c,z)))
#define ASNC(a,v)	{*(uint*)&a.col = *(uint*)&v.col;}
#define ASNH(a,v,c)	*(uint*)&a.col = (uint)(U_DF((double)v,c,VZERO));
#define V_M2C(v,m,z)	(uint)(U_DF(v,m,z))
#define V_M2R1(v)	(v)<0?V_M2C(v,VDAWN,VGREY):V_M2C(v,VWHTE,VGREY)
#define V_M2R(v,r)	*(uint*)&v.col = V_M2R1(r.pos.z - v.pos.z);
#define V_MD2(m,i,l,v,r)	{if(m==2){while(i++<l){V_M2R(v[i-1],r[i-1]);}}}

void	fdf_color_mode(fdf_t *o)
{
	size_t	i;

	i = 0;
	o->modes = 2;
	o->mode %= o->modes;
	if (!o->mode)
		while (i++ < o->map.mesh.v_len)
			ASNC(o->map.mesh.v[i - 1], o->map.mesh.ref_v[i - 1]);
	if (o->mode == 1)
		while (i++ < o->map.mesh.v_len)
			IF_E(o->map.mesh.v[i - 1].pos.z < 0,
			ASNH(o->map.mesh.v[i - 1], o->map.mesh.v[i - 1].pos.z, VBLUE),
			ASNH(o->map.mesh.v[i - 1], o->map.mesh.v[i - 1].pos.z, VDAWN));
	V_MD2(o->mode, i, o->map.mesh.v_len, o->map.mesh.v, o->map.mesh.ref_v);
	fdf_redraw(o);
}
