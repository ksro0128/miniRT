/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:51:29 by surkim            #+#    #+#             */
/*   Updated: 2023/12/25 20:07:25 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_hit	check_hit(t_list *obj, t_ray ray, int flag)
{
	t_hit	ret;
	t_hit	tmp;
	t_list	*cur;

	ft_memchr(&ret, 0, sizeof(t_hit));
	ret.t_min = INFINITY;
	cur = obj;
	ft_memset(&tmp, 0, sizeof(t_hit));
	while (cur)
	{
		if (cur->type == SP)
			tmp = hit_sphere(cur->content, ray, flag);
		if (cur->type == PL)
			tmp = hit_plane(cur->content, ray, flag);
		if (cur->type == CY)
			tmp = hit_cylinder(cur->content, ray, flag);
		if (cur->type == HB)
			tmp = hit_hyperboloid(cur->content, ray, flag);
		if (tmp.t_min != INFINITY && tmp.t_min < ret.t_min)
			ret = tmp;
		cur = cur->next;
	}
	return (ret);
}
