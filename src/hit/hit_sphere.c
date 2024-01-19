/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:47:33 by surkim            #+#    #+#             */
/*   Updated: 2023/12/20 16:41:01 by surkim           ###   ########.fr       */
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

t_hit	hit_sphere(t_sphere *sp, t_ray ray)
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
	ret.rgb = sp->rgb;
	return (ret);
}
