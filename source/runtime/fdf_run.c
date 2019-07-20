/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:28:21 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 15:39:29 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define K_MVR(t)	{t.x += 1.0 / 42.0;}
#define K_MVL(t)	{t.x -= 1.0 / 42.0;}
#define K_MVD(t)	{t.y += 1.0 / 42.0;}
#define K_MVU(t)	{t.y -= 1.0 / 42.0;}
#define K_MV0(k,t,r)	IF_C(r=k==KEY_ARROW_UP,K_MVU(t))
#define K_MV1(k,t,r)	IF_E(r=k==KEY_ARROW_DOWN,K_MVD(t),K_MV0(k,t,r))
#define K_MV2(k,t,r)	IF_E(r=k==KEY_ARROW_LEFT,K_MVL(t),K_MV1(k,t,r))
#define K_MOV(k,t,r)	IF_E(r=k==KEY_ARROW_RIGHT,K_MVR(t),K_MV2(k,t,r))

int
	fdf_run_loop(fdf_t *o)
{
	if (o->key)
		K_MOV(o->key, o->map.transform.translate, o->redraw);
	if (o->redraw)
	{
		fdf_redraw(o);
	}
	return (1);
}
