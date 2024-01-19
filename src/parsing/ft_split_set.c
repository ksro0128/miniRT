/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:54:35 by  yeonwkan         #+#    #+#             */
/*   Updated: 2023/12/20 10:45:46 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset && charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_sentence(char *str, char *charset)
{
	int	i;
	int	flag;
	int	cnt;

	i = 0;
	flag = 0;
	cnt = 0;
	while (str && str[i])
	{
		if (flag == 0 && !is_charset(str[i], charset))
		{
			flag = 1;
			cnt++;
		}
		else if (flag == 1 && is_charset(str[i], charset))
		{
			flag = 0;
			str[i] = 0;
		}
		if (is_charset(str[i], charset))
			str[i] = 0;
		i++;
	}
	return (cnt);
}

char	**ft_split_set(char *str, char *charset)
{
	int		sentence;
	int		i;
	int		j;
	int		len;
	char	**new;

	len = ft_strlen(str);
	sentence = count_sentence(str, charset);
	new = ft_malloc(sizeof(char *) * (sentence + 1));
	new[sentence] = 0;
	i = 0;
	j = 0;
	while (i < len)
	{
		if ((i != 0 && str[i - 1] == 0 && str[i]) || (i == 0 && str[i]))
		{
			new[j] = ft_strdup(&str[i]);
			j++;
		}
		i++;
	}
	return (new);
}
