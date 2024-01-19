/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:05:49 by surkim            #+#    #+#             */
/*   Updated: 2023/03/14 16:36:15 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	if (ft_strlen(haystack) == 0)
		return (0);
	if (len <= 0)
		return (0);
	while (haystack[i])
	{
		if (i + ft_strlen(needle) > len)
			return (0);
		else if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
		{
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
