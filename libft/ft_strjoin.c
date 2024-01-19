/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:29:22 by surkim            #+#    #+#             */
/*   Updated: 2023/12/06 17:01:00 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*tmp;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tmp = (char *) malloc(sizeof (char) * (s1_len + s2_len + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (i < s1_len)
	{
		tmp[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		tmp[i] = s2[i - s1_len];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
