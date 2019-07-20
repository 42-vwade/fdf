/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_linedraw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:37:58 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 07:38:45 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void
	linedraw(v3d_t a, v3d_t b, v2d_t bound, fdf_t *o)
{
	v3d_t	c;
	v2d_t	pos;

	c = (v3d_t){0, (b.y - a.y) / (b.x - a.x), 0};
	c.z = sqrt(PYTH(b.x - a.x, b.y - a.y, b.z - a.z));
	while (c.x < c.z)
	{
		pos = (v2d_t){a.x + (c.x * MIN(SL0(c.y), 1 / c.y)),
					a.y + (c.x * MIN(SL0(c.y), c.y))};
		if (ABS(pos.x) < bound.x && ABS(pos.y) < bound.y)
			fdf_pixel(o, pos, (pixel_t){
		.r = (255 * (1 - (c.x / c.z))) + 0 * (c.x / c.z),
		.g = (96 * (1 - (c.x / c.z))) + 192 * (c.x / c.z),
		.b = (0 * (1 - (c.x / c.z))) + 255 * (c.x / c.z)});
		c.x += 1;
	}
}

/*
**		example
**	linedraw((v3d_t){-99, -99, 0}, (v3d_t){99, 99, 0}, SCL2D(o.dim, 0.5), &o);
**	linedraw((v3d_t){0, 0, 0}, (v3d_t){20, 60, 0}, SCL2D(o.dim, 0.5), &o);
*/
