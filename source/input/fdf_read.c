/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:37:13 by viwade            #+#    #+#             */
/*   Updated: 2019/07/10 23:56:32 by viwade           ###   ########.fr       */
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
	while (ft_iswhitespace(s[i]) && s[i])
		i++;
	while (s[i])
	{
		items += 1;
		while (!ft_iswhitespace(s[i]) && s[i])
			i++;
		while (ft_iswhitespace(s[i]) && s[i])
			i++;
	}
	return (items);
}

static t_point
	item_point(char *s, v2d_t c)
{
	t_point	p;
	int		col;

	if ((s[0] == '-' && !ft_isdigit(s[1])) ||
		(s[0] != '-' && !ft_isdigit(s[0])))
		ft_error("fdf-error: invalid item value format\n");
	p.pos = (v3d_t){c.x, c.y, ft_atoi(s)};
	s += s[0] == '-';
	while (s[0] && !ft_iswhitespace(s[0]) && ft_isdigit(s[0]))
		s++;
	if (s[0] != ',' && !ft_iswhitespace(s[0]))
		ft_error("fdf-error: invalid item color format");
	else if (ft_iswhitespace(s[0]))
		p.col = (t_pixel){.r = 255, .g = 255, .b = 255};
	else if (s[0] == ',')
	{
		col = ft_hextol(&(++s)[0]);
		p.col = (t_pixel){.r = col >> 16, .g = col >> 8, .b = col};
	}
	return (p);
}

static t_list


static void
	item_list(t_verify *v)
{
	v->col = 0;
	if (!v->cols)
		v->cols = item_expect(v->line);
	else if (v->cols != item_expect(v->line))
		ft_error("fdf-error: input item count mismatch\n");
	while (v->line[0])
		if (v->col > v->cols)
			ft_error("fdf-error: too many items in row\n");
		else
		{
			v->point = item_point(v->line, (v2d_t){v->col++, v->row});
			ft_lstpush(&v->lst, ft_lstnew(&v->point, sizeof(v->point)));
		}
}

static void
	array_create(t_verify *v)
{
	size_t	i;
	t_list	*node;

	i = 0;
	node = v->lst;
	while (i < v->len)
	{
		v->arr[i++] = *(t_point *)node->content;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	ft_lstdel(&v->lst, ft_del);
}

t_point
	*fdf_read(int fd)
{
	t_verify	v;

	ft_bzero(&v, sizeof(v));
	while (get_next_line(fd, &v.line) > 1)
	{
		while (ft_iswhitespace(v.line[0]))
			v.line++;
		item_list(&v);
		v.row++;
	}
	v.len = ft_lstlen(v.lst);
	if (!(v.arr = (t_point *)malloc(v.len * sizeof(t_point))))
		ft_error("fdf-error: could not allocate vertex array");
	array_create(&v);
	return (v.arr);
}
