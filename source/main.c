/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:04:16 by viwade            #+#    #+#             */
/*   Updated: 2019/04/02 20:25:57 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int
	main(int n, char **v)
{
	t_mlx	mlx;

	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, 200, 200, "MAIN::TEST WINDOW");
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
