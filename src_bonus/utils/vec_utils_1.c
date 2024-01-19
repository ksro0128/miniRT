/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:26:40 by surkim            #+#    #+#             */
/*   Updated: 2023/12/20 11:28:49 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec	vplus(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	ret.z = v1.z + v2.z;
	return (ret);
}

t_vec	vminus(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret.x = v1.x - v2.x;
	ret.y = v1.y - v2.y;
	ret.z = v1.z - v2.z;
	return (ret);
}

t_vec	vmulv(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret.x = v1.x * v2.x;
	ret.y = v1.y * v2.y;
	ret.z = v1.z * v2.z;
	return (ret);
}

t_vec	vmuln(t_vec v, double d)
{
	t_vec	ret;

	ret.x = v.x * d;
	ret.y = v.y * d;
	ret.z = v.z * d;
	return (ret);
}

t_vec	vdivn(t_vec v, double d)
{
	t_vec	ret;

	ret.x = v.x / d;
	ret.y = v.y / d;
	ret.z = v.z / d;
	return (ret);
}
