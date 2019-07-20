/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 23:11:32 by viwade            #+#    #+#             */
/*   Updated: 2019/07/20 02:26:37 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define D2RAD(n)	(PI * (n) / 180.0)

v3d_t
	fdf_transform(v3d_t v, tfm_t t)
{
	v3d_t	angle;

	angle = (v3d_t){D2RAD(t.rotate.x), D2RAD(t.rotate.y), D2RAD(t.rotate.z)};
	v = (v3d_t){
		v.x * (1),
		v.y * (cos(angle.x) + -sin(angle.x)),
		v.z * (sin(angle.x) + cos(angle.x))};
	v = (v3d_t){
		v.x * (cos(angle.y) + sin(angle.y)),
		v.y * (1),
		v.z * (-sin(angle.y) + cos(angle.y))};
	v = (v3d_t){
		v.x * (cos(angle.z) + -sin(angle.z)),
		v.y * (sin(angle.z) + cos(angle.z)),
		v.z * (1)};
	v = (v3d_t){
		t.scale.x * v.x + t.translate.x,
		t.scale.y * v.y + t.translate.y,
		t.scale.z * v.z + t.translate.z};
	return (v);
}
