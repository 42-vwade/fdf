/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:04:16 by viwade            #+#    #+#             */
/*   Updated: 2019/07/10 17:26:03 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
**	Ok, here I am testing how to manipulate and display an image
**	The hard part is not knowing exactly what data I am modifying
**	Trial and error dictates we try until something works. Expect errors.
**	Or worse.
*/

/*static int
	ft_introot(ssize_t n)
{
	int c;

	if (n < 0 || (size_t)n > __INT_MAX__)
		return (-1);
	if (!n)
		return (0);
	c = 1;
	while (c * c < n)
		c++;
	return (c);
}//*/

static double
	ft_sqroot(size_t n)
{
	double	c;
	double	i;

	i = 1;
	c = 0;
	if ((ssize_t)n < 0)
		return (-1.0);
	if (!n)
		return (0.0);
	while (i)
	{
		while ((c + i) * (c + i) < n)
			c += i;
		i /= 10;
	}
	return (c);
}//*/

static double
	line_length(t_line ln)
{
	return (
		ft_sqroot(
		((ln.b.pos.x - ln.a.pos.x) * (ln.b.pos.x - ln.a.pos.x)) +
		((ln.b.pos.y - ln.a.pos.y) * (ln.b.pos.y - ln.a.pos.y)) +
		((ln.b.pos.z - ln.a.pos.z) * (ln.b.pos.z - ln.a.pos.z))));
}

static t_3d
	unit_vector(t_line ln)
{
	t_3d	vec;
	double	max;

	vec = (t_3d){
		.x = ln.b.pos.x - ln.a.pos.x,
		.y = ln.b.pos.y - ln.a.pos.y,
		.z = ln.b.pos.z - ln.a.pos.z
	};
	max = MAX(MAX(vec.z, vec.y), vec.x);
	vec = (t_3d){
		.x = vec.x / ln.len,
		.y = vec.y / ln.len,
		.z = vec.z / ln.len
	};
	return (vec);
}

static void
	draw_line(t_fdf *map, t_line ln)
{
	t_3d	slope;
	t_2d	step;
	size_t	*i;

	i = (size_t[]){0, 0};
	ln.len = line_length(ln);
//	slope = (ln.b.pos.y - ln.a.pos.y) / (ln.b.pos.x - ln.a.pos.x);
	slope = unit_vector(ln);
/*	while (i[0] < (ln.b.pos.x - ln.a.pos.x))
	{
		step = (t_2d){ln.a.pos.x + i[0], ln.a.pos.y + (i[0] * slope)};
		i[0]++;
	}
	while (i[0] < ABS(slope.y))
	{
		step = (t_2d){0, 0};
		while (i[1] < ABS(slope.x))
		{

		}
		i++;
	}//*/
}

static int
	render(t_fdf *o)
{
	static int	i;
//	int		avg = AVG_2D(o->dim);
	t_img	*b;
	t_line	ln;

	b = &o->bmp;
	ln =
	(t_line){
		.a = (t_p3d){
			.pos = (t_3d){0, 0, 0},
			.col = (t_pixel){.r = 255, .g = 192, .b = 96}
		},
		.b = (t_p3d){
			.pos = (t_3d){0.5, 0.5, 0.5},
			.col = (t_pixel){.r = 160, .g = 96, .b = 0}
		},
	};
	b->start = (void *)mlx_get_data_addr(b->ref, &b->depth, &b->line, &b->endian);
	b->start[i] =
	(t_pixel){
		.r = 255 - i % 256,
		.g = 192 - i % 256,
		.b = 96 - i % 256
	};
	draw_line(o, ln);
	mlx_put_image_to_window(o->mlx.init, o->mlx.window, o->bmp.ref, 0, 0);
	i = (i + 1) % (o->bmp.width * o->bmp.height);
	return (0);
}

int
	main(int n, char **v)
{
	t_fdf	o;
	t_img	bmp;

	print_hex((long)(char *){"abc"});
	ft_putendl(ft_itoa_base((long)(char *){"abd"}, 16));

	print_memory(&bmp, sizeof(bmp)); ft_putendl(0);

	if (n == 2 || n == 4)
		ft_putendl(v[1]);
	ft_bzero(&o, sizeof(o));
	o.mlx.init = mlx_init();
	o.dim = (t_2d){512, 512};
	bmp.ref = mlx_new_image(o.mlx.init, o.dim.x, o.dim.y);
	bmp.start = (void *)mlx_get_data_addr(bmp.ref, &bmp.depth, &bmp.line, &bmp.endian);
	o.mlx.window = mlx_new_window(o.mlx.init, o.dim.x, o.dim.y, "BLANK");
	o.bmp = bmp;
	print_memory(&bmp, sizeof(bmp)); ft_putendl(0);

	mlx_loop_hook(o.mlx.init, &render, &o);
	mlx_loop(o.mlx.init);
}

/*
**	{
**		if (n == 2)
**			fdf(fdf_verify(open(v[1], O_RDONLY)));
**		else if (n == 4)
**		{
**			if (ft_atoi(v[2]) && ft_atoi(v[3]))
**				g_size = (t_v2d){ft_atoi(v[2]), ft_atoi(v[3])};
**			fdf(fdf_verify(open(v[1], O_RDONLY)));
**		}
**		else
**			ft_putendl("usage: ./fdf <filename> [ xy_size z_size]");
**	}
*/
