/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:28:18 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/24 10:28:18 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief Supprime et libère la mémoire de l’élément passé en paramètre, 
 * et de tous les élements qui suivent, à l’aide de del et de free(3)
 * Enfin, le pointeur initial doit être mis à NULL
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;
	t_list	*p;

	if (!lst)
		return ;
	l = *lst;
	while (l)
	{
		p = l;
		l = l->next;
		(*del)(p->content);
		free(p);
	}
}
