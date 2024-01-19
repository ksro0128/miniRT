/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:11:19 by surkim            #+#    #+#             */
/*   Updated: 2023/12/20 19:30:43 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_hit	hit_plane(t_plane *pl, t_ray ray)
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
	ret.rgb = pl->rgb;
	return (ret);
}
