/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:11:08 by surkim            #+#    #+#             */
/*   Updated: 2023/03/14 12:45:41 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ini_dstlen;

	ini_dstlen = ft_strlen(dst);
	i = 0;
	j = 0;
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	else
	{
		while (dst[i])
			i++;
		while (i < dstsize - 1 && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (ft_strlen(src) + ini_dstlen);
	}
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char a[100] = "ab";
	char b[100] = "zzzzz";
	char c[100] = "ab";
	char d[100] = "zzzzz";
	printf ("my  : %lu\n", ft_strlcat(a, b, 1));
	printf ("my  : %s\n", a);
	printf ("lib : %lu\n", strlcat(c, d, 1));
	printf ("lib : %s\n", c);
}*/