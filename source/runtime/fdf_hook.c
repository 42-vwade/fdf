/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:32:33 by viwade            #+#    #+#             */
/*   Updated: 2019/07/14 17:04:30 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int
	key_press(int keycode, fdf_t *o)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (1);
}

void
	fdf_hook(fdf_t *o)
{
	mlx_hook(o->m_window, 3, 0, key_press, o);
}
