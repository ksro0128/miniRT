/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:51:55 by surkim            #+#    #+#             */
/*   Updated: 2023/03/13 14:57:39 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(int c, char *v[])
{
	c++;
	printf("my  :%d\n", ft_isprint(v[1][0]));
	printf("lib :%d\n", isprint(v[1][0]));

	char a = 2;
	printf("my  :%d\n", ft_isprint(a));
	printf("lib :%d\n", isprint(a));
}*/