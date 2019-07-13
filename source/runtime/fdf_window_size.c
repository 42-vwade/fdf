/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:42:48 by viwade            #+#    #+#             */
/*   Updated: 2019/07/12 17:30:10 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

v2d_t	fdf_window_size(v2d_t size)
{
	size_t	v;

	v = MAX(size.x, size.y) * LINE_RESOLUTION;
	v = MIN(VIEW_RES_MAX, v);
	size.x = MAX(CONTROL_PANEL_X + VIEW_RES_MIN, CONTROL_PANEL_X + v);
	size.y = MAX(CONTROL_PANEL_Y + VIEW_RES_MIN, CONTROL_PANEL_Y + v);
	return (size);
}
