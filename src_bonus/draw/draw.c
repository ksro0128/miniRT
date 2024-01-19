/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:59:42 by surkim            #+#    #+#             */
/*   Updated: 2024/01/08 15:07:38 by surkim           ###   ########.fr       */
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

	hit = check_hit(data->obj, _ray, data->checker);
	if (hit.t_min == INFINITY)
		return (rgb(0, 0, 0));
	if (isshadow(data, hit))
		return (vmulv(data->amb.rgb, hit.rgb));
	return (apply_phonglighting(data, hit));
}

void	*draw2(void *tmp)
{
	t_opt	*opt;
	int		x;
	t_ray	ray;
	t_rgb	rgb;

	opt = tmp;
	x = 0;
	while (x < opt->data->win_width)
	{
		ray = make_ray(opt->data, x, opt->id);
		rgb = render_pixel_color(opt->data, ray);
		my_mlx_pixel_put(&opt->data->image, x, opt->id, rgb);
		x++;
	}
	return (0);
}

void	draw(t_data *data)
{
	t_opt		opt[720];
	pthread_t	thread[720];
	int			i;

	i = 0;
	while (i < data->win_height)
	{
		opt[i].id = i;
		opt[i].data = data;
		pthread_create(&thread[i], 0, draw2, &opt[i]);
		i++;
	}
	i = 0;
	while (i < data->win_height)
	{
		pthread_join(thread[i], 0);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.img, 0, 0);
}
