/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:04:37 by surkim            #+#    #+#             */
/*   Updated: 2023/12/20 14:14:05 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_doublefree(char **obj)
{
	int	i;

	i = 0;
	while (obj[i])
	{
		free(obj[i]);
		i++;
	}
	free(obj);
}

void	print_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_rgb	clamp_rgb(t_rgb rgb)
{
	t_rgb	ret;

	ret = rgb;
	if (ret.x > 1)
		ret.x = 0.999;
	if (ret.y > 1)
		ret.y = 0.999;
	if (ret.z > 1)
		ret.z = 0.999;
	return (ret);
}
