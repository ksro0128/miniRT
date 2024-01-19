/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:53:57 by youngcki          #+#    #+#             */
/*   Updated: 2023/12/29 15:54:08 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	get_rgb_plane_case1(double u, double v, t_rgb rgb)
{
	int	ucheck;
	int	vcheck;

	ucheck = (int)u;
	vcheck = (int)v;
	if (ucheck % 2 == 0)
	{
		if (vcheck % 2 == 0)
			return (get_complementary_color(rgb));
		else
			return (rgb);
	}
	else
	{
		if (vcheck % 2 == 0)
			return (rgb);
		else
			return (get_complementary_color(rgb));
	}
}

t_rgb	get_rgb_plane_case2(double u, double v, t_rgb rgb)
{
	int	ucheck;
	int	vcheck;

	ucheck = (int)u;
	vcheck = (int)v;
	if (ucheck % 2 == 0)
	{
		if (vcheck % 2 == 0)
			return (rgb);
		else
			return (get_complementary_color(rgb));
	}
	else
	{
		if (vcheck % 2 == 0)
			return (get_complementary_color(rgb));
		else
			return (rgb);
	}
}

t_rgb	get_pl_checker_rgb(double x, double y, t_rgb rgb)
{
	if (x * y > 0)
		return (get_rgb_plane_case1(x / 10, y / 10, rgb));
	else
		return (get_rgb_plane_case2(x / 10, y / 10, rgb));
}

t_rgb	get_rgb_plane(t_plane *pl, t_hit hit, int flag)
{
	t_xyz	center_to_hit;
	double	u;
	double	v;

	if (flag == 0)
		return (pl->rgb);
	center_to_hit = vminus(hit.hit_point, pl->o);
	u = vdot(center_to_hit, pl->nor.x);
	v = vdot(center_to_hit, pl->nor.y);
	if (flag == 1)
		return (get_pl_checker_rgb(u, v, pl->rgb));
	else if (flag == 2)
		return (get_pl_texture_rgb(u, v, pl->img));
	else
		return (get_pl_normal_rgb(u, v, pl->himg));
}
