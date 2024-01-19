/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:15:04 by surkim            #+#    #+#             */
/*   Updated: 2023/12/20 15:24:26 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	cal_discriminant(t_abc abc)
{
	double	ret;

	ret = pow(abc.b, 2.0) - 4.0 * abc.a * abc.c;
	return (ret);
}

double	cal_root(t_abc abc)
{
	double	x;
	double	y;

	x = (-abc.b + sqrt(cal_discriminant(abc))) / (2.0 * abc.a);
	y = (-abc.b - sqrt(cal_discriminant(abc))) / (2.0 * abc.a);
	if (x >= 0 && x < y)
		return (x);
	else if (y >= 0 && y < x)
		return (y);
	else if (x >= 0 && y < 0)
		return (x);
	else if (y >= 0 && x < 0)
		return (y);
	else
		return (-1);
}
