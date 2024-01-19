/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_veiwport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:11:57 by surkim            #+#    #+#             */
/*   Updated: 2024/01/03 13:25:12 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_veiwport	set_veiwport(t_data *data)
{
	t_veiwport	ret;

	ret.width = 5;
	ret.height = ret.width * 9 / 16;
	ret.focal_length = (ret.width / 2.0) / tan(data->cam.degrees / 360 * M_PI);
	if (data->cam.v.x == 0 && data->cam.v.y == 0)
		ret.u = vmuln(vunit(vec(1.0, 0.0, 0.0)), ret.width / data->win_width);
	else
		ret.u = vmuln(vunit(vcross(data->cam.v, vec(0, 0, 1))), \
		ret.width / data->win_width);
	ret.v = vmuln(vunit(vcross(data->cam.v, ret.u)), \
	ret.height / data->win_height);
	ret.upper_left = vplus(vplus(vmuln(ret.u, -data->win_width / 2.0), \
	vmuln(ret.v, -data->win_height / 2.0)), \
	vmuln(data->cam.v, ret.focal_length));
	return (ret);
}
