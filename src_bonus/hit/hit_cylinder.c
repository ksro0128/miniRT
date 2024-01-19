/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:38:36 by surkim            #+#    #+#             */
/*   Updated: 2024/01/08 15:13:18 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_abc	cal_coefficients_cy_body(t_cylinder *cy, t_ray ray)
{
	t_abc	ret;

	ret.a = pow(vlength(vcross(ray.dir, cy->v)), 2.0);
	ret.b = 2.0 * vdot(vcross(ray.dir, cy->v), \
	vminus(vcross(ray.o, cy->v), vcross(cy->o, cy->v)));
	ret.c = pow(vlength(vminus(vcross(ray.o, cy->v), \
	vcross(cy->o, cy->v))), 2.0) - pow(cy->d / 2.0, 2.0);
	return (ret);
}

t_hit	hit_cylinder_body(t_cylinder *cy, t_ray ray)
{
	t_abc	abc;
	t_hit	ret;
	double	t;

	abc = cal_coefficients_cy_body(cy, ray);
	if (cal_discriminant(abc) < 0)
		return (hit_infinity());
	t = cal_root(abc);
	ret.hit_point = vplus(ray.o, vmuln(ray.dir, t));
	if (t < 0 || fabs(vdot(vminus(cy->o, ret.hit_point), cy->v)) > cy->h / 2)
		return (hit_infinity());
	ret.t_min = t;
	ret.n_vec = vminus(vminus(ret.hit_point, cy->o), \
	vmuln(cy->v, vdot(vminus(ret.hit_point, cy->o), cy->v)));
	ret.hit_point = vplus(ret.hit_point, vmuln(ret.n_vec, 0.001));
	ret.rgb = cy->rgb;
	return (ret);
}

t_hit	hit_cylinder_top(t_cylinder *cy, t_ray ray)
{
	t_hit	ret;
	t_xyz	disk_o;
	double	t;

	disk_o = vplus(cy->o, vmuln(cy->v, cy->h / 2.0));
	if (vdot(ray.dir, cy->v) == 0)
		return (hit_infinity());
	t = (vdot(cy->v, disk_o) - vdot(cy->v, ray.o)) / (vdot(ray.dir, cy->v));
	ret.t_min = t;
	ret.hit_point = vplus(ray.o, vmuln(ray.dir, t));
	if (t < 0 || vlength(vminus(ret.hit_point, disk_o)) > cy->d / 2.0)
		return (hit_infinity());
	if (vdot(ray.dir, cy->v) > 0)
		ret.n_vec = vunit(vmuln(cy->v, -1));
	else
		ret.n_vec = vunit(cy->v);
	ret.hit_point = vplus(ret.hit_point, vmuln(ret.n_vec, 0.001));
	ret.rgb = cy->rgb;
	return (ret);
}

t_hit	hit_cylinder_bottom(t_cylinder *cy, t_ray ray)
{
	t_hit	ret;
	t_xyz	disk_o;
	double	t;

	disk_o = vplus(cy->o, vmuln(cy->v, -cy->h / 2.0));
	if (vdot(ray.dir, cy->v) == 0)
		return (hit_infinity());
	t = (vdot(cy->v, disk_o) - vdot(cy->v, ray.o)) / (vdot(ray.dir, cy->v));
	ret.t_min = t;
	ret.hit_point = vplus(ray.o, vmuln(ray.dir, t));
	if (t < 0 || vlength(vminus(ret.hit_point, disk_o)) > cy->d / 2.0)
		return (hit_infinity());
	if (vdot(ray.dir, cy->v) > 0)
		ret.n_vec = vunit(vmuln(cy->v, -1));
	else
		ret.n_vec = vunit(cy->v);
	ret.hit_point = vplus(ret.hit_point, vmuln(ret.n_vec, 0.001));
	ret.rgb = cy->rgb;
	return (ret);
}

t_hit	hit_cylinder(t_cylinder *cy, t_ray ray, int flag)
{
	t_hit	ret;
	t_hit	tmp;

	ret = hit_cylinder_body(cy, ray);
	tmp = hit_cylinder_top(cy, ray);
	if (tmp.t_min != INFINITY && tmp.t_min < ret.t_min)
		ret = tmp;
	tmp = hit_cylinder_bottom(cy, ray);
	if (tmp.t_min != INFINITY && tmp.t_min < ret.t_min)
		ret = tmp;
	if (ret.t_min != INFINITY)
		ret.rgb = get_rgb_cylinder(cy, ret, flag);
	if (ret.t_min != INFINITY && flag == 2)
		ret.n_vec = cal_cy_tbn_normal(cy, ret);
	return (ret);
}
