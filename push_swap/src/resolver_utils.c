/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:37:29 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/12 17:11:29 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
 * @brief retourne le plus grand nombre
 * 
 * @param c 
 * @return t_uint 
 */
t_uint	ft_height_value(t_list2 *c)
{
	t_list2	*l_height;

	l_height = c;
	c = c->next;
	while (c)
	{
		if (ft_a_lt_b(l_height, c))
			l_height = c;
		c = c->next;
	}
	return (((t_number *)l_height->content)->n);
}

/**
 * @brief retourne le plus petit nombre
 * 
 * @param c 
 * @return t_uint 
 */
t_uint	ft_low_value(t_list2 *c)
{
	t_list2	*l_low;

	l_low = c;
	c = c->next;
	while (c)
	{
		if (ft_a_lt_b(c, l_low))
			l_low = c;
		c = c->next;
	}
	return (((t_number *)l_low->content)->n);
}
