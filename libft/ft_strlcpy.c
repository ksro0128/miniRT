/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:57:52 by surkim            #+#    #+#             */
/*   Updated: 2023/03/14 13:22:24 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	src_size = 0;
	while (src[src_size])
		src_size++;
	if (dstsize == 0)
		return (src_size);
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char a[100] = "abcdefg";
	char b[100] = "abcdefg";
	char c[100] = "1234567890";
	char d[100] = "1234567890";
	printf("my  : %d\n", (int)ft_strlcpy(a, c, 12));
	printf("my  : %s\n", a);
	printf("lib : %d\n", (int)strlcpy(b, d, 12));
	printf("lib : %s\n", b);
}*/