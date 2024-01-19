/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:09:34 by surkim            #+#    #+#             */
/*   Updated: 2023/03/14 17:24:21 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char *) malloc(count * size);
	if (!tmp)
		return (0);
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return ((void *)tmp);
}
