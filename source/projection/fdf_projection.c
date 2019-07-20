/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:41:38 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 05:26:01 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define F_PROJ_X(i,p,t,x)	{v3d_t a,b,c; x=(i?F_ISO(p,t):F_PER(p,t));}
#define SCPS(n,res)	(SQ(n) * (res))
#define SL0(n)	((n)<0?(MAX(-1,(n))):(MIN(1, (n))))
#define SL1(a,b,n)	((a)<(b)?SL0(ABS(n?1/n:0)):-SL0(ABS(n?1/n:0)))
#define SL2(n)	(MIN(1, (n)))
#define VEC_SCL(v,m)	((v3d_t){v.x * m,v.y * m,v.z * m})
#define SCL2D(v,m)		((v2d_t){(v).x*(m),(v).y*(m)})

/*
**	Copy verts at line and scale normalized space into screen space
**	Set index to 0. Set slope. Set line length.
**	While index is less than line length, iterate by 1
**	Set cursor at position of p1 and increment towards p2
**	Set pixel color for p1 via blend : c1 * (1-(i/len))
**	Set pixel color for p2 via blend : c2 * (i/len)
**	Place pixel color at array location : 2d position -> 1d index
**		i = (y * screen.width) + x
*/

static void
	fdf_drawline(fdf_t *o, l3d_t *l, v2d_t bound, size_t res)
{
	p3d_t	p[2];
	v3d_t	c;
	v2d_t	pos;

	p[0] = (p3d_t){VEC_SCL(l->a->pos, res), (pixel_t)l->a->col};
	p[1] = (p3d_t){VEC_SCL(l->b->pos, res), (pixel_t)l->b->col};
	c = (v3d_t){0, (p[1].pos.y - p[0].pos.y) / (p[1].pos.x - p[0].pos.x), 0};
	c.z = sqrt(PYTH(p[1].pos.x - p[0].pos.x, p[1].pos.y - p[0].pos.y, 0));
	while (c.x < c.z)
	{
		pos = (v2d_t){p[0].pos.x + (c.x * SL1(p[0].pos.x, p[1].pos.x, c.y)),
					p[0].pos.y + (c.x * SL0(c.y))};
		if (ABS(pos.x) < bound.x && ABS(pos.y) < bound.y)
			fdf_pixel(o, pos, (pixel_t){
		.r = (p[0].col.r * (1 - (c.x / c.z))) + p[1].col.r * (c.x / c.z),
		.g = (p[0].col.g * (1 - (c.x / c.z))) + p[1].col.g * (c.x / c.z),
		.b = (p[0].col.b * (1 - (c.x / c.z))) + p[1].col.b * (c.x / c.z)});
		c.x += 1;
	}
}

static void
	fdf_project(fdf_t *o, char iso, size_t i)
{
	l3d_t	*l;

	while ((i++ < o->map.mesh.v_len) || (i = 0))
		o->map.mesh.v[i - 1].pos = fdf_transform(o->map.mesh.ref_v[i - 1].pos,
			o->map.transform);
// iso will determine projection
	while (i < o->map.mesh.l_len)
	{
		l = (void*)&o->map.mesh.l[i * sizeof(l3d_t)];
		fdf_drawline(o, l, SCL2D(o->dim, 0.5), o->resolution);
		i++;
	}
}

void
	fdf_projection(fdf_t *o, tfm_t t, char iso, size_t i)
{
	if (i >= o->map.mesh.v_len)
		ft_error("fdf-error: fdf_projection index mismatch");
	fdf_project(o, iso, i);
}
