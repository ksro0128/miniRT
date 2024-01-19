/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:44:33 by surkim            #+#    #+#             */
/*   Updated: 2023/03/13 13:56:06 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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
    printf("my  :%d\n", ft_isdigit(v[1][0]));
	printf("lib :%d\n", isdigit(v[1][0]));
}*/