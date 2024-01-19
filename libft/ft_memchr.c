/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:41:38 by surkim            #+#    #+#             */
/*   Updated: 2023/03/14 15:55:57 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	a = (unsigned char *)s;
	i = 0;
	if (n <= 0)
		return (0);
	while (i < n - 1)
	{
		if ((unsigned char) a[i] == (unsigned char) c)
			return ((void *) &a[i]);
		i++;
	}
	if ((unsigned char) c == (unsigned char) a[i])
		return ((void *) &a[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
	argc++;
	printf("%s",ft_memchr(argv[1],argv[2][0],atoi(argv[3])));
}*/