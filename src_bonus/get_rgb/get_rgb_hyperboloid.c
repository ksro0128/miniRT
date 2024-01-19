/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_hyperboloid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:54:01 by youngcki          #+#    #+#             */
/*   Updated: 2023/12/29 20:17:37 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	get_hyperboloid_checker_theta(t_hyperboloid *hb, t_hit hit)
{
	t_vec	o_to_hit;
	t_vec	v;
	double	len;
	double	theta;

	o_to_hit = vminus(hit.hit_point, hb->center);
	len = vdot(hb->v, o_to_hit);
	v = vunit(vplus(o_to_hit, vmuln(hb->v, -len)));
	theta = acos(vdot(hb->nor.x, v)) * 180.0 / M_PI;
	if (vdot(vcross(hb->nor.x, v), hb->v) < 0)
		theta = 360 - theta;
	return (theta);
}

double	get_hyperboloid_checker_len(t_hyperboloid *hb, t_hit hit)
{
	double	len;
	t_vec	o;

	o = vminus(hit.hit_point, hb->center);
	len = vdot(o, hb->v);
	if (len < 0)
		len = len * -1 + 1;
	return (len);
}

t_rgb	get_hb_checker_rgb(double x, double y, t_rgb rgb)
{
	int	xx;
	int	yy;

	xx = x * 20;
	yy = y * M_PI;
	if ((xx + yy) % 2 == 0)
		return (get_complementary_color(rgb));
	else
		return (rgb);
}

t_rgb	get_rgb_hyperboloid(t_hyperboloid *hb, t_hit hit, int flag)
{
	double	len;
	double	theta;

	if (flag == 0)
		return (hb->rgb);
	else
	{
		len = get_hyperboloid_checker_len(hb, hit);
		theta = get_hyperboloid_checker_theta(hb, hit) / 360;
		if (flag == 1)
			return (get_hb_checker_rgb(theta, len, hb->rgb));
		else if (flag == 2)
			return (get_hb_texture_rgb(theta, len, hb->img));
		else
			return (get_hb_normal_rgb(theta, len, hb->himg));
	}
}
