/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bumbmap_hyperboloid.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:46:36 by youngcki          #+#    #+#             */
/*   Updated: 2023/12/29 15:55:41 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	get_hb_texture_rgb(double x, double y, t_img *img)
{
	char			*dst;
	unsigned int	color;
	t_rgb			ret;
	int				xx;
	int				yy;

	xx = x * img->width;
	y = fmod(y, 1);
	yy = y * img->height;
	if (yy == img->height)
		yy--;
	dst = img->addr + yy * img->line_length + xx * (img->bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	ret = rgb((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
	return (vdivn(ret, 255));
}

t_rgb	get_hb_normal_rgb(double x, double y, t_img *img)
{
	char			*dst;
	unsigned int	color;
	t_rgb			ret;
	int				xx;
	int				yy;

	xx = x * img->width * 4;
	xx = xx % img->width;
	y = fmod(y, 10) / 10;
	yy = y * img->height;
	if (yy == img->height)
		yy--;
	dst = img->addr + yy * img->line_length + xx * (img->bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	ret = rgb((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
	ret = vplus(vmuln(ret, 2), vec(-1, -1, -1));
	return (vunit(ret));
}
