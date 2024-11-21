/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:12:58 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/02 14:12:58 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
/*
int	main(void)
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew("Hello World!");
	new = ft_lstnew("Bonjour le monde!");
	ft_lstadd_front(&list, new);
	printf("%d\n", ft_lstsize(list));
	return (0);
}
*/