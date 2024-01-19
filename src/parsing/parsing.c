/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:54:42 by surkim            #+#    #+#             */
/*   Updated: 2024/01/08 14:07:15 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	open_file(char *filename)
{
	int	i;
	int	fd;

	i = 0;
	while (filename[i])
		i++;
	if (i < 4)
		print_error("파일 이름이 잘못 되었습니다.");
	i -= 3;
	if (ft_strncmp(&filename[i], ".rt", 3) != 0)
		print_error("파일 이름이 잘못 되었습니다.");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("파일을 열 수 없습니다.");
	return (fd);
}

void	ft_switch(t_data *data, char **strstr)
{
	if (ft_strncmp(strstr[0], "A", 2) == 0)
		parsing_amb(data, strstr);
	else if (ft_strncmp(strstr[0], "C", 2) == 0)
		parsing_cam(data, strstr);
	else if (ft_strncmp(strstr[0], "L", 2) == 0)
		parsing_light(data, strstr);
	else if (ft_strncmp(strstr[0], "sp", 3) == 0)
		parsing_sphere(data, strstr);
	else if (ft_strncmp(strstr[0], "pl", 3) == 0)
		parsing_plane(data, strstr);
	else if (ft_strncmp(strstr[0], "cy", 3) == 0)
		parsing_cylinder(data, strstr);
	else
		print_error("파일요소가 올바르지 않습니다.");
}

void	parsing_obj(t_data *data, int fd)
{
	char	*str;
	char	**strstr;

	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		strstr = ft_split_set(str, " \t\v\f\r\n");
		if (strstr[0] == NULL)
		{
			free(str);
			free(strstr);
			continue ;
		}
		ft_switch(data, strstr);
		free(str);
		ft_doublefree(strstr);
	}
}

void	check(t_data *data)
{
	if (data->status == 0)
		print_error("파일요소가 올바르지 않습니다.");
	if ((data->status >> 1) % 2 == 0)
		print_error("파일요소가 올바르지 않습니다.");
	if ((data->status % 2 == 0) && ((data->status >> 2) % 2) == 0)
		print_error("파일요소가 올바르지 않습니다.");
}

void	parsing(t_data *data, char *filename)
{
	int		fd;

	fd = open_file(filename);
	parsing_obj(data, fd);
	data->veiwport = set_veiwport(data);
	check(data);
	close(fd);
}
