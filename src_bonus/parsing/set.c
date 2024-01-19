/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:27:38 by surkim            #+#    #+#             */
/*   Updated: 2024/01/08 15:30:15 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	check_comma(char *str)
{
	int	i;
	int	comma_cnt;

	i = 0;
	comma_cnt = 0;
	if (str[0] == ',')
		print_error("파일요소가 올바르지 않습니다.");
	while (str[i])
	{
		if (str[i] == ',')
			comma_cnt++;
		i++;
	}
	if (comma_cnt != 2)
		print_error("파일요소가 올바르지 않습니다.");
}

void	check_three_elements(char **s)
{
	int	i;

	if (s == NULL)
		print_error("파일요소가 올바르지 않습니다.");
	i = 0;
	while (s[i])
		i++;
	if (i != 3)
		print_error("파일요소가 올바르지 않습니다.");
}

t_xyz	set_xyz(char *str)
{
	char	**tmp;
	t_xyz	ret;

	if (!str)
		print_error("파일요소가 올바르지 않습니다.");
	check_comma(str);
	tmp = ft_split_set(str, ",");
	check_three_elements(tmp);
	ret.x = ft_strtod(tmp[0]);
	ret.y = ft_strtod(tmp[1]);
	ret.z = ft_strtod(tmp[2]);
	ft_doublefree(tmp);
	return (ret);
}

t_rgb	set_rgb(char *str)
{
	t_rgb	ret;

	if (!str)
		print_error("파일요소가 올바르지 않습니다.");
	ret = set_xyz(str);
	if (ret.x < 0.0 || ret.x > 255.0 || \
	ret.y < 0.0 || ret.y > 255.0 || \
	ret.z < 0.0 || ret.z > 255.0)
		print_error("파일요소가 올바르지 않습니다.");
	ret.x /= 255.0;
	ret.y /= 255.0;
	ret.z /= 255.0;
	return (ret);
}

t_vec	set_vec(char *str)
{
	t_vec	ret;

	ret = set_xyz(str);
	if (ret.x == 0 && ret.y == 0 && ret.z == 0)
		print_error("파일요소가 올바르지 않습니다.");
	if (ret.x < -1.0 || ret.x > 1.0 || \
	ret.y < -1.0 || ret.y > 1.0 || \
	ret.z < -1.0 || ret.z > 1.0)
		print_error("파일요소가 올바르지 않습니다.");
	return (ret);
}
