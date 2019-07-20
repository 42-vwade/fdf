/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:43:39 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 14:47:42 by viwade           ###   ########.fr       */
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
# include "keycodes_mac.h"
# include "mousecodes_mac.h"
# include "fdf_macros.h"
# include "fdf_structs.h"
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# define PI	(3.141592653589793238462643383279502884197169399375105820974944592L)
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
void	fdf_create_vertex_array(p3d_t **dst, size_t num_elements);
void	fdf_create_line_array(l3d_t **dst, size_t num_elements);
void	fdf_print_vertex(mesh_t map_object);
void	fdf_print_line(mesh_t map_object);
v2d_t	fdf_window_size(v2d_t map_size);
void	fdf_hook(fdf_t *o);
int		fdf_run_loop(fdf_t *o);
void	fdf_reset(fdf_t *o);
void	fdf_projection(fdf_t *o);
void	fdf_draw(t_map2d *m);
void	fdf_pixel(fdf_t *o, v2d_t pos, pixel_t col);

v3d_t	fdf_transform(v3d_t reference_vector, tfm_t transform);
v3d_t	fdf_rotate2d(v2d_t t, v3d_t v);

void	fdf_redraw(fdf_t *o);
void	fdf_color_mode(fdf_t *o);
void	*fdf_keyboard(size_t i);
int		key_press(int keycode, fdf_t *o);
int		key_release(int keycode, fdf_t *o);
int		key_event(int keycode, fdf_t *o);
void	*fdf_mouse(size_t i);
int		mouse_down(int button, int x, int y, fdf_t *o);
int		mouse_up(int button, int x, int y, fdf_t *o);
int		mouse_move(int x, int y, fdf_t *o);

#endif
