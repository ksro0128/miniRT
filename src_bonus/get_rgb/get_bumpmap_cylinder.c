/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bumpmap_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:46:36 by youngcki          #+#    #+#             */
/*   Updated: 2024/01/08 14:48:54 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	get_cy_texture_rgb(double x, double y, t_img *img)
{
	t_rgb			ret;
	char			*dst;
	unsigned int	color;
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
	return (vdivn(ret, 255));
}

t_rgb	get_cy_normal_rgb(double x, double y, t_img *img)
{
	t_rgb			ret;
	char			*dst;
	unsigned int	color;
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
	ret = vplus(vmuln(vdivn(ret, 255), 2), vec(-1, -1, -1));
	return (ret);
}
