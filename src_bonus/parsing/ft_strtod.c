/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:07:21 by surkim            #+#    #+#             */
/*   Updated: 2023/12/20 10:45:49 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	get_integer(char *str, int end)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == end)
		exit(1);
	while (i < end)
	{
		if (str[i] < '0' || str[i] > '9')
			exit(1);
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	if (str[0] == '-')
		ret = -ret;
	return (ret);
}

double	get_fractional(char *str, int i)
{
	double	ret;
	double	x;

	if (str[i] == '\0')
		return (0);
	i++;
	ret = 0;
	x = 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			exit(1);
		ret = ret * 10 + (double)(str[i] - '0');
		x *= 10;
		i++;
	}
	ret = ret / x;
	return (ret);
}

double	ft_strtod(char *str)
{
	int		i;
	int		integer;
	double	fractional;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	integer = get_integer(str, i);
	fractional = get_fractional(str, i);
	if (str[0] == '-')
		fractional = -fractional;
	return (integer + fractional);
}
