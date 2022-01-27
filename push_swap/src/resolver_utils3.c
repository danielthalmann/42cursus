/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:37:29 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/14 15:18:05 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

void	ft_push_b_region_int(t_descriptor *desc)
{
	t_uint	idx;

	while (desc->len)
	{
		idx = ft_get_index(desc->lists->a.list);
		if (idx >= desc->min && idx <= desc->max)
			ft_push_swap_resolv_a_to_b(desc->lists);
		else
			ft_exec(ra, desc->lists);
		desc->len--;
	}
}

/**
 * @brief Déplace une portion de la liste a dans la b. Cette portion correspond
 * au indexe précalculé de la liste.
 * 
 * @param lists 
 * @param size taille total d'élément
 * @param split part à couper
 * @param index part actuelle à traiter
 */
void	ft_push_b_region(t_swap *lists, t_uint size, t_uint split, t_uint index)
{
	t_descriptor	desc;

	desc.range = (size / split);
	desc.min = (desc.range * index) + 1;
	if (index + 1 == split)
		desc.max = size;
	else
		desc.max = 5 + (desc.range * (index + 1));
	desc.len = lists->a.length;
	desc.lists = lists;
	ft_push_b_region_int(&desc);
}

/**
 * @brief retourne l'index de la list *l du prochain élément chainé qui est dans
 * la tranche de l'index entre min et max en reculant dans la liste
 * 
 * @param l 
 * @param min 
 * @param max 
 * @return long 
 */
long	ft_search_next_index_p(t_list2 *l, t_uint min, t_uint max)
{
	t_uint	index;
	t_uint	final_index;

	index = 0;
	while (l)
	{
		final_index = ft_get_index(l);
		if (final_index >= min && final_index <= max)
			return (index);
		l = l->previous;
		index++;
	}
	return (-1);
}

/**
 * @brief retourne l'index de la list *l du prochain élément chainé qui est dans
 * la tranche de l'index entre min et max en avancant dans la liste
 * 
 * @param l 
 * @param min 
 * @param max 
 * @return long 
 */
long	ft_search_next_index(t_list2 *l, t_uint min, t_uint max)
{
	t_uint	index;
	t_uint	final_index;

	index = 0;
	while (l)
	{
		final_index = ft_get_index(l);
		if (final_index >= min && final_index <= max)
			return (index);
		l = l->next;
		index++;
	}
	return (-1);
}
