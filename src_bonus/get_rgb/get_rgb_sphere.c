/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:21:46 by youngcki          #+#    #+#             */
/*   Updated: 2023/12/29 15:52:21 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	get_sp_checker_rgb(double x, double y, t_rgb rgb)
{
	int	xx;
	int	yy;

	xx = x * 5 * M_PI;
	yy = y * 10;
	if ((xx + yy) % 2 == 0)
		return (get_complementary_color(rgb));
	else
		return (rgb);
}

t_rgb	get_rgb_sphere(t_sphere *sp, t_hit hit, int flag)
{
	t_vec	o_to_hit;
	t_vec	v;
	double	len;
	double	theta;

	if (flag == 0)
		return (sp->rgb);
	o_to_hit = vminus(hit.hit_point, sp->o);
	len = vdot(vec(0, 0, 1), o_to_hit);
	v = vunit(vplus(o_to_hit, vmuln(vec(0, 0, -1), len)));
	if (len <= 0)
		len = len * -1 + (sp->d / 2);
	else
		len = (sp->d / 2) - len;
	len /= sp->d;
	theta = acos(vdot(vec(1, 0, 0), v)) * (180 / M_PI);
	if (vdot(vcross(vec(1, 0, 0), v), vec(0, 0, 1)) < 0)
		theta = 360 - theta;
	theta /= 360;
	if (flag == 1)
		return (get_sp_checker_rgb(len, theta, sp->rgb));
	else if (flag == 2)
		return (vdivn(get_sp_texture_rgb(theta, len, sp->img), 255));
	else
		return (get_sp_normal_rgb(theta, len, sp->himg));
}
