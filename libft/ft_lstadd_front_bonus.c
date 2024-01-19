/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:42:47 by surkim            #+#    #+#             */
/*   Updated: 2023/03/16 15:38:56 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

int main(void)
{
	t_list *lst;
	t_list *new = ft_lstnew("a");
	t_list *new1 = ft_lstnew("a");
	t_list *new2 = ft_lstnew("b");
	t_list *new3 = ft_lstnew("c");
	t_list *new4 = ft_lstnew("d");

	new1->next = new2;
	new2->next = new3;
	new3->next = new4;
	lst = new1;
	ft_lstadd_front(&lst, new);
	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}*/