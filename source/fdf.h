/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:43:39 by viwade            #+#    #+#             */
/*   Updated: 2019/07/13 04:42:15 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <pthread.h>
# include "fdf_structs.h"
# include "fdf_macros.h"
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# define AVG_2D(c) ( ((c).x  + (c).y) / 2 )

/*
**	//	Allowed functions	//
**	open, read, write, close
**	malloc, free, exit
**	perror, strerror
*/

void	fdf(char *filename);
map_t	fdf_init(char *filename);
void	fdf_read(map_t *map_object, int file_desc);
void	fdf_line(map_t *map_object, size_t size, size_t i);
void	fdf_print_vertex(mesh_t map_object);
v2d_t	fdf_window_size(v2d_t map_size);

#endif
