/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:18:23 by surkim            #+#    #+#             */
/*   Updated: 2024/01/02 13:42:49 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->mlx_win = mlx_new_window(data->mlx, \
	data->win_width, data->win_height, "miniRT_bonus");
	if (!data->mlx_win)
		exit(1);
	data->image.img = mlx_new_image(data->mlx, \
	data->win_width, data->win_height);
	if (!data->image.img)
		exit(1);
	data->image.addr = mlx_get_data_addr(data->image.img, \
	&data->image.bits_per_pixel, &data->image.line_length, &data->image.endian);
	if (!data->image.addr)
		exit(1);
}

void	init_data(t_data *data)
{
	data->obj = NULL;
	data->normalmap.img = 0;
	data->win_width = 1280;
	data->win_height = 720;
	data->status = 0;
	data->checker = 0;
	data->light = 0;
}

void	init(t_data *data)
{
	init_data(data);
	init_mlx(data);
}
