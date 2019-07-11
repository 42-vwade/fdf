/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:49:13 by viwade            #+#    #+#             */
/*   Updated: 2019/07/10 16:06:29 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	VERIFY THE FOLLOWING BEFORE TURNING IN <<>> THEN DELETE THIS SECTION
**	TIME.H	--	MAY NOT BE ALLOWED		[?]
**	PTHREAD.H	--	MAY NOT BE ALLOWED	[?]
*/

#ifndef _FDF_STRUCTS_H
# define _FDF_STRUCTS_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <pthread.h>
# include "fdf_macros.h"
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

/*
** ENUMERATION
*/

/*
** UNION
*/

union	u_pixel
{
	char	r;
	char	g;
	char	b;
};

/*
** TYPE DEFINITIONS
*/

typedef struct s_fdf	t_fdf;
typedef struct s_mlx	t_mlx;
typedef struct s_verify	t_verify;
typedef struct s_vec3d	t_3d;
typedef struct s_vec2d	t_2d;
typedef struct s_point2d	t_p2d;
typedef struct s_point3d	t_point;
typedef struct s_line2d	t_line2d;
typedef struct s_line3d	t_line;
typedef struct s_pixel	t_pixel;
typedef struct s_image	t_img;
typedef struct s_map	t_map;

/*
** STRUCT
*/

struct	s_mlx
{
	void	*init;
	void	*window;
};

struct	s_pixel
{
	unsigned int	b:BIT_DEPTH;
	unsigned int	g:BIT_DEPTH;
	unsigned int	r:BIT_DEPTH;
};

struct	s_vec2d
{
	int	x;
	int	y;
};

struct	s_vec3d
{
	double	x;
	double	y;
	double	z;
};

struct	s_point2d
{
	v2d_t	pos;
	pixel_t	color;
};

struct	s_point3d
{
	pixel_t	col;
	v3d_t	pos;
};

struct	s_line2d
{
	p2d_t	a;
	p2d_t	b;
};

struct	s_line3d
{
	p3d_t	a;
	p3d_t	b;
	double	len;
};

struct	s_image
{
	void		*ref;
	pixel_t		*pixel;
	pixel_t		*start;
	int			depth;
	int			line;
	int			endian;
	uint32_t	width;
	uint32_t	height;
};

struct	s_map
{
	t_point	point;
	t_map	*right;
	t_map	*down;
};

struct	s_verify
{
	char	*line;
	t_list	*lst;
	size_t	len;
	t_point	*arr;
	size_t	i;
	size_t	col;
	size_t	row;
	size_t	cols;
	p3d_t	point;
	v2d_t	pos;
	map_t	*map;
};

struct	s_fdf
{
	int		fd;
	t_mlx	m;
	size_t	width;
	size_t	height;
	size_t	resolution;
	t_img	bmp;
	t_list	*input;
	void	*param;
};

#endif
