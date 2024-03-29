/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:12:32 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/13 17:41:04 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

/**
 * @brief return true if the value of list a is little that list b
 * 
 * @param a 
 * @param b 
 */
int	ft_a_lt_b(t_list2 *a, t_list2 *b)
{
	t_number	*na;
	t_number	*nb;

	na = a->content;
	nb = b->content;
	return (na->n < nb->n);
}

/**
 * @brief return true if the value of list a is great that list b
 * 
 * @param a 
 * @param b 
 */
int	ft_a_gt_b(t_list2 *a, t_list2 *b)
{
	t_number	*na;
	t_number	*nb;

	na = a->content;
	nb = b->content;
	return (na->n > nb->n);
}

/**
 * @brief return true if the value of list a is equal to list b
 * 
 * @param a 
 * @param b 
 */
int	ft_a_eq_b(t_list2 *a, t_list2 *b)
{
	t_number	*na;
	t_number	*nb;

	na = a->content;
	nb = b->content;
	return (na->n == nb->n);
}

/**
 * @brief return true if the value of list a is great or egual
 * that list b
 * 
 * @param a 
 * @param b 
 */
int	ft_a_lte_b(t_list2 *a, t_list2 *b)
{
	t_number	*na;
	t_number	*nb;

	na = a->content;
	nb = b->content;
	return (na->n <= nb->n);
}
