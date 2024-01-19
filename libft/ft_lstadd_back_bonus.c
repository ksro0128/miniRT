/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:20:02 by surkim            #+#    #+#             */
/*   Updated: 2023/03/16 21:59:51 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	tmp = *lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}
/*
#include <stdio.h>

int main(void)
{
	t_list *lst;
	t_list *new1 = ft_lstnew("a");
	t_list *new2 = ft_lstnew("b");
	t_list *new3 = ft_lstnew("c");
	t_list *new4 = ft_lstnew("d");
	t_list *new5 = ft_lstnew("good");

	lst = new1;
	ft_lstadd_back(&lst, new2);
	ft_lstadd_back(&lst, new3);
	ft_lstadd_back(&lst, new4);
	ft_lstadd_back(&lst, new5);
	for (int i = 0; i < 10; i++)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}*/