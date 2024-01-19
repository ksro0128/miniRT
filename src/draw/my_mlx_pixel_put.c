/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:48:23 by surkim            #+#    #+#             */
/*   Updated: 2023/12/29 19:26:40 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, t_rgb rgb)
{
	char	*dst;
	int		color;
	int		r;
	int		g;
	int		b;

	r = (rgb.x) * 255.0;
	if (r > 255)
		r = 255;
	g = (rgb.y) * 255.0;
	if (g > 255)
		g = 255;
	b = (rgb.z) * 255.0;
	if (b > 255)
		b = 255;
	color = (r * 65536) + (g * 256) + b;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
