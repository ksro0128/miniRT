/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:42:19 by surkim            #+#    #+#             */
/*   Updated: 2023/03/14 18:02:43 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	if (dst <= src)
	{
		while (i < len)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			*((unsigned char *)dst + len - 1 - i) = \
			*((unsigned char *)src + len - 1 - i);
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char target[21] = "a shiny white sphere";
	char * p = target + 8;
	char * source = target + 2;
	printf( "Before memmove, target is \"%s\"\n", target );
	ft_memmove( p, source, 5 );
	printf( "After memmove, target becomes \"%s\"\n", target );
}*/