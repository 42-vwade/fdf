/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:43:22 by viwade            #+#    #+#             */
/*   Updated: 2019/07/13 03:18:01 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	fdf(char *filename)
{
	fdf_t	o;

	o.map = fdf_init(filename);
	o.m_init = mlx_init();
	o.m_title = encode_utf8(L"🅕🅓🅕 — √ﾉwﾑd乇");
	o.dim = fdf_window_size(o.map.size);
	o.m_window = mlx_new_window(o.m_init, o.dim.x, o.dim.y, o.m_title);
	mlx_loop(o.m_init);
}
