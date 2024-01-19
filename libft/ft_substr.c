/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:35:41 by surkim            #+#    #+#             */
/*   Updated: 2023/03/15 20:01:29 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(char const *s, unsigned int start, size_t len)
{
	size_t	s_size;

	s_size = ft_strlen(s);
	if (s_size >= start + len)
		return (len + 1);
	else
		return (s_size - start + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (ft_strlen(s) <= start)
	{
		tmp = (char *)malloc(1);
		if (!tmp)
			return (0);
		tmp[0] = '\0';
		return (tmp);
	}
	tmp = (char *)malloc(get_len(s, start, len));
	if (!tmp)
		return (0);
	while (i < len && s[start])
	{
		tmp[i] = s[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	return (tmp);
}
