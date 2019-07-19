/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix_math.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:44:58 by viwade            #+#    #+#             */
/*   Updated: 2019/07/19 02:28:02 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

v3d_t
	fdf_matrix_translate(v3d_t v, tfm_t t)
{
	return ((v3d_t){
		(double){
			cos(t.rotate.y * PI / 180) * v.x
		},
		(double){
			cos(t.rotate.x * PI / 180) * v.y,
		},
		(double){
			cos(t.rotate.z * PI / 180) * v.z
		}
	});
}
