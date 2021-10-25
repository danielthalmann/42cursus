/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:11:30 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/24 16:11:30 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Itère sur la liste lst et applique la fonction f au contenu de chaque 
 * élément. Crée une nouvelle liste résultant des applications successives de f. 
 * la fonction del est la pour detruire le contenu d un element si necessaire
 * 
 * @param lst 
 * @param f 
 * @param del 
 * @return t_list* 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*r;

	r = 0;
	start = 0;
	while (lst)
	{
		if (!start)
		{
			r = ft_lstnew((*f)(lst->content));
			start = r;
		}
		else
		{
			r->next = ft_lstnew((*f)(lst->content));
			r = r->next;
		}
		if (!r && start)
		{
			ft_lstclear(&start, (del));
			break ;
		}
		lst = lst->next;
	}
	return (start);
}
