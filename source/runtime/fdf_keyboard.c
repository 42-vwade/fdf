/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:42:26 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 15:50:01 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define K_MVR(t)	{t.x += 1.0 / 42.0;}
#define K_MVL(t)	{t.x -= 1.0 / 42.0;}
#define K_MVD(t)	{t.y += 1.0 / 42.0;}
#define K_MVU(t)	{t.y -= 1.0 / 42.0;}
#define K_MV2(k,t,r)	IF_C(r=k==KEY_ARROW_UP,K_MVU(t))
#define K_MV1(k,t,r)	IF_E(r=k==KEY_ARROW_DOWN,K_MVD(t),K_MV2(k,t,r))
#define K_MV0(k,t,r)	IF_E(r=k==KEY_ARROW_LEFT,K_MVL(t),K_MV1(k,t,r))
#define K_MOV(k,t,r)	IF_E(r=k==KEY_ARROW_RIGHT,K_MVR(t),K_MV0(k,t,r))

int
	key_press(int key, fdf_t *o)
{
	IF_C(key == KEY_P, o->iso = o->iso ? 0 : 1);
	IF_C(o->mode += key == KEY_C, fdf_color_mode(o));
	IF_C(key == KEY_R, fdf_reset(o));
	return (o->key = key);
}

int
	key_release(int key, fdf_t *o)
{
	IF_C(key == KEY_ESC, exit(0));
	return (!(o->key = 0));
}

int
	key_event(int key, fdf_t *o)
{
	if (o->key)
		K_MOV(key, o->map.transform.translate, o->redraw);
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
