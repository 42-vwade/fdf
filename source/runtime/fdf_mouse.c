/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:33:10 by viwade            #+#    #+#             */
/*   Updated: 2019/07/19 13:09:36 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int
	mouse_down(int button, int x, int y, fdf_t *o)
{
	return (o->mouse = 1);
}

int
	mouse_up(int button, int x, int y, fdf_t *o)
{
	o->redraw = 1;
	return (!(o->mouse = 0));
}

int
	mouse_move(int x, int y, fdf_t *o)
{
	if (o->mouse)
		;
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
