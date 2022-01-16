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

void	ft_p_b_r_a(t_swap *lists, t_uint size, t_uint split, t_uint index)
{
	long	j;

	j = ft_search_next_index_p(lists->a.end, ((size / split) * index),
			((size / split) * (index + 1)) + 1);
	while (j > -1)
	{
		j++;
		if (j != lists->a.length)
		{
			while (j)
			{
				if (index != split - 1)
					ft_exec(rra, lists);
				else
					ft_exec(ra, lists);
				j--;
			}
		}
		ft_push_swap_resolv_a_to_b(lists);
		j = ft_search_next_index_p(lists->a.end, ((size / split) * index),
				((size / split) * (index + 1)));
	}
}

void	ft_p_b_r_b(t_swap *lists, t_uint size, t_uint split, t_uint index)
{
	long	j;

	j = ft_search_next_index(lists->a.list, ((size / split) * index),
			((size / split) * (index + 1)) + 1);
	while (j > -1)
	{
		if (j != lists->a.length)
		{
			while (j)
			{
				if (index != split - 1)
					ft_exec(rra, lists);
				else
					ft_exec(ra, lists);
				j--;
			}
		}
		ft_push_swap_resolv_a_to_b(lists);
		j = ft_search_next_index(lists->a.list, ((size / split) * index),
				((size / split) * (index + 1)));
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
	if (index != split - 1)
		ft_p_b_r_a(lists, size, split, index);
	else
		ft_p_b_r_b(lists, size, split, index);
}

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
