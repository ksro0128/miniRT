/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:26:48 by surkim            #+#    #+#             */
/*   Updated: 2023/03/16 22:01:44 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	if (!lst)
		return (0);
	while (lst)
	{
		tmp = (t_list *)malloc(sizeof (t_list));
		if (!tmp)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		tmp->content = f(lst->content);
		tmp->next = NULL;
		ft_lstadd_back(&head, tmp);
		lst = lst->next;
	}
	return (head);
}
