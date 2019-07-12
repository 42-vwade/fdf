/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:56:41 by viwade            #+#    #+#             */
/*   Updated: 2019/07/12 16:18:18 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static	p3d_t
	*v_h(p3d_t *v, v3d_t c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && v[i].pos.y == c.y)
		if (v[i].pos.x == c.x + 1)
			return (&v[i]);
		else
			i++;
	return (NULL);
}

static	p3d_t
	*v_v(p3d_t *v, v3d_t c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && v[i].pos.x != c.x)
		i++;
	while (i < size && v[i].pos.x == c.x)
		if (v[i].pos.y == c.y + 1)
			return (&v[i]);
		else
			i++;
	return (NULL);
}

static void
	array_create(t_list *lst, t_line *arr)
{
	size_t	i;
	t_list	*node;

	i = 0;
	node = lst;
	while (node)
	{
		arr[i++] = *(t_line *)node->content;
		node = node->next;
	}
	ft_lstdel(&lst, ft_del);
}

static void
	vertex_normalize(p3d_t *v, size_t size)
{
	size_t	i;
	v3d_t	d;

	i = 0;
	d = (v3d_t){0, 0, 0};
	while (i++ < size)
		d = (v3d_t){.x = MAX(MAX(d.x, ABS(v[i - 1].pos.x)), ABS(v[i - 1].pos.y))
		, .z = MAX(d.z, ABS(v[i - 1].pos.z))};
	i = 0;
	d.x /= 2;
	while (i++ < size)
		v[i - 1].pos = (v3d_t){v[i - 1].pos.x / d.x, v[i - 1].pos.y / d.x,
			v[i - 1].pos.z / d.z};
	i = 0;
	while (i++ < size)
		v[i - 1].pos =
			(v3d_t){ v[i - 1].pos.x - 1, v[i - 1].pos.y - 1, v[i - 1].pos.z};
}

/*
**	Vertex array length must be handled separately. Cannot terminate with NULL.
**	Line array length must be handled separately. Cannot terminate with NULL.
**	/\
*/

void
	fdf_line(map_t *m, size_t size, size_t i)
{
	t_line	ln[2];
	t_list	*list;

	list = NULL;
	while (i < size)
	{
		ln[0] = (t_line){&m->mesh.v[i], (i + 1 < size) ?
			v_h(&m->mesh.v[i + 1], m->mesh.v[i].pos, size - i) : NULL};
		ln[1] = (t_line){&m->mesh.v[i], (i + m->size.x < size) ? v_v(&m->mesh.v[
			i + m->size.x], m->mesh.v[i].pos, size - i - m->size.x) : NULL};
		if (ln[0].b)
			ft_lstpush(&list, ft_lstnew(&ln[0], sizeof(t_line)));
		if (ln[1].b)
			ft_lstpush(&list, ft_lstnew(&ln[1], sizeof(t_line)));
		i++;
	}
	m->mesh.l_len = ft_lstlen(list);
	if (!(m->mesh.l = (l3d_t*)malloc(sizeof(*m->mesh.l) * (m->mesh.l_len + 1))))
		ft_error("fdf-error: could not allocate vertex lattice");
	array_create(list, m->mesh.l);
	vertex_normalize(m->mesh.v, m->mesh.v_len);
}