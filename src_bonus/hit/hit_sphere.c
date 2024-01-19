/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:47:33 by surkim            #+#    #+#             */
/*   Updated: 2024/01/02 17:52:29 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_abc	cal_coefficients_sphere(t_sphere *sp, t_ray ray)
{
	t_abc	ret;

	ret.a = pow(vlength(ray.dir), 2.0);
	ret.b = 2.0 * vdot(ray.dir, vminus(ray.o, sp->o));
	ret.c = pow(vlength(vminus(ray.o, sp->o)), 2.0) \
	- pow(sp->d / 2, 2.0);
	return (ret);
}

void	print_vec(t_vec a)
{
	printf("%f %f %f\n", a.x, a.y, a.z);
}

t_vec	cal_sp_tbn_normal(t_sphere *sp, t_hit hit)
{
	t_vec		normalmap_vec;
	t_vec		tangent;
	t_vec		bitangent;
	t_matrix	tbn;

	normalmap_vec = vunit(get_rgb_sphere(sp, hit, 3));
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

t_hit	hit_sphere(t_sphere *sp, t_ray ray, int flag)
{
	t_hit	ret;
	t_abc	abc;
	double	t;

	abc = cal_coefficients_sphere(sp, ray);
	if (cal_discriminant(abc) < 0)
		return (hit_infinity());
	t = cal_root(abc);
	if (t < 0)
		return (hit_infinity());
	ret.t_min = t;
	ret.hit_point = vplus(ray.o, vmuln(ray.dir, t));
	ret.n_vec = vunit(vminus(ret.hit_point, sp->o));
	ret.hit_point = vplus(ret.hit_point, vmuln(ret.n_vec, 0.001));
	if (flag == 2)
		ret.n_vec = cal_sp_tbn_normal(sp, ret);
	ret.rgb = get_rgb_sphere(sp, ret, flag);
	return (ret);
}
