/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:23:07 by surkim            #+#    #+#             */
/*   Updated: 2023/03/16 17:56:27 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(char const *s, char c, int flag)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (flag == 0 && s[i] != c)
		{
			count++;
			flag = 1;
		}
		else if (flag == 1 && s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

static char	*ft_strdup_v2(char const *s1, char c)
{
	int		i;
	size_t	size;
	char	*tmp;

	i = 0;
	size = 0;
	while (s1[size])
	{
		if (s1[size] == c)
			break ;
		size++;
	}
	tmp = (char *) malloc(size + 1);
	if (!tmp)
		return (0);
	while (i < (int) size)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static void	alloc_memory(char **tmp, char const *s, char c, int *flag)
{
	int	i;
	int	idx;

	i = 0;
	idx = 0;
	while (s[i])
	{
		if (*flag == 0 && s[i] != c)
		{
			tmp[idx] = ft_strdup_v2(&s[i], c);
			if (!tmp[idx])
			{
				*flag = -idx - 1;
				return ;
			}
			idx++;
			*flag = 1;
		}
		else if (*flag == 1 && s[i] == c)
			*flag = 0;
		i++;
	}
}

static void	all_free(char **tmp, int flag)
{
	int	i;

	i = 0;
	flag = -flag - 1;
	while (i <= flag)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	int		flag;

	flag = 0;
	tmp = (char **)malloc(sizeof(char *) * (get_size(s, c, flag) + 1));
	if (!tmp)
		return (0);
	alloc_memory(tmp, s, c, &flag);
	tmp[get_size(s, c, 0)] = NULL;
	if (flag < 0)
	{
		all_free(tmp, flag);
		return (0);
	}
	return (tmp);
}

// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// 	argc++;
// 	argv[0][0]++;
// 	// char **a = ft_split(argv[1], argv[2][0]);
// 	// //printf ("%d\n", get_size(argv[1],argv[2][0],0));
// 	// int i = 0;
// 	// while (a[i] != NULL)
// 	// {
// 	// 	printf("%s\n", a[i]);
// 	// 	i++;
// 	// }
// 	char a[100] = "\0aaaa\0bbb";
// 	char b = '\0';
// 	char **w = ft_split(a, b);
// 	for (int i = 0; i< 3 ; i++)
// 	{
// 		printf("%s\n", w[i]);
// 	}
// }