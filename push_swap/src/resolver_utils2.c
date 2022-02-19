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

/**
 * @brief retourne l'index du plus au nombre
 * 
 * @param c 
 * @return t_uint 
 */
t_uint	ft_next_height(t_list2 *c)
{
	t_uint	idx_height;
	t_uint	idx_curr;
	t_list2	*l_height;

	idx_height = 0;
	idx_curr = 0;
	l_height = c;
	c = c->next;
	while (c)
	{
		idx_curr++;
		if (ft_a_lt_b(l_height, c))
		{
			idx_height = idx_curr;
			l_height = c;
		}
		c = c->next;
	}
	return (idx_height);
}

/**
 * @brief retourne l'index le plus bas en nombre
 * 
 * @param c 
 * @return t_uint 
 */
t_uint	ft_next_low(t_list2 *c)
{
	t_uint	idx_low;
	t_uint	idx_curr;
	t_list2	*l_height;

	idx_low = 0;
	idx_curr = 0;
	l_height = c;
	c = c->next;
	while (c)
	{
		idx_curr++;
		if (ft_a_gt_b(l_height, c))
		{
			idx_low = idx_curr;
			l_height = c;
		}
		c = c->next;
	}
	return (idx_low);
}

/**
 * @brief retourne l'index du plus grand nombre juste après la valeur
 * 
 * @param c 
 * @return t_uint 
 */
t_uint	ft_get_index_of(t_list2 *c, int value)
{
	t_uint	idx_height;
	t_uint	idx_curr;
	int		sav;

	idx_height = 0;
	idx_curr = 0;
	sav = 2147483647;
	while (c)
	{
		idx_curr++;
		if (ft_get_value(c) > value)
		{
			if (sav >= ft_get_value(c))
			{
				idx_height = idx_curr - 1;
				sav = ft_get_value(c);
			}
		}
		else
			if (sav < ft_get_value(c))
				idx_height = idx_curr;
		c = c->next;
	}
	return (idx_height);
}

/**
 * @brief retourne l'index du plus petit nombre juste avant la valeur
 * 
 * @param c 
 * @return t_uint 
 */
t_uint	ft_get_smallindex_of(t_list2 *c, int value)
{
	t_uint	idx_height;
	t_uint	idx_curr;
	int		sav;

	idx_height = 0;
	idx_curr = 0;
	sav = ft_low_value(c);
	while (c)
	{
		idx_curr++;
		if (ft_get_value(c) < value)
		{
			if (sav <= ft_get_value(c))
			{
				idx_height = idx_curr - 1;
				sav = ft_get_value(c);
			}
		}
		else
			if (sav > ft_get_value(c))
				idx_height = idx_curr;
		c = c->next;
	}
	return (idx_height);
}
