/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bumbmap_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:46:36 by youngcki          #+#    #+#             */
/*   Updated: 2023/12/29 15:52:24 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	get_sp_texture_rgb(double x, double y, t_img *img)
{
	t_rgb			ret;
	unsigned int	color;
	char			*dst;
	int				xx;
	int				yy;

	xx = x * img->width;
	yy = y * img->height;
	if (xx == img->width)
		xx--;
	if (yy == img->height)
		yy--;
	dst = img->addr + yy * img->line_length + xx * (img->bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	ret = rgb((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
	return (ret);
}

t_rgb	get_sp_normal_rgb(double x, double y, t_img *img)
{
	t_rgb			ret;
	unsigned int	color;
	char			*dst;
	int				xx;
	int				yy;

	xx = x * img->width;
	yy = y * img->height;
	if (xx == img->width)
		xx--;
	if (yy == img->height)
		yy--;
	dst = img->addr + yy * img->line_length + xx * (img->bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	ret = rgb((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
	ret.x = (ret.x / 255) * 2 - 1;
	ret.y = (ret.y / 255) * 2 - 1;
	ret.z = (ret.z / 255) * 2 - 1;
	return (ret);
}
