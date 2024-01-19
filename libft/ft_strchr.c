/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:53:17 by surkim            #+#    #+#             */
/*   Updated: 2023/12/06 17:00:48 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if ((char) c == '\0')
		return ((char *) &s[i]);
	else
		return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(int argc, char *argv[])
// {
// 	argc++;
// 	printf("%s", ft_strchr_gnl(argv[1],argv[2][0]));
// }