/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:03:54 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/09 12:04:56 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list2.h"
#include <stdlib.h>

/**
 * @brief Alloue (avec malloc(3)) et renvoie un nouvel élément. la variable 
 * content est initialisée à l’aide de la valeur du paramètre content. La
 * variable ’next’ est initialisée à NULL.
 * 
 * @param content value of content
 * @return t_list* 
 */
t_list2	*ft_lst2new(void *content)
{
	t_list2	*list;

	list = malloc(sizeof(t_list2));
	if (list)
	{
		list->next = 0;
		list->previous = 0;
		list->content = content;
	}
	return (list);
}

/**
 * @brief Renvoie le dernier élément de la liste
 * 
 * @param lst 
 * @return t_list* 
 */
t_list2	*ft_lst2last(t_list2 *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/**
 * @brief Ajoute l’élément ’new’ au début de la liste.
 * 
 * @param alst 
 * @param new 
 */
void	ft_lst2add_front(t_list2 **alst, t_list2 *new)
{
	new->previous = 0;
	new->next = (*alst);
	if (*alst)
		(*alst)->previous = new;
	*alst = new;
}

/**
 * @brief Ajoute l’élément new à la fin de la liste.
 * 
 * @param alst 
 * @param new 
 */
void	ft_lst2add_back(t_list2 **alst, t_list2 *new)
{
	t_list2	*llast;

	if (!*alst)
	{
		*alst = new;
		new->previous = 0;
		new->next = 0;
	}
	else
	{
		llast = ft_lst2last(*alst);
		llast->next = new;
		new->previous = llast;
		new->next = 0;
	}
}

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
