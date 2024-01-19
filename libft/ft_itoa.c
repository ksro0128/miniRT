/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:30 by surkim            #+#    #+#             */
/*   Updated: 2023/03/15 18:30:09 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_strrev(char *ans, int size)
{
	int		i;
	char	c;

	i = 0;
	while (i <= size / 2)
	{
		c = ans[i];
		ans[i] = ans[size - i];
		ans[size - i] = c;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*ans;
	int		i;
	int		tmp;

	tmp = n;
	ans = (char *)malloc(sizeof (char) * (get_size(n) + 1));
	if (!ans)
		return (0);
	i = 1;
	ans[0] = '\0';
	if (tmp == 0)
		ans[get_size(n)] = '0';
	while (i <= get_size(n))
	{
		if (n < 0)
			ans[i] = -(tmp % 10) + '0';
		else
			ans[i] = tmp % 10 + '0';
		tmp = tmp / 10;
		i++;
	}
	if (n < 0)
		ans[get_size(n)] = '-';
	ft_strrev(ans, get_size(n));
	return (ans);
}
/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	argc++;
	printf("%s\n", ft_itoa(ft_atoi(argv[1])));
	printf("%d", get_size(ft_atoi(argv[1])));
	//printf("%d \n", -1/10);
}*/