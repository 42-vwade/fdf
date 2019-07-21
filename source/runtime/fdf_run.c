/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:28:21 by viwade            #+#    #+#             */
/*   Updated: 2019/07/21 15:19:33 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define K_MVR(t)	{t.x += 1.0 / 42.0;}
#define K_MVL(t)	{t.x -= 1.0 / 42.0;}
#define K_MVD(t)	{t.y += 1.0 / 42.0;}
#define K_MVU(t)	{t.y -= 1.0 / 42.0;}
#define K_SCL0(s,v)	(0<s&&s<0.03125?-1.125*(0.03125/s):v)
#define K_SCL1(s,v)	(0<s&&s<0.03125?-1.125*(0.03125/s):v)
#define K_SCLX(s,v)	{s.x *= s.x<0?K_SCL0(-(s.x),(1/v)):K_SCL0(s.x,v);}
#define K_SCLY(s,v)	{s.y *= s.y<0?K_SCL0(-(s.y),(1/v)):K_SCL0(s.y,v);}
#define K_SCLZ(s,v)	{s.z *= s.z<0?K_SCL0(-(s.z),(1/v)):K_SCL0(s.z,v);}
#define K_MV2(k,t,r)	IF_C(r=k==KEY_ARROW_UP,K_MVU(t))
#define K_MV1(k,t,r)	IF_E(r=k==KEY_ARROW_DOWN,K_MVD(t),K_MV2(k,t,r))
#define K_MV0(k,t,r)	IF_E(r=k==KEY_ARROW_LEFT,K_MVL(t),K_MV1(k,t,r))
#define K_MOV(k,t,r)	IF_E(r=k==KEY_ARROW_RIGHT,K_MVR(t),K_MV0(k,t,r))
#define K_SC1(k,s,r)	IF_C(r=k==KEY_NUM_MINUS,K_SCLZ(s,(1/1.125)))
#define K_SC0(k,s,r)	IF_E(r=k==KEY_NUM_PLUS,K_SCLZ(s,(1.125)),K_SC1(k,s,r))
#define K_SCL(k,s,r)	IF_E(r=k==KEY_0,if(s.z!=S_Z0){s.z=S_Z0;},K_SC0(k,s,r))

int
	fdf_run_loop(fdf_t *o)
{
	if (o->key == 123 || o->key == 124 || o->key == 125 || o->key == 126)
		K_MOV(o->key, o->map.transform.translate, o->redraw);
	if (o->key == 29 || o->key == 78 || o->key == 69)
		K_SCL(o->key, o->map.transform.scale, o->redraw);
	if (o->redraw)
	{
		fdf_redraw(o);
	}
	return (1);
}
