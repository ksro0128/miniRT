/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:25:58 by surkim            #+#    #+#             */
/*   Updated: 2023/12/29 19:26:28 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_xyz	xyz(double x, double y, double z)
{
	t_xyz	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_xyz	rgb(double x, double y, double z)
{
	t_xyz	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_xyz	vec(double x, double y, double z)
{
	t_xyz	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_ray	ray(t_xyz o, t_vec dir)
{
	t_ray	ret;

	ret.o = o;
	ret.dir = vunit(dir);
	return (ret);
}

t_hit	hit_infinity(void)
{
	t_hit	ret;

	ret.t_min = INFINITY;
	return (ret);
}
