/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:39:20 by youngcki          #+#    #+#             */
/*   Updated: 2023/12/28 20:39:26 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_matrix	cal_matrix_matrix(t_matrix a, t_matrix b)
{
	t_matrix	ret;

	ret.x.x = a.x.x * b.x.x + a.x.y * b.y.x + a.x.z * b.z.x;
	ret.x.y = a.x.x * b.x.y + a.x.y * b.y.y + a.x.z * b.z.y;
	ret.x.z = a.x.x * b.x.z + a.x.y * b.y.z + a.x.z * b.z.z;
	ret.y.x = a.y.x * b.x.x + a.y.y * b.y.x + a.y.z * b.z.x;
	ret.y.y = a.y.x * b.x.y + a.y.y * b.y.y + a.y.z * b.z.y;
	ret.y.z = a.y.x * b.x.z + a.y.y * b.y.z + a.y.z * b.z.z;
	ret.z.x = a.z.x * b.x.x + a.z.y * b.y.x + a.z.z * b.z.x;
	ret.z.y = a.z.x * b.x.y + a.z.y * b.y.y + a.z.z * b.z.y;
	ret.z.z = a.z.x * b.x.z + a.z.y * b.y.z + a.z.z * b.z.z;
	return (ret);
}

t_vec	cal_matrix_vec(t_matrix a, t_vec b)
{
	t_vec	ret;

	ret.x = a.x.x * b.x + a.x.y * b.y + a.x.z * b.z;
	ret.y = a.y.x * b.x + a.y.y * b.y + a.y.z * b.z;
	ret.z = a.z.x * b.x + a.z.y * b.y + a.z.z * b.z;
	return (ret);
}

t_matrix	transpose_matrix(t_matrix a)
{
	t_matrix	ret;

	ret.x.x = a.x.x;
	ret.x.y = a.y.x;
	ret.x.z = a.z.x;
	ret.y.x = a.x.y;
	ret.y.y = a.y.y;
	ret.y.z = a.z.y;
	ret.z.x = a.x.z;
	ret.z.y = a.y.z;
	ret.z.z = a.z.z;
	return (ret);
}
