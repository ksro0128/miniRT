/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isshadow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:07:06 by surkim            #+#    #+#             */
/*   Updated: 2023/12/20 18:23:21 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	isshadow(t_data *data, t_hit hit)
{
	t_vec	obj_to_light;
	t_hit	hit_shadow;
	double	min;

	obj_to_light = vminus(data->light.o, hit.hit_point);
	min = vlength(obj_to_light);
	hit_shadow = check_hit(data->obj, \
	ray(hit.hit_point, vminus(data->light.o, hit.hit_point)));
	if (hit_shadow.t_min < min)
		return (1);
	else
		return (0);
}
