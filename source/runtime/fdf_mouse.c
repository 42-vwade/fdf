/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:33:10 by viwade            #+#    #+#             */
/*   Updated: 2019/07/14 17:49:55 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int
	mouse_move(int x, int y, fdf_t *o)
{
	return (1);
}

void
	*fdf_mouse(size_t i)
{
	if (i == 1)
		return (mouse_move);
	return (0);
}
