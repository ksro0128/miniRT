/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_hyperboloid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:43:24 by youngcki          #+#    #+#             */
/*   Updated: 2023/12/29 16:27:31 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_matrix	set_abc(char *str)
{
	t_matrix	ret;
	char		**tmp;

	if (!str)
		print_error("파일요소가 올바르지 않습니다.");
	check_comma(str);
	tmp = ft_split_set(str, ",");
	check_three_elements(tmp);
	ret.x.x = ft_strtod(tmp[0]);
	ret.x.y = 0;
	ret.x.z = 0;
	ret.y.x = 0;
	ret.y.y = ft_strtod(tmp[1]);
	ret.y.z = 0;
	ret.z.x = 0;
	ret.z.y = 0;
	ret.z.z = ft_strtod(tmp[2]);
	if (ret.z.z > 0)
		ret.z.z *= -1;
	ft_doublefree(tmp);
	return (ret);
}

void	parsing_hyperboloid(t_data *data, char **strstr)
{
	int				i;
	t_hyperboloid	*new;

	i = 0;
	while (strstr[i])
		i++;
	if (i != 5)
		print_error("파일요소가 올바르지 않습니다.");
	new = (t_hyperboloid *)ft_malloc(sizeof(t_hyperboloid));
	new->center = set_xyz(strstr[1]);
	new->v = set_vec(strstr[2]);
	new->abc = set_abc(strstr[3]);
	new->rgb = set_rgb(strstr[4]);
	new->nor = set_nor(new->v);
	ft_lstadd_back(&data->obj, ft_lstnew(new, HB));
}
