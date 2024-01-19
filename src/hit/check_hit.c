/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:51:29 by surkim            #+#    #+#             */
/*   Updated: 2023/12/20 20:04:25 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_hit	check_hit(t_list *obj, t_ray ray)
{
	t_hit	ret;
	t_hit	tmp;
	t_list	*cur;

	ret.t_min = INFINITY;
	cur = obj;
	while (cur)
	{
		if (cur->type == SP)
			tmp = hit_sphere(cur->content, ray);
		if (cur->type == PL)
			tmp = hit_plane(cur->content, ray);
		if (cur->type == CY)
			tmp = hit_cylinder(cur->content, ray);
		if (tmp.t_min != INFINITY && tmp.t_min < ret.t_min)
			ret = tmp;
		cur = cur->next;
	}
	return (ret);
}
