/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_normalmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:31:19 by youngcki          #+#    #+#             */
/*   Updated: 2024/01/02 12:18:57 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	check_xmp_file(char *filename)
{
	int	i;
	int	fd;

	i = 0;
	while (filename[i])
		i++;
	if (i < 5)
		print_error("파일 이름이 잘못 되었습니다.");
	i -= 4;
	if (ft_strncmp(&filename[i], ".xpm", 4) != 0)
		print_error("파일 이름이 잘못 되었습니다.");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("파일을 열 수 없습니다.");
	close(fd);
}

void	parsing_normalmap(t_data *data, char **strstr)
{
	int	i;

	i = 0;
	while (strstr[i])
		i++;
	if (i != 3)
		print_error("파일 요소가 올바르지 않습니다.");
	check_xmp_file(strstr[1]);
	check_xmp_file(strstr[2]);
	data->texturemap.img = mlx_xpm_file_to_image(data->mlx, strstr[1], \
	&data->texturemap.width, &data->texturemap.height);
	if (data->texturemap.img == NULL)
		print_error("xpm 파일이 올바르지 않습니다.");
	data->texturemap.addr = mlx_get_data_addr(data->texturemap.img, \
	&data->texturemap.bits_per_pixel, &data->texturemap.line_length, \
	&data->texturemap.endian);
	data->normalmap.img = mlx_xpm_file_to_image(data->mlx, strstr[2], \
	&data->normalmap.width, &data->normalmap.height);
	if (data->normalmap.img == NULL)
		print_error("xpm 파일이 올바르지 않습니다.");
	data->normalmap.addr = mlx_get_data_addr(data->normalmap.img, \
	&data->normalmap.bits_per_pixel, &data->normalmap.line_length, \
	&data->normalmap.endian);
}
