/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 02:23:50 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 02:27:08 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void
	fdf_pixel(fdf_t *o, v2d_t pos, pixel_t col)
{
	unsigned int	*screen;

	screen = o->m_start;
	pos.x = pos.x + (o->dim.x / 2);
	pos.y = pos.y + (o->dim.y / 2);
	screen[(pos.y * o->dim.x) + pos.x] = *(int *)&col;
}
