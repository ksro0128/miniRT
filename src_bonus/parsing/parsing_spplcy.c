/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_spplcy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:45:12 by surkim            #+#    #+#             */
/*   Updated: 2024/01/03 13:52:21 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	parsing_sphere(t_data *data, char **strstr)
{
	int			i;
	t_sphere	*new;

	i = 0;
	while (strstr[i])
		i++;
	if (i != 4)
		print_error("파일요소가 올바르지 않습니다.");
	new = (t_sphere *)ft_malloc(sizeof(t_sphere));
	new->o = set_xyz(strstr[1]);
	new->d = ft_strtod(strstr[2]);
	new->rgb = set_rgb(strstr[3]);
	new->nor = set_nor(vec(1, 0, 0));
	ft_lstadd_back(&data->obj, ft_lstnew(new, SP));
}

void	parsing_plane(t_data *data, char **strstr)
{
	int		i;
	t_plane	*new;

	i = 0;
	while (strstr[i])
		i++;
	if (i != 4)
		print_error("파일요소가 올바르지 않습니다.");
	new = (t_plane *)ft_malloc(sizeof(t_plane));
	new->o = set_xyz(strstr[1]);
	new->v = vunit(set_vec(strstr[2]));
	new->rgb = set_rgb(strstr[3]);
	new->nor = set_nor(new->v);
	ft_lstadd_back(&data->obj, ft_lstnew(new, PL));
}

void	parsing_cylinder(t_data *data, char **strstr)
{
	int			i;
	t_cylinder	*new;

	i = 0;
	while (strstr[i])
		i++;
	if (i != 6)
		print_error("파일요소가 올바르지 않습니다.");
	new = (t_cylinder *)ft_malloc(sizeof(t_cylinder));
	new->o = set_xyz(strstr[1]);
	new->v = vunit(set_vec(strstr[2]));
	new->d = ft_strtod(strstr[3]);
	new->h = ft_strtod(strstr[4]);
	new->rgb = set_rgb(strstr[5]);
	new->nor = set_nor(new->v);
	ft_lstadd_back(&data->obj, ft_lstnew(new, CY));
}
