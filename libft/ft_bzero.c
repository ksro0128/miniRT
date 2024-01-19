/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:11:59 by surkim            #+#    #+#             */
/*   Updated: 2023/03/13 16:27:17 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <stdio.h>
#include <string.h>

int main (int c, char *v[])
{
	c++;
	char *a = v[1];
	ft_bzero(a, 5);
	//char *b = (char *)memset(v[1],'b',10);
	int i;
	i = 0;
	while (i < 10)
	{
		printf("%c", a[i]);
		i++;
	}
	printf("%s\n", a);
	//printf("%s\n", b);
}*/