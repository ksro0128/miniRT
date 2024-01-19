/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bumpmap_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:46:36 by youngcki          #+#    #+#             */
/*   Updated: 2023/12/29 19:26:05 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	get_pl_normal_rgb(double x, double y, t_img *img)
{
	t_rgb			ret;
	unsigned int	color;
	char			*dst;
	int				xx;
	int				yy;

	yy = y * 70;
	xx = x * 70;
	if (abs(xx) > img->width)
		xx = xx % img->width;
	if (abs(yy) > img->height)
		yy = yy % img->height;
	if (xx < 0)
		xx = (img->width + xx) % img->width;
	if (yy < 0)
		yy = (img->height + yy) % img->height;
	if (xx == img->width)
		xx--;
	yy = img->height - yy;
	if (yy == img->height)
		yy--;
	dst = img->addr + yy * img->line_length + xx * (img->bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	ret = rgb((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
	return (vminus(vmuln(vdivn(ret, 255), 2), vec(1, 1, 1)));
}

t_rgb	get_pl_texture_rgb(double x, double y, t_img *img)
{
	t_rgb			ret;
	unsigned int	color;
	char			*dst;
	int				xx;
	int				yy;

	yy = y * 70;
	xx = x * 70;
	if (abs(xx) > img->width)
		xx = xx % img->width;
	if (abs(yy) > img->height)
		yy = yy % img->height;
	if (xx < 0)
		xx = (img->width + xx) % img->width;
	if (yy < 0)
		yy = (img->height + yy) % img->height;
	if (xx == img->width)
		xx--;
	yy = img->height - yy;
	if (yy == img->height)
		yy--;
	dst = img->addr + yy * img->line_length + xx * (img->bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	ret = rgb((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
	return (vdivn(ret, 255));
}
