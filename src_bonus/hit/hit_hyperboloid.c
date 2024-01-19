/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_hyperboloid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:58:07 by youngcki          #+#    #+#             */
/*   Updated: 2024/01/02 17:52:24 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_abc	cal_coefficient_hb(t_ray ray, t_hyperboloid *hb)
{
	t_abc		ret;
	t_vec		ad;
	t_vec		ab;
	t_vec		b;
	t_matrix	a;

	a = cal_matrix_matrix(transpose_matrix(hb->nor), hb->abc);
	a = cal_matrix_matrix(a, hb->nor);
	b = vminus(ray.o, hb->center);
	ad = cal_matrix_vec(a, ray.dir);
	ab = cal_matrix_vec(a, b);
	ret.a = vdot(ray.dir, ad);
	ret.b = vdot(ray.dir, ab) + vdot(b, ad);
	ret.c = vdot(b, ab) - 1;
	return (ret);
}

t_vec	cal_normal_hb(t_hit hit, t_hyperboloid *hb)
{
	t_vec		ret;
	t_matrix	a;

	a = cal_matrix_matrix(transpose_matrix(hb->nor), hb->abc);
	a = cal_matrix_matrix(a, hb->nor);
	ret = vunit(cal_matrix_vec(a, vminus(hit.hit_point, hb->center)));
	return (ret);
}

t_vec	cal_hb_tbn_normal(t_hyperboloid *hb, t_hit hit)
{
	t_vec		normalmap_vec;
	t_vec		tangent;
	t_vec		bitangent;
	t_matrix	tbn;

	normalmap_vec = vunit(get_rgb_hyperboloid(hb, hit, 3));
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

t_hit	hit_hyperboloid(t_hyperboloid *hb, t_ray ray, int flag)
{
	t_hit	ret;
	t_abc	abc;
	double	t;

	abc = cal_coefficient_hb(ray, hb);
	if (cal_discriminant(abc) < 0)
		return (hit_infinity());
	t = cal_root(abc);
	if (t < 0)
		return (hit_infinity());
	ft_memset(&ret, 0, sizeof(t_hit));
	ret.t_min = t;
	ret.hit_point = vplus(ray.o, vmuln(ray.dir, t));
	ret.n_vec = cal_normal_hb(ret, hb);
	ret.hit_point = vplus(ret.hit_point, vmuln(ret.n_vec, 0.001));
	if (flag == 2)
		ret.n_vec = cal_hb_tbn_normal(hb, ret);
	ret.rgb = get_rgb_hyperboloid(hb, ret, flag);
	return (ret);
}
