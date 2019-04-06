/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:04:16 by viwade            #+#    #+#             */
/*   Updated: 2019/04/06 08:31:04 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int
	render(t_fdf *o)
{
	static int	i;

	if (!(i % 1000))
		print_memory(o, sizeof(*o));
	mlx_put_image_to_window(o->mlx.init, o->mlx.window, o->bmp.ref, 0, 0);
	i = (i + 1) % 1000;
}

int
	main(int n, char **v)
{
	t_fdf	o;
	t_img	bmp;

	if (n == 2)
		ft_putendl(v[1]);
	o.mlx.init = mlx_init();
	o.dim = (t_v2d){500, 500};
	bmp.ref = mlx_new_image(o.mlx.init, o.dim.x, o.dim.y);
	bmp.start = mlx_get_data_addr(bmp.ref, &bmp.depth, &bmp.line, &bmp.endian);
	o.mlx.window = mlx_new_window(o.mlx.init, o.dim.x, o.dim.y, "BLANK");
	o.bmp = bmp;
	o.param = &o;
	mlx_loop_hook(o.mlx.init, &render, o.param);
	mlx_loop(o.mlx.init);
}

/*{
	if (n == 2)
		fdf(fdf_verify(open(v[1], O_RDONLY)));
	else if (n == 4)
	{
		if (ft_atoi(v[2]) && ft_atoi(v[3]))
			g_size = (t_v2d){ft_atoi(v[2]), ft_atoi(v[3])};
		fdf(fdf_verify(open(v[1], O_RDONLY)));
	}
	else
		ft_putendl("usage: ./fdf <filename> [ xy_size z_size]");
}*/
