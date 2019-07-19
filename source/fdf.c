/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:43:22 by viwade            #+#    #+#             */
/*   Updated: 2019/07/19 14:07:16 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define SCL2D(v,m)		((v2d_t){(v).x*(m),(v).y*(m)})

static void
	fdf_pixel(fdf_t *o, v2d_t pos, pixel_t col)
{
	unsigned int	*screen;

	screen = o->m_start;
	pos.x = pos.x + (o->dim.x / 2);
	pos.y = pos.y + (o->dim.y / 2);
	screen[(pos.y * o->dim.x) + pos.x] = *(int *)&col;
}

static void
	linedraw(v3d_t a, v3d_t b, v2d_t bound, fdf_t *o)
{
	v3d_t	c;
	v2d_t	pos;

	c = (v3d_t){0, (b.y - a.y) / (b.x - a.x), 0};
	c.z = sqrt(PYTH(b.x - a.x, b.y - a.y, b.z - a.z));
	while (c.x < c.z)
	{
		pos = (v2d_t){a.x + (c.x * MIN(1, 1 / c.y)),
					a.y + (c.x * MIN(1, c.y))};
		if (ABS(pos.x) < bound.x && ABS(pos.y) < bound.y)
			fdf_pixel(o, pos, (pixel_t){
		.r = (255 * (1 - (c.x / c.z))) + 0 * (c.x / c.z),
		.g = (96 * (1 - (c.x / c.z))) + 192 * (c.x / c.z),
		.b = (0 * (1 - (c.x / c.z))) + 255 * (c.x / c.z)});
		c.x += 1;
	}
}

/*
**	Initialization – Things we need for fdf_t (o)
**		Read a file, create a map (map)
**		Create mlx instance (m_init)
**		Create window title (m_title)
**		Set window dimensions (dim)
**		Create window instance (m_window)
**		Set raster resolution (resolution)
*/

void
	fdf(char *filename)
{
	fdf_t	o;

	o.m_init = mlx_init();
	o.map = fdf_init(filename);
	o.m_title = "fdf <-> viwade";
	o.dim = fdf_window_size(o.map.size);
	o.m_window = mlx_new_window(o.m_init, o.dim.x, o.dim.y, o.m_title);
	o.resolution = MAX(1, o.dim.x / MAX(o.map.size.x, o.map.size.y));
	o.resolution = MAX(42, (o.dim.x / 2) - WINDOW_PADDING);
	o.m_image = mlx_new_image(o.m_init, o.dim.x, o.dim.y);
	o.bmp.line = o.dim.x;
	o.m_start = mlx_get_data_addr(o.m_image, &(int){BIT_DEPTH},&o.bmp.line,
		&o.bmp.endian);
	linedraw(o.map.mesh.l->a[0].pos, o.map.mesh.l->b[0].pos, SCL2D(o.dim, 0.5), &o);
	fdf_projection(&o, o.map.transform, o.iso, 0);
	mlx_put_image_to_window(o.m_init, o.m_window, o.m_image, 0, 0);
	fdf_hook(&o);
	mlx_loop(o.m_init);
}
