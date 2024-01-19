/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:26:15 by youngcki          #+#    #+#             */
/*   Updated: 2024/01/03 12:24:09 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	checker_on(t_data *data)
{
	if (data->checker != 1)
	{
		data->checker = 1;
		draw(data);
	}
}

void	mode_off(t_data *data)
{
	if (data->checker != 0)
	{
		data->checker = 0;
		draw(data);
	}
}

void	normalmap_onoff(t_data *data)
{
	if (data->normalmap.img != NULL)
	{
		if (data->checker == 2)
			data->checker = 0;
		else
			data->checker = 2;
		draw(data);
	}
}

int	press(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 18)
		mode_off(data);
	else if (keycode == 19)
		checker_on(data);
	else if (keycode == 20)
		normalmap_onoff(data);
	return (0);
}

int	xbutton(void)
{
	exit(0);
	return (0);
}
