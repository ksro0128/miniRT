/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bumpmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:34:21 by youngcki          #+#    #+#             */
/*   Updated: 2023/12/29 19:22:51 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	set_bumpmap_sppl(t_list *cur, t_data *data)
{
	if (cur->type == SP)
	{
		((t_sphere *)(cur->content))->img = &data->texturemap;
		((t_sphere *)(cur->content))->himg = &data->normalmap;
	}
	else
	{
		((t_plane *)(cur->content))->img = &data->texturemap;
		((t_plane *)(cur->content))->himg = &data->normalmap;
	}
}

void	set_bumpmap_cyhb(t_list *cur, t_data *data)
{
	if (cur->type == CY)
	{
		((t_cylinder *)(cur->content))->img = &data->texturemap;
		((t_cylinder *)(cur->content))->himg = &data->normalmap;
	}
	else
	{
		((t_hyperboloid *)(cur->content))->img = &data->texturemap;
		((t_hyperboloid *)(cur->content))->himg = &data->normalmap;
	}
}

void	insert_normalmap(t_data *data)
{
	t_list			*cur;

	cur = data->obj;
	while (cur)
	{
		if (cur->type == SP || cur->type == PL)
			set_bumpmap_sppl(cur, data);
		else if (cur->type == CY || cur->type == HB)
			set_bumpmap_cyhb(cur, data);
		cur = cur->next;
	}
}
