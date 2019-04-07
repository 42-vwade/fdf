/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:43:39 by viwade            #+#    #+#             */
/*   Updated: 2019/04/07 12:10:58 by viwade           ###   ########.fr       */
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
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

/*
**	//	Allowed functions	//
**	open, read, write, close
**	malloc, free, exit
**	perror, strerror
*/

void	fdf(t_fdf obj);
t_fdf	fdf_verify(int fd);

#endif
