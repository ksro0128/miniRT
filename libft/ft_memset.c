/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:29:05 by surkim            #+#    #+#             */
/*   Updated: 2023/03/13 16:11:23 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;

	a = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		a[i] = c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>
#include <string.h>

int main (int c, char *v[])
{
	c++;
	v[0][0]++;
	char *a = (char *)ft_memset(v[1],'a',10);
	//char *b = (char *)memset(v[1],'b',10);
	printf("%s\n", a);
	//printf("%s\n", b);
}*/