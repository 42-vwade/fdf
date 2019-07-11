/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_macros.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:39:33 by viwade            #+#    #+#             */
/*   Updated: 2019/07/10 16:03:59 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_MACROS_H
# define _FDF_MACROS_H
# include "fdf_structs.h"

/*
**	SETTINGS
*/

# define BIT_DEPTH 8

/*
**	TYPE DEFINITION
*/

# define _TD_FDF	typedef struct s_fdf	fdf_t;
# define _TD_MLX	typedef struct s_mlx	mlx_t;
# define _TD_MAP	typedef struct s_map	map_t;
# define _TD_IMG	typedef struct s_image	img_t;
# define _TD_PXL	typedef struct s_pixel	pixel_t;
# define _TD_V3D	typedef struct s_vec3d	v3d_t;
# define _TD_P3D	typedef struct s_point3d	p3d_t;
# define _TD_L3D	typedef struct s_line3d	l3d_t;
# define _TD_V2D	typedef struct s_vec2d	v2d_t;
# define _TD_P2D	typedef struct s_point2d	p2d_t;
# define _TD_L2D	typedef struct s_line2d	l2d_t;

_TD_FDF;
_TD_MLX;
_TD_MAP;
_TD_IMG;
_TD_PXL;
_TD_V3D;
_TD_P3D;
_TD_L3D;
_TD_V2D;
_TD_P2D;
_TD_L2D;

#endif
