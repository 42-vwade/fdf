/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:04:16 by viwade            #+#    #+#             */
/*   Updated: 2019/04/22 07:45:42 by viwade           ###   ########.fr       */
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

static int
	render(t_fdf *o)
{
	static int	i;
	int		avg = AVG_2D(o->dim);
	char	*bmp;

	bmp = &o->bmp.ref;
	if (!(i % (avg)))
		print_memory(bmp, sizeof(*bmp));
	bmp[i] = i;
	mlx_put_image_to_window(o->mlx.init, o->mlx.window, o->bmp.ref, 0, 0);
	i = (i + 1) % (avg);
	return (0);
}

int
	main(int n, char **v)
{
	t_fdf	o;
	t_img	bmp;

	print_hex((long)(char *){"abc"});
	ft_putendl(ft_itoa_base((long)(char *){"abd"}, 16));

	print_memory(&bmp, sizeof(bmp));

	return 0;

	if (n == 2 || n == 4)
		ft_putendl(v[1]);
	ft_bzero(&o, sizeof(o));
	o.mlx.init = mlx_init();
	o.dim = (t_2d){500, 500};
	bmp.ref = mlx_new_image(o.mlx.init, o.dim.x, o.dim.y);
	bmp.start = mlx_get_data_addr(bmp.ref, &bmp.depth, &bmp.line, &bmp.endian);
	o.mlx.window = mlx_new_window(o.mlx.init, o.dim.x, o.dim.y, "BLANK");
	o.bmp = bmp;

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
