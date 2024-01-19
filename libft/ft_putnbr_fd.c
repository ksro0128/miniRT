/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:34:20 by surkim            #+#    #+#             */
/*   Updated: 2023/03/17 12:47:41 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_nbr(int n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	else
	{
		print_nbr(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		print_nbr(-n, fd);
	}
	else
	{
		print_nbr(n, fd);
	}
}
/*
int main (int c, char *v[])
{
	c++;
	ft_putnbr_fd(ft_atoi(v[1]), 1);
}*/