/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:29:20 by surkim            #+#    #+#             */
/*   Updated: 2023/12/29 16:27:13 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec	vcross(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret.x = v1.y * v2.z - v1.z * v2.y;
	ret.y = v1.z * v2.x - v1.x * v2.z;
	ret.z = v1.x * v2.y - v1.y * v2.x;
	return (ret);
}

t_vec	vunit(t_vec v)
{
	return (vdivn(v, vlength(v)));
}

double	vdot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	vlength(t_vec v)
{
	return (sqrt(vdot(v, v)));
}

t_matrix	set_nor(t_vec v)
{
	t_matrix	ret;
	t_vec		up;

	if (v.x == 0 && v.y == 0)
	{
		ret.z = v;
		ret.x = vec(1, 0, 0);
		ret.y = vec(0, 1, 0);
	}
	else
	{
		up = vec(0, 0, 1);
		ret.x = vunit(vcross(up, v));
		ret.y = vunit(vcross(v, ret.x));
		ret.z = v;
	}
	return (ret);
}
