/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:45:08 by surkim            #+#    #+#             */
/*   Updated: 2023/03/15 20:08:54 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_start_index(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (is_in_set(s1[i], set) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	get_last_index(char const *s1, char const *set)
{
	int	i;
	int	s1_size;

	i = 1;
	s1_size = ft_strlen(s1);
	while (s1_size - i >= 0)
	{
		if (is_in_set(s1[s1_size - i], set) == 0)
			break ;
		i++;
	}
	if (s1_size - i < 0)
		return (s1_size - 1);
	return (s1_size - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	int		start_idx;
	int		last_idx;
	int		idx;

	start_idx = get_start_index(s1, set);
	last_idx = get_last_index(s1, set);
	tmp = (char *)malloc(sizeof (char) * (last_idx - start_idx + 2));
	if (!tmp)
		return (0);
	idx = 0;
	while (start_idx <= last_idx)
	{
		tmp[idx] = s1[start_idx];
		idx++;
		start_idx++;
	}
	tmp[idx] = '\0';
	return (tmp);
}
/*
#include <stdio.h>

int main (int argc, char *argv[])
{
	argc++;
	printf("%s\n",ft_strtrim(argv[1],argv[2]));
}*/