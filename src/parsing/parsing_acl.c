/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_acl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:17:14 by surkim            #+#    #+#             */
/*   Updated: 2024/01/03 13:35:21 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	parsing_amb(t_data *data, char **strstr)
{
	static int	check;
	int			i;

	if (check != 0)
		print_error("파일요소가 올바르지 않습니다.");
	i = 0;
	while (strstr[i])
		i++;
	if (i != 3)
		print_error("파일요소가 올바르지 않습니다.");
	data->amb.ratio = ft_strtod(strstr[1]);
	if (data->amb.ratio < 0.0 || data->amb.ratio > 1.0)
		print_error("파일요소가 올바르지 않습니다.");
	data->amb.rgb = set_rgb(strstr[2]);
	data->amb.rgb = vmuln(data->amb.rgb, data->amb.ratio);
	check++;
	data->status += 1;
}

void	parsing_cam(t_data *data, char **strstr)
{
	static int	check;
	int			i;

	if (check != 0)
		print_error("파일요소가 올바르지 않습니다.");
	i = 0;
	while (strstr[i])
		i++;
	if (i != 4)
		print_error("파일요소가 올바르지 않습니다.");
	data->cam.o = set_xyz(strstr[1]);
	data->cam.v = vunit(set_vec(strstr[2]));
	data->cam.degrees = ft_strtod(strstr[3]);
	check++;
	data->status += 2;
}

void	parsing_light(t_data *data, char **strstr)
{
	static int	check;
	int			i;

	if (check != 0)
		print_error("파일요소가 올바르지 않습니다.");
	i = 0;
	while (strstr[i])
		i++;
	if (i != 4 && i != 3)
		print_error("파일요소가 올바르지 않습니다.");
	data->light.o = set_xyz(strstr[1]);
	data->light.ratio = ft_strtod(strstr[2]);
	if (strstr[3] == NULL)
		data->light.rgb = rgb(1.0, 1.0, 1.0);
	else
		data->light.rgb = set_rgb(strstr[3]);
	data->light.rgb = vmuln(data->light.rgb, data->light.ratio);
	check++;
	data->status += 4;
}
