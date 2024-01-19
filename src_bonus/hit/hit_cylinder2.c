/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:16:54 by youngcki          #+#    #+#             */
/*   Updated: 2024/01/02 17:52:33 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	cal_cy_tbn_normal(t_cylinder *cy, t_hit hit)
{
	t_vec		normalmap_vec;
	t_vec		tangent;
	t_vec		bitangent;
	t_matrix	tbn;

	normalmap_vec = vunit(get_rgb_cylinder(cy, hit, 3));
	tangent = vunit(vminus(vec(0, 0, 1), \
	vmuln(hit.n_vec, vdot(vec(0, 0, 1), hit.n_vec))));
	if (hit.n_vec.x == 0 && hit.n_vec.y == 0)
		tangent = vec(1, 0, 0);
	bitangent = vunit(vcross(hit.n_vec, tangent));
	tbn.x = tangent;
	tbn.y = bitangent;
	tbn.z = hit.n_vec;
	tbn = transpose_matrix(tbn);
	hit.n_vec = vunit(cal_matrix_vec(tbn, normalmap_vec));
	return (hit.n_vec);
}
