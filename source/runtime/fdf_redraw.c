/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_redraw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 10:11:00 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 11:49:12 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fdf_redraw(fdf_t *o)
{
	ft_bzero(o->m_start, sizeof(int) * o->dim.x * o->dim.y);
	fdf_projection(o);
	mlx_put_image_to_window(o->m_init, o->m_window, o->m_image, 0, 0);
	o->redraw = 0;
}
