/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:41:15 by surkim            #+#    #+#             */
/*   Updated: 2023/03/16 15:48:35 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	i++;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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

	new1->next = new2;
	new2->next = new3;
	new3->next = new4;
	lst = new1;
	
	int a = ft_lstsize(lst);
	printf("%d\n",a);
	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}*/