/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:42:26 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 02:31:34 by viwade           ###   ########.fr       */
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
	IF_C(key == KEY_ARROW_RIGHT, o->map.transform.rotate.x += 0.1);
	IF_C(key == KEY_ARROW_LEFT, o->map.transform.rotate.x -= 0.1);
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
