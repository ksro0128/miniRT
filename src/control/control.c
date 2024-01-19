/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:26:49 by youngcki          #+#    #+#             */
/*   Updated: 2023/12/29 19:26:50 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	press(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	xbutton(void)
{
	exit(0);
	return (0);
}

void	control(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, xbutton, NULL);
	mlx_hook(data->mlx_win, 2, 1L << 0, press, &data);
	mlx_loop(data->mlx);
}
