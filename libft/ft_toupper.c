/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:46:10 by surkim            #+#    #+#             */
/*   Updated: 2023/03/14 12:51:35 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(int argc, char *argv[])
{
	argc++;
	printf("my  : %c\n", ft_toupper(argv[1][0]));
	printf("lib : %c\n", toupper(argv[1][0]));
}*/