/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:54:41 by surkim            #+#    #+#             */
/*   Updated: 2023/03/14 16:05:08 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*r1;
	unsigned char	*r2;
	size_t			i;

	r1 = (unsigned char *)s1;
	r2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (r1[i] != r2[i])
			return ((int) r1[i] - r2[i]);
		i++;
	}
	return ((int) r1[i] - r2[i]);
}
