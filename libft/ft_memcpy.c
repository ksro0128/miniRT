/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:27:45 by surkim            #+#    #+#             */
/*   Updated: 2023/03/14 14:07:43 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main(int c, char *v[])
{
	c++;
	char a[100] = "0123456789";
	char b[100] = "0123456789";

	*a = *(char *)ft_memcpy(a, v[1], 5);
	*b = *(char *)memcpy(b, v[1], 5);
	printf("my  : %s\n", a);
	printf("lib : %s\n", b);
}*/