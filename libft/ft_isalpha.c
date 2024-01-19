/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:16:45 by surkim            #+#    #+#             */
/*   Updated: 2023/03/13 14:01:24 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    argc++;
    printf("my  : %d\n", ft_isalpha(argv[1][0]));
    printf("lib : %d\n", isalpha(argv[1][0]));
}*/
