/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection_2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:41:38 by viwade            #+#    #+#             */
/*   Updated: 2019/07/17 17:21:52 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define F_ISO(p,t)	
#define F_PERS(p,t)	
#define F_PROJ_X(i,p,t)	(i?F_ISO(p,t):F_PER(p,t))

p2d_t
	fdf_project_2d(map_t *m, tfm_t t, char iso, size_t i)
{
	p3d_t	v;
	p2d_t	p;

	if (i >= m->mesh.v_len)	
		ft_error("fdf-error: fdf_projection index mismatch");
	v = (p3d_t)*(m->mesh.v + i * sizeof(p3d_t));
	{
		p.color = v.col;
		p.pos.x = F_PROJ(iso, v.pos)
		m.mesh.v[i];
		i++;
	}
	return (p);
}
