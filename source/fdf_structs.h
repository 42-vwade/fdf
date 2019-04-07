/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:49:13 by viwade            #+#    #+#             */
/*   Updated: 2019/04/07 14:54:01 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	VERIFY THE FOLLOWING BEFORE TURNING IN <<>> THEN DELETE THIS SECTION
**	TIME.H	--	MAY NOT BE ALLOWED		[?]
**	PTHREAD.H	--	MAY NOT BE ALLOWED	[?]
*/

#ifndef FT_FDF_STRUCTS_H
# define FT_FDF_STRUCTS_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <pthread.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

/*
** ENUMERATION
*/

/*
** TYPE DEFINITIONS
*/

typedef struct s_fdf	t_fdf;
typedef struct s_mlx	t_mlx;
typedef struct s_vec3d	t_3d;
typedef struct s_vec2d	t_2d;
typedef struct s_pixel	t_pixel;
typedef struct s_image	t_img;

/*
** STRUCT
*/

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
	char		*start;
	int			depth;
	int			line;
	int			endian;
	uint32_t	width;
	uint32_t	height;
};

struct	s_fdf
{
	int		fd;
	t_mlx	mlx;
	t_2d	dim;
	t_img	bmp;
	t_list	*input;
	void	*param;
};

#endif
