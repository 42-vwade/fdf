/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:49:13 by viwade            #+#    #+#             */
/*   Updated: 2019/07/21 16:51:53 by viwade           ###   ########.fr       */
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
# include "../.minilibx/mlx.h"
# include "../libft/libft.h"

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
typedef struct s_verts	t_vert;
typedef struct s_map2d	t_map2d;

/*
** ENUMERATION
*/

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

union	u_pixel
{
	unsigned int	col;
	struct s_pixel	rgb;
};

struct	s_vec2d
{
	ssize_t	x;
	ssize_t	y;
};

struct	s_vec3d
{
	double	x;
	double	y;
	double	z;
};

struct	s_vec4d
{
	double	x;
	double	y;
	double	z;
	double	w;
};

struct	s_point2d
{
	v2d_t	pos;
	pixel_t	col;
};

struct	s_point3d
{
	v3d_t	pos;
	pixel_t	col;
};

struct	s_line2d
{
	p2d_t	a;
	p2d_t	b;
};

struct	s_line3d
{
	p3d_t	*a;
	p3d_t	*b;
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

struct	s_transform
{
	v3d_t	translate;
	v3d_t	rotate;
	v3d_t	scale;
};

struct	s_camera
{
	v3d_t	pos;
	ld_t	angle;
	tfm_t	transform;
};

struct	s_mesh
{
	p3d_t		*v;
	const p3d_t	*ref_v;
	const l3d_t	*l;
	size_t		v_len;
	size_t		l_len;
};

struct	s_map
{
	mesh_t	mesh;
	v2d_t	size;
	tfm_t	cam;
	tfm_t	transform;
	ld_t	aspect;
};

struct	s_map2d
{
	map_t	*m3d;
	p2d_t	*v;
	l2d_t	*l;
	size_t	v_len;
	size_t	l_len;
	v2d_t	size;
};

struct	s_verify
{
	char	*line;
	t_list	*lst;
	size_t	len;
	p3d_t	*arr;
	size_t	i;
	size_t	col;
	size_t	row;
	size_t	cols;
	p3d_t	point;
	v2d_t	pos;
};

struct	s_fdf
{
	int		fd;
	map_t	map;
	char	*m_title;
	void	*m_init;
	void	*m_window;
	void	*m_image;
	void	*m_start;
	char	iso;
	char	key[256];
	char	mouse[16];
	v2d_t	mouse_xy;
	char	mode;
	char	modes;
	size_t	width;
	size_t	height;
	v2d_t	dim;
	size_t	resolution;
	t_img	bmp;
	t_list	*input;
	char	redraw;
	void	*param;
};

/*
** UNION
*/

#endif
