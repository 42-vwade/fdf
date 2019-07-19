/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:42:26 by viwade            #+#    #+#             */
/*   Updated: 2019/07/19 14:08:15 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int
	key_press(int key, fdf_t *o)
{
	IF_C(key == KEY_P, o->iso = o->iso ? 0 : 1);
	return (o->key = 1);
}

int
	key_release(int key, fdf_t *o)
{
	IF_C(key == KEY_ESC, exit(0));
	IF_C(o->redraw = key == KEY_W, o->map.transform.rotate.x -= 10);
	IF_C(o->redraw = key == KEY_S, o->map.transform.rotate.x -= 10);
	IF_C(o->redraw = key == KEY_A, o->map.transform.rotate.y -= 10);
	IF_C(o->redraw = key == KEY_D, o->map.transform.rotate.y += 10);
	return (!(o->key = 0));
}

int
	key_event(int key, fdf_t *o)
{
	if (o->key)
		;
	return (1);
}

void
	*fdf_keyboard(size_t i)
{
	if (i == 1)
		return (key_press);
	if (i == 2)
		return (key_release);
	if (i == 3)
		return (key_event);
	return (0);
}
