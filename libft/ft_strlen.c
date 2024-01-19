/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:58:11 by surkim            #+#    #+#             */
/*   Updated: 2023/10/31 10:40:25 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(int c, char *v[])
{
	(void) c;
	printf("my  : %lu\n",ft_strlen(v[1]));
	printf("lib : %lu\n",strlen(v[1]));
}*/
