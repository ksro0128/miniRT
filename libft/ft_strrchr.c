/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:25:31 by surkim            #+#    #+#             */
/*   Updated: 2023/03/14 14:30:13 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	size;

	size = 0;
	while (s[size])
		size++;
	i = 0;
	while (s[i])
	{
		if (s[--size] == (char) c)
			return ((char *) &s[size]);
		i++;
	}
	if ((char) c == '\0')
		return ((char *) &s[i]);
	else
		return (0);
}
