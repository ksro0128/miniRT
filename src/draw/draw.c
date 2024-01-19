/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:59:42 by surkim            #+#    #+#             */
/*   Updated: 2023/12/20 19:20:19 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_ray	make_ray(t_data *data, int i, int j)
{
	t_vec	dir;

	dir = vplus(data->veiwport.upper_left, vplus(vmuln(data->veiwport.u, i), \
	vmuln(data->veiwport.v, j)));
	return (ray(data->cam.o, dir));
}

t_rgb	render_pixel_color(t_data *data, t_ray _ray)
{
	t_hit	hit;

	hit = check_hit(data->obj, _ray);
	if (hit.t_min == INFINITY)
		return (rgb(0, 0, 0));
	if (isshadow(data, hit))
		return (vmulv(data->amb.rgb, hit.rgb));
	return (apply_phonglighting(data, hit));
}

void	draw(t_data *data)
{
	int		i;
	int		j;
	t_ray	ray;
	t_rgb	rgb;

	j = 0;
	while (j < data->win_height)
	{
		i = 0;
		while (i < data->win_width)
		{
			ray = make_ray(data, i, j);
			rgb = render_pixel_color(data, ray);
			my_mlx_pixel_put(&data->image, i, j, rgb);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.img, 0, 0);
}
