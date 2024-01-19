/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_complementary_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:25:21 by youngcki          #+#    #+#             */
/*   Updated: 2023/12/29 19:25:22 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	get_complementary_color(t_rgb color)
{
	t_rgb	ret;

	ret.x = 1 - color.x;
	ret.y = 1 - color.y;
	ret.z = 1 - color.z;
	return (ret);
}
