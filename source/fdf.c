/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:43:22 by viwade            #+#    #+#             */
/*   Updated: 2019/07/21 15:13:25 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Initialization – Things we need for fdf_t (o)
**		Read a file, create a map (map)
**		Create mlx instance (m_init)
**		Create window title (m_title)
**		Set window dimensions (dim)
**		Create window instance (m_window)
**		Set raster resolution (resolution)
**		Set color mode (0: default, 1: heightmap)
*/

void
	fdf(char *filename)
{
	fdf_t	o;

	ft_bzero(&o, sizeof(o));
	o.m_init = mlx_init();
	o.map = fdf_init(filename);
	o.m_title = "fdf <-> viwade";
	o.dim = fdf_window_size(o.map.size);
	o.dim = (v2d_t){1200, 1200};
	o.m_window = mlx_new_window(o.m_init, o.dim.x, o.dim.y, o.m_title);
	o.resolution = MAX(1, o.dim.x / MAX(o.map.size.x, o.map.size.y));
	o.resolution = MAX(42, (o.dim.x / 2) - WINDOW_PADDING);
	o.bmp.line = o.dim.x;
	o.m_image = mlx_new_image(o.m_init, o.dim.x, o.dim.y);
	o.m_start = mlx_get_data_addr(o.m_image, &(int){BIT_DEPTH},
		&o.bmp.line, &o.bmp.endian);
	o.map.transform.scale = (v3d_t){.8, .8, .8};
	o.map.transform.rotate = (v3d_t){60, 0, 10};
	o.mode = 1;
	fdf_color_mode(&o);
	fdf_hook(&o);
	mlx_loop(o.m_init);
}
