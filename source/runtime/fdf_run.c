/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:28:21 by viwade            #+#    #+#             */
/*   Updated: 2019/07/19 14:05:55 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int
	fdf_run_loop(fdf_t *o)
{
	if (o->redraw)
	{
		fdf_projection(o, o->map.transform, o->iso, 0);
		mlx_put_image_to_window(o->m_init, o->m_window, o->m_image, 0, 0);
		o->redraw = 0;
	}
	return (1);
}
