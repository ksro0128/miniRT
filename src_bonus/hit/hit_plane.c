/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:11:19 by surkim            #+#    #+#             */
/*   Updated: 2024/01/02 17:52:19 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec	cal_pl_tbn_normal(t_plane *pl, t_hit hit)
{
	t_vec		normalmap_vec;
	t_vec		tangent;
	t_vec		bitangent;
	t_matrix	tbn;

	normalmap_vec = vunit(get_rgb_plane(pl, hit, 3));
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

t_hit	hit_plane(t_plane *pl, t_ray ray, int flag)
{
	t_hit	ret;
	double	t;

	if (vdot(ray.dir, pl->v) == 0)
		return (hit_infinity());
	t = (vdot(pl->v, pl->o) - vdot(pl->v, ray.o)) / (vdot(ray.dir, pl->v));
	if (t < 0)
		return (hit_infinity());
	ret.t_min = t;
	ret.hit_point = vplus(ray.o, vmuln(ray.dir, t));
	if (vdot(ray.dir, pl->v) > 0)
		ret.n_vec = vunit(vmuln(pl->v, -1));
	else
		ret.n_vec = vunit(pl->v);
	ret.hit_point = vplus(ret.hit_point, vmuln(ret.n_vec, 0.001));
	if (flag == 2)
		ret.n_vec = cal_pl_tbn_normal(pl, ret);
	ret.rgb = get_rgb_plane(pl, ret, flag);
	return (ret);
}
