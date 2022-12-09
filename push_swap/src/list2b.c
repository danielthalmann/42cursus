/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:03:54 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/12 11:07:01 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list2.h"
#include <stdlib.h>

/**
 * @brief Libère la mémoire de l’élément passé en argument en utilisant 
 * la fonction del puis avec free(3). La mémoire de next ne doit pas être free.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lst2delone(t_list2 *lst, void (*del)(void*))
{
	(*del)(lst->content);
	free(lst);
}

/**
 * @brief Supprime et libère la mémoire de l’élément passé en paramètre, 
 * et de tous les élements qui suivent, à l’aide de del et de free(3)
 * Enfin, le pointeur initial doit être mis à NULL
 * 
 * @param lst 
 * @param del 
 */
void	ft_lst2clear(t_list2 **lst, void (*del)(void*))
{
	t_list2	*l;
	t_list2	*p;

	if (!lst)
		return ;
	l = *lst;
	while (l)
	{
		p = l;
		l = l->next;
		ft_lst2delone(p, del);
	}
	*lst = 0;
}
