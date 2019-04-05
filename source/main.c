/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:04:16 by viwade            #+#    #+#             */
/*   Updated: 2019/04/05 16:33:41 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



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
	o.mlx.window = mlx_new_window(o.mlx.init, o.dim.x, o.dim.y, "BLANK");
	mlx_put_image_to_window(o.mlx.init, o.mlx.window, bmp.ref, 0, 0);
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
