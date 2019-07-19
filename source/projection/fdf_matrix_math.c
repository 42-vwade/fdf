/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix_math.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:44:58 by viwade            #+#    #+#             */
/*   Updated: 2019/07/19 10:26:26 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define RAD(n)	((n) * PI / 180)

v3d_t
	fdf_matrix_rotate(v3d_t v, v3d_t t)
{
	v4d_t	*d;

	t = (v3d_t){RAD(t.x), RAD(t.y), RAD(t.z)};
	v = (v3d_t){
		v.x * (1),
		v.y * (cos(t.x) + -sin(t.x)),
		v.z * (sin(t.x) + cos(t.x))};
	v = (v3d_t){
		v.x * (cos(t.y) + sin(t.y)),
		v.y * (1),
		v.z * (-sin(t.y) + cos(t.y))};
	v = (v3d_t){
		v.x * (cos(t.z) + -sin(t.z)),
		v.y * (sin(t.z) + cos(t.z)),
		v.z * (1)};
	return (v);
}

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
