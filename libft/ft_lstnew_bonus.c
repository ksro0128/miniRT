/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:27:34 by surkim            #+#    #+#             */
/*   Updated: 2023/12/06 16:35:56 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, int type)
{
	t_list	*new;

	new = (t_list *)ft_malloc(sizeof (t_list));
	if (!new)
		return (0);
	new->content = content;
	new->type = type;
	new->next = NULL;
	return (new);
}
