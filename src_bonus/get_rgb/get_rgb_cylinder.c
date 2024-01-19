/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:25:16 by youngcki          #+#    #+#             */
/*   Updated: 2024/01/08 15:05:48 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	get_cylinder_checker_len(t_cylinder *cy, t_hit hit)
{
	t_xyz	top_disk_o;
	t_xyz	bottom_disk_o;
	t_vec	topdisk_to_hit;
	double	len;

	top_disk_o = vplus(cy->o, vmuln(cy->v, cy->h / 2));
	bottom_disk_o = vplus(cy->o, vmuln(cy->v, -cy->h / 2));
	topdisk_to_hit = vminus(hit.hit_point, top_disk_o);
	if (vdot(cy->v, hit.n_vec) > 0.90)
		return (vlength(topdisk_to_hit));
	else if (vdot(cy->v, hit.n_vec) < -0.90)
	{
		len = cy->d / 2 - vlength(vminus(hit.hit_point, bottom_disk_o));
		return (cy->h + cy->d / 2 + len);
	}
	else
	{
		topdisk_to_hit = vminus(hit.hit_point, top_disk_o);
		len = cy->d / 2 + vdot(topdisk_to_hit, vmuln(cy->v, -1));
		return (len);
	}
}

double	get_cylinder_checker_theta(t_cylinder *cy, t_hit hit)
{
	t_vec	o_to_hit;
	t_vec	v;
	double	len;
	double	theta;

	o_to_hit = vminus(hit.hit_point, cy->o);
	len = vdot(cy->v, o_to_hit);
	v = vunit(vplus(o_to_hit, vmuln(cy->v, -len)));
	theta = acos(vdot(cy->nor.x, v)) * 180.0 / M_PI;
	if (vdot(vcross(cy->nor.x, v), cy->v) < 0)
		theta = 360 - theta;
	return (theta);
}

t_rgb	get_cy_checker_rgb(double x, double y, t_rgb rgb)
{
	int	xx;
	int	yy;

	xx = x * 10 * M_PI;
	yy = y * 10;
	if ((xx + yy) % 2 == 0)
		return (get_complementary_color(rgb));
	else
		return (rgb);
}

t_rgb	get_rgb_cylinder(t_cylinder *cy, t_hit hit, int flag)
{
	double	len;
	double	theta;

	if (flag == 0)
		return (cy->rgb);
	len = get_cylinder_checker_len(cy, hit) / (cy->d + cy->h);
	if (len > 1.0)
		printf("%f\n", len);
	theta = get_cylinder_checker_theta(cy, hit) / 360;
	if (flag == 1)
		return (get_cy_checker_rgb(len, theta, cy->rgb));
	else if (flag == 2)
		return (get_cy_texture_rgb(theta, len, cy->img));
	else
		return (get_cy_normal_rgb(theta, len, cy->himg));
}
