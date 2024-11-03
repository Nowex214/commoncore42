/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehenry <ehenry@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:08:05 by ehenry            #+#    #+#             */
/*   Updated: 2024/11/03 16:08:05 by ehenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;

	if (!(lst || f))
		return (NULL);
	lst1 = lst;
	lst2 = ft_lstnew(lst->content);
	if (!lst1)
		return (NULL);
	lst3 = ft_lstnew(f(lst1->next->content));
	while (lst1->next)
	{
		lst3 = ft_lstnew(f(lst1->next->content));
		if (!lst3)
		{
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ft_lstadd_back(&lst2, &lst3);
		lst1 = lst1->next;	
	}
	return (lst2);
}
/*
int	main(void)
{
    t_list	*list;
    t_list	*new_list;
    t_list	*elem1;
    t_list	*elem2;
    t_list	*elem3;

    // Création de la liste initiale
    elem1 = ft_lstnew("Hello");
    elem2 = ft_lstnew("World");
    elem3 = ft_lstnew("42");
    ft_lstadd_back(&elem1, elem2);
    ft_lstadd_back(&elem1, elem3);

    // Fonction de transformation
    void *to_upper(void *content)
    {
        char *str = (char *)content;
        for (int i = 0; str[i]; i++)
            str[i] = ft_toupper(str[i]);
        return (str);
    }

    // Suppression d'un élément
    void del(void *content)
    {
        free(content);
    }

    // Application de ft_lstmap
    new_list = ft_lstmap(elem1, to_upper, del);

    // Affichage des résultats
    t_list *temp = new_list;
    while (temp)
    {
        printf("%s\n", (char *)temp->content);
        temp = temp->next;
    }

    // Nettoyage de la mémoire
    ft_lstclear(&elem1, del);
    ft_lstclear(&new_list, del);

    return (0);
}
*/