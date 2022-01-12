/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:03:54 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/12 11:07:11 by dthalman         ###   ########.fr       */
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
