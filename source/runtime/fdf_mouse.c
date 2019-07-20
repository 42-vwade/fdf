/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:33:10 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 16:31:02 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define M_0(s)			MAX(s*(1/1.125),0.03125)
#define M_1(s)			MIN(s*1.125,10)
#define M_2(s)			s=(v3d_t){M_0(s.x),M_0(s.y),M_0(s.z)};
#define M_3(s)			s=(v3d_t){M_1(s.x),M_1(s.y),M_1(s.z)};
#define M_SCL(s,m4,m5)	IF_E(m5,M_2(s);m5=0,M_3(s);m4=0);

int
	mouse_down(int button, int x, int y, fdf_t *o)
{
	o->mouse[button] = 1;
	o->mouse_xy = (v2d_t){x, y};
	if ((o->redraw = (o->mouse[4] || o->mouse[5])))
		M_SCL(o->map.transform.scale, o->mouse[4], o->mouse[5]);
	return (1);
}

int
	mouse_up(int button, int x, int y, fdf_t *o)
{
	o->redraw = 1;
	o->mouse_xy = (v2d_t){x, y};
	return (!(o->mouse[button] = 0));
}

int
	mouse_move(int x, int y, fdf_t *o)
{
	if (o->mouse[1])
	{
		o->map.transform.rotate = (v3d_t){
			.x = o->map.transform.rotate.x + (y - o->mouse_xy.y) * -0.125,
			.y = o->map.transform.rotate.y + (x - o->mouse_xy.x) * 0.125,
			.z = o->map.transform.rotate.z
		};
		o->mouse_xy = (v2d_t){x, y};
		o->redraw = 1;
	}
	return (1);
}

void
	*fdf_mouse(size_t i)
{
	if (i == 1)
		return (mouse_down);
	if (i == 2)
		return (mouse_up);
	if (i == 3)
		return (mouse_move);
	return (0);
}
