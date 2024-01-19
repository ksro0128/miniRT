/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:57:16 by surkim            #+#    #+#             */
/*   Updated: 2023/03/13 14:35:59 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c))
		return (1);
	else if (ft_isdigit(c))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(int c, char *v[])
{
	c++;
	printf("my  :%d\n", ft_isalnum(v[1][0]));
	printf("lib :%d\n", isalnum(v[1][0]));
	return (0);
}*/