/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:42:26 by viwade            #+#    #+#             */
/*   Updated: 2019/07/17 16:52:35 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int
	key_press(int keycode, fdf_t *o)
{
	IF_C(keycode == KEY_P, o->iso = o->iso ? 0 : 1);
	return (o->key = 1);
}

static int
	key_release(int keycode, fdf_t *o)
{
	IF_C(keycode == KEY_ESC, exit(0));
	return (!(o->key = 0));
}

static int
	key_event(int keycode, fdf_t *o)
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
