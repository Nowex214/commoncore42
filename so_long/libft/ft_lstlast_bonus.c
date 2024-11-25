/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:15:04 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/02 14:15:04 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew("Hello World!");
	new = ft_lstnew("Bonjour le monde!");
	ft_lstadd_front(&list, new);
	printf("%s\n", (char *)ft_lstlast(list)->content);
	return (0);
}*/