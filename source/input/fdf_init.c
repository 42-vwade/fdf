/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:58:01 by viwade            #+#    #+#             */
/*   Updated: 2019/07/12 00:00:58 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

map_t	fdf_init(char *filename)
{
	int		fd;
	map_t	map;

	if ((fd = open(filename, O_RDONLY) < 0))
		fd_error("fdf-error: open file error");
	ft_bzero(&map, sizeof(map));
	fdf_read(&map, fd);
	fdf_line(&map, map.mesh.v_len, 0);
	close(fd);
	return (map);
}
