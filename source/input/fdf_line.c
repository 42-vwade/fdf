/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:56:41 by viwade            #+#    #+#             */
/*   Updated: 2019/07/14 14:50:29 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define _D_D(a,b)	((double)(a)/(double)(b))

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
	array_create(t_list *lst, t_line *arr, size_t i)
{
	t_list	*node;

	node = lst;
	while (node)
	{
		ft_memcpy(arr, node->content, sizeof(t_line));
		arr += sizeof(t_line);
		node = node->next;
	}
	ft_lstdel(&lst, ft_del);
}

static void
	vertex_normalize(map_t m, p3d_t *v, size_t size)
{
	size_t	i;
	v3d_t	d;

	i = 0;
	d = (v3d_t){0, 0, 0};
	print_double(m.size.x, 10); ft_putendl("]- dimensions mesh.x");
	print_double(m.size.y, 10); ft_putendl("]- dimensions mesh.y");
	while (i++ < size)
		d.z = MAX(d.z, ABS(v[i - 1].pos.z));
	i = 0;
	d = (v3d_t){(double)(m.size.x - 1) / 2, (double)(m.size.y - 1) / 2, d.z};
	print_double(d.x, 10); ft_putendl("]- max normalize d.x");
	print_double(d.y, 10); ft_putendl("]- aspect ratio d.y");
	while (i++ < size)
		v[i - 1].pos = (v3d_t){
			v[i - 1].pos.x - d.x, v[i - 1].pos.y - d.y, v[i - 1].pos.z};
	i = 0;
	d = (v3d_t){(double)MAX(m.size.x - 1, m.size.y - 1) / 2.0,
		_D_D(m.size.y, m.size.x), d.z};
	print_double(d.x, 10); ft_putendl("]- shift d.x");
	while (i++ < size)
		v[i - 1].pos = (v3d_t){
			v[i - 1].pos.x / d.x, v[i - 1].pos.y / d.x, v[i - 1].pos.z / d.z};
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
	if (!(m->mesh.l = (l3d_t*)malloc(sizeof(*m->mesh.l) * (m->mesh.l_len))))
		ft_error("fdf-error: could not allocate vertex lattice");
	array_create(list, m->mesh.l, 0);
	vertex_normalize(*m, m->mesh.v, m->mesh.v_len);
}
