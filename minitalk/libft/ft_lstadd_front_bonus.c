/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:19:24 by ehenry            #+#    #+#             */
/*   Updated: 2024/10/30 16:47:51 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
int main(void)
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew("Hello World!");
	new = ft_lstnew("Bonjour le monde!");
	ft_lstadd_front(&list, new);
	printf("%s\n", (char *)list->content);
	printf("%s\n", (char *)list->next->content);
	return (0);
}*/