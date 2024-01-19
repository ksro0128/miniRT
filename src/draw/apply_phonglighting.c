/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_phonglighting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:24:11 by surkim            #+#    #+#             */
/*   Updated: 2023/12/20 18:28:03 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	cal_ambient(t_amb amb, t_hit hit)
{
	return (vmulv(amb.rgb, hit.rgb));
}

t_rgb	cal_diffuse(t_light light, t_hit hit)
{
	double	k;
	t_rgb	ret;

	k = max(vdot(hit.n_vec, vunit(vminus(light.o, hit.hit_point))), 0);
	ret = vmuln(vmulv(hit.rgb, light.rgb), k);
	return (ret);
}

t_rgb	cal_specular(t_light light, t_cam cam, t_hit hit)
{
	t_vec	hit_to_light;
	t_vec	hit_to_cam;
	t_vec	reflec;
	t_rgb	ret;
	double	k;

	hit_to_light = vminus(light.o, hit.hit_point);
	hit_to_cam = vminus(cam.o, hit.hit_point);
	reflec = vminus(vmuln(hit.n_vec, 2.0 * vdot(hit_to_light, hit.n_vec)), \
	hit_to_light);
	k = pow(max(vdot(vunit(hit_to_cam), vunit(reflec)), 0.0), 10);
	ret = vmuln(vmulv(light.rgb, hit.rgb), k);
	return (ret);
}

t_rgb	apply_phonglighting(t_data *data, t_hit hit)
{
	t_rgb	ambient;
	t_rgb	diffuse;
	t_rgb	specular;
	t_rgb	ret;

	if (data->status % 2 == 1)
		ambient = cal_ambient(data->amb, hit);
	else
		ambient = rgb(0, 0, 0);
	if ((data->status >> 2) % 2 == 1)
	{
		diffuse = cal_diffuse(data->light, hit);
		specular = cal_specular(data->light, data->cam, hit);
	}
	else
	{
		diffuse = rgb(0, 0, 0);
		specular = rgb(0, 0, 0);
	}
	ret = vplus(ambient, diffuse);
	ret = vplus(ret, specular);
	ret = clamp_rgb(ret);
	return (ret);
}
