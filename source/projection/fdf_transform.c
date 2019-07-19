/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 23:11:32 by viwade            #+#    #+#             */
/*   Updated: 2019/07/19 12:38:21 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#define RAD(n)	((n) * PI / 180)

v3d_t
	fdf_transform(v3d_t v, tfm_t t)
{
	v3d_t	a;

	v = (v3d_t){
		t.scale.x * v.x + t.translate.x,
		t.scale.y * v.y + t.translate.y,
		t.scale.z * v.z + t.translate.z};
	a = (v3d_t){RAD(t.rotate.x), RAD(t.rotate.y), RAD(t.rotate.z)};
	v = (v3d_t){
		v.x * (1),
		v.y * (cos(a.x) - sin(a.x)),
		v.z * (sin(a.x) + cos(a.x))};
	v = (v3d_t){
		v.x * (cos(a.y) + sin(a.y)),
		v.y * (1),
		v.z * (-sin(a.y) + cos(a.y))};
	v = (v3d_t){
		v.x * (cos(a.z) - sin(a.z)),
		v.y * (sin(a.z) + cos(a.z)),
		v.z * (1)};
	return (v);
}
