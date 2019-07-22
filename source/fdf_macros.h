/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_macros.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:39:33 by viwade            #+#    #+#             */
/*   Updated: 2019/07/21 15:18:29 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_MACROS_H
# define _FDF_MACROS_H

/*
**	COLORS
*/

# define VBLUE	0x00c0FF
# define VDAWN	0xFF6000
# define VGRSS	0xc0f060
# define VWHTE	0xFFFFFF
# define VGREY	0x808080
# define VZERO	VWHTE

/*
**	SETTINGS
*/

# define S_Z0	(0.0001220703125L)

# define BIT_DEPTH 8
# define LINE_RESOLUTION	42
# define WINDOW_PADDING		21
# define CONTROL_PANEL_X	240
# define CONTROL_PANEL_Y	420
# define VIEW_RES_MIN	(2 * CONTROL_PANEL_X)
# define VIEW_RES_MAX	(5 * CONTROL_PANEL_X)

/*
**	TYPE DEFINITION
*/

# define _TD_FDF	typedef struct s_fdf	fdf_t;
# define _TD_MLX	typedef struct s_mlx	mlx_t;
# define _TD_MAP	typedef struct s_map	map_t;
# define _TD_MSH	typedef struct s_mesh	mesh_t;
# define _TD_IMG	typedef struct s_image	img_t;
# define _TD_PXL	typedef struct s_pixel	pixel_t;
# define _UD_PXL	typedef union u_pixel	pixel_u;
# define _TD_V4D	typedef struct s_vec4d	v4d_t;
# define _TD_V3D	typedef struct s_vec3d	v3d_t;
# define _TD_P3D	typedef struct s_point3d	p3d_t;
# define _TD_L3D	typedef struct s_line3d	l3d_t;
# define _TD_V2D	typedef struct s_vec2d	v2d_t;
# define _TD_P2D	typedef struct s_point2d	p2d_t;
# define _TD_L2D	typedef struct s_line2d	l2d_t;
# define _TD_TFM	typedef struct s_transform  tfm_t;
# define _TD_CAM	typedef struct s_camera     cam_t;

_TD_FDF;
_TD_MLX;
_TD_MAP;
_TD_MSH;
_TD_IMG;
_TD_PXL;
_UD_PXL;
_TD_V4D;
_TD_V3D;
_TD_P3D;
_TD_L3D;
_TD_V2D;
_TD_P2D;
_TD_L2D;
_TD_TFM;
_TD_CAM;

#endif
