/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:43:39 by viwade            #+#    #+#             */
/*   Updated: 2019/04/05 16:25:44 by viwade           ###   ########.fr       */
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
typedef struct s_mlx	t_mlx;
typedef struct s_vec3d	t_v3d;
typedef struct s_vec2d	t_v2d;
typedef struct s_pixel	t_pixel;
typedef struct s_image	t_img;
struct	s_mlx
{
	void	*init;
	void	*window;
};
struct	s_vec3d
{
	double	x;
	double	y;
	double	z;
};
struct	s_vec2d
{
	double	x;
	double	y;
};
struct	s_pixel
{
	int32_t		val;
	u_int32_t	color;
};
struct	s_image
{
	void		*ref;
	t_pixel		*pixel;
	u_int8_t	*data;
	u_int32_t	width;
	u_int32_t	height;
};
struct	s_fdf
{
	int		fd;
	t_mlx	mlx;
	t_v2d	dim;
	char	*str;
	t_list	*input;
};

void	fdf(t_fdf obj);
t_fdf	fdf_verify(int fd);

#endif
