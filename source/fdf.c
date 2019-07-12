/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:43:22 by viwade            #+#    #+#             */
/*   Updated: 2019/07/12 15:19:41 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	fdf(char *filename)
{
	fdf_t	o;

	o.map = fdf_init(filename);
	o.m_init = mlx_init();
	o.m_window = mlx_new_window(o.m_init, 200, 200, "TEST WINDOW -- MLXy");
}
