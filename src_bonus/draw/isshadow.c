/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isshadow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:07:06 by surkim            #+#    #+#             */
/*   Updated: 2023/12/27 19:05:07 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	isshadow(t_data *data, t_hit hit)
{
	t_vec	obj_to_light;
	t_hit	hit_shadow;
	t_light	*cur;
	double	min;

	cur = data->light;
	while (cur)
	{
		obj_to_light = vminus(cur->o, hit.hit_point);
		min = vlength(obj_to_light);
		hit_shadow = check_hit(data->obj, \
		ray(hit.hit_point, vunit(vminus(cur->o, hit.hit_point))), 0);
		if (hit_shadow.t_min > min)
			return (0);
		cur = cur->next;
	}
	return (1);
}
