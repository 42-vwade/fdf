/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:43:39 by viwade            #+#    #+#             */
/*   Updated: 2019/03/28 17:56:04 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

/*
**	//	Allowed functions	//
**	open, read, write, close
**	malloc, free, exit
**	perror, strerror
*/

typedef struct s_fdf	t_fdf;
typedef struct s_vec3d	t_v3d;
typedef struct s_vec2d	t_v2d;
typedef struct s_elem	t_elem;
struct s_fdf
{
	int		fd;
	char	**
	t_list	*input;
};
struct	s_vec3d
{
	int64_t	x;
	int64_t	y;
	int64_t	z;
};
struct	s_vec2d
{
	int64_t	x;
	int64_t	y;
};
struct	s_elem
{
	t_v2d		c;
	int32_t		val;
	u_int32_t	color;
};

t_fdf	fdf_verify(int fd);

#endif
