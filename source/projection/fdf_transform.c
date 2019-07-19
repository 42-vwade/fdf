/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 23:11:32 by viwade            #+#    #+#             */
/*   Updated: 2019/07/19 05:16:05 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
**  3D-REFERENCE -> TO -> 3D-TRANSFORM
*/

void
	fdf_apply_transform(mesh_t *m, tfm_t t)
{
	size_t	i;

	i = 0;
	while (i < m->v_len)
	{
		m->v[i].pos = fdf_matrix_translate(m->v[i].pos, t);
		i++;
	}
}
