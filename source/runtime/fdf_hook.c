/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:32:33 by viwade            #+#    #+#             */
/*   Updated: 2019/07/14 17:53:23 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int
	key_press(int keycode, fdf_t *o)
{
	IF_C(keycode == KEY_P, o->iso = o->iso ? 0 : 1);
	return (1);
}

static int
	key_release(int keycode, fdf_t *o)
{
	IF_C(keycode == KEY_ESC, exit(0));
	return (1);
}

static int
	mouse_down(int button, int x, int y, fdf_t *o)
{
	return (1);
}

static int
	mouse_up(int button, int x, int y, fdf_t *o)
{
	return (1);
}

void
	fdf_hook(fdf_t *o)
{
	mlx_hook(o->m_window, 2, 0, key_press, o);
	mlx_hook(o->m_window, 3, 0, key_release, o);
	mlx_hook(o->m_window, 4, 0, mouse_down, o);
	mlx_hook(o->m_window, 5, 0, mouse_up, o);
	mlx_hook(o->m_window, 6, 0, (int (*)()){fdf_mouse(1)}, o);
}
