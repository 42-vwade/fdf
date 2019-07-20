/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:32:33 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 11:03:30 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void
	fdf_hook(fdf_t *o)
{
	mlx_loop_hook(o->m_init, fdf_run_loop, o);
	mlx_hook(o->m_window, 2, 0, fdf_keyboard(1), o);
	mlx_hook(o->m_window, 3, 0, fdf_keyboard(2), o);
	mlx_hook(o->m_window, 4, 0, fdf_mouse(1), o);
	mlx_hook(o->m_window, 5, 0, fdf_mouse(2), o);
	mlx_hook(o->m_window, 6, 0, fdf_mouse(3), o);
}
