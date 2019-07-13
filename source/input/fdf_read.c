/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:37:13 by viwade            #+#    #+#             */
/*   Updated: 2019/07/13 03:01:12 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static size_t
	item_expect(char *s)
{
	size_t	i;
	size_t	items;

	i = 0;
	items = 0;
	while (s[i] && ft_iswhitespace(s[i]))
		i++;
	while (s[i])
	{
		items += 1;
		while (s[i] && !ft_iswhitespace(s[i]))
			i++;
		while (s[i] && ft_iswhitespace(s[i]))
			i++;
	}
	return (items);
}

static t_point
	item_point(char **s, v2d_t c)
{
	t_point			p;
	union u_pixel	pxl;

	if ((s[0][0] == '-' && !ft_isdigit(s[0][1])) ||
		(s[0][0] != '-' && !ft_isdigit(s[0][0])))
		ft_error("fdf-error: invalid item value format\n");
	p.pos = (v3d_t){c.x, c.y, ft_atoi(s[0])};
	s[0] += s[0][0] == '-';
	while (s[0][0] && !ft_iswhitespace(s[0][0]) && ft_isdigit(s[0][0]))
		s[0]++;
	if (s[0][0] && s[0][0] != ',' && !ft_iswhitespace(s[0][0]))
		ft_error("fdf-error: invalid item color format");
	else if (s[0][0] && ft_iswhitespace(s[0][0]))
		p.col = (pixel_t){.r = 255, .g = 255, .b = 255};
	else if (s[0][0] == ',')
	{
		pxl.col = ft_hextol(&((++s)[0])[0]);
		p.col = (pixel_t){.r = pxl.rgb.r, .g = pxl.rgb.g, .b = pxl.rgb.b};
	}
	while (s[0][0] && ft_iswhitespace(s[0][0]))
		s[0]++;
	return (p);
}

static void
	item_list(t_verify *v)
{
	v->col = 0;
	if (!v->cols)
		v->cols = item_expect(v->line);
	else if (v->cols != item_expect(v->line))
		ft_error("fdf-error: input item count mismatch\n");
	if (!v->cols)
		ft_error("fdf-error: empty line");
	while (v->col < v->cols)
		if (v->col > v->cols)
			ft_error("fdf-error: too many items in row\n");
		else
		{
			v->point = item_point(&v->line, (v2d_t){v->col++, v->row});
			ft_lstpush(&v->lst, ft_lstnew(&v->point, sizeof(v->point)));
		}
}

static void
	array_create(t_list *lst, void *arr)
{
	size_t	i;
	t_list	*node;

	i = 0;
	if (!(node = lst))
		ft_error("fdf-error: [array_create] list is empty!");
	while (node)
	{
		ft_memcpy(arr, node->content, sizeof(t_point));
		arr += sizeof(t_point);
		node = node->next;
	}
	ft_lstdel(&lst, ft_del);
}

/*
**	Collect points, articulate position, detect color (if possible)
**	Create
**	Convert from list to array
*/

void
	fdf_read(map_t *m, int fd)
{
	t_verify	v;
	char		*tmp;

	ft_bzero(&v, sizeof(v));
	if (!(get_next_line(fd, &v.line) > 0))
		ft_error("fdf-error: nothing to read");
	while ((1))
	{
		tmp = v.line;
		if (!v.line)
			ft_error("fdf-error: nothing appended to line");
		while (ft_iswhitespace(v.line[0]))
			v.line++;
		item_list(&v);
		ft_memdel((void**)&tmp);
		v.row++;
		if (!(get_next_line(fd, &v.line) > 0))
			break ;
	}
	m->size = (v2d_t){v.cols, v.row};
	m->mesh.v_len = ft_lstlen(v.lst);
	if (!(m->mesh.v = (t_point *)malloc(sizeof(t_point) * (m->mesh.v_len))))
		ft_error("fdf-error: could not allocate vertex array");
	ft_bzero(m->mesh.v, sizeof(t_point) * (m->mesh.v_len));
	array_create(v.lst, m->mesh.v);
}
