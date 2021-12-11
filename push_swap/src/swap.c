/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:12:32 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/04 19:31:42 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include "libft.h"
#include <stdlib.h>

/**
 * @brief swap the first 2 elements at the top of stacka. Do nothing if thereis
 * only one or no elements
 * 
 * @param lists 
 */
void ft_swap_a(t_swap *lists)
{
	t_list2 *a_nnext;
	t_list2 *a_next;

	if (!lists->a)
		return ;
	if (!lists->a->next)
		return ;	
	a_next = lists->a->next;
	a_nnext = lists->a->next->next;
	if (lists->a_end == a_next)
		lists->a_end = lists->a;
	a_next->next = lists->a;
	a_next->previous = 0;
	lists->a->next = a_nnext;
	lists->a->previous = a_next;
	lists->a = a_next;
	if (lists->a_end == a_nnext)
		lists->a_end = a_next;
}

/**
 * @brief swap b- swap the first 2 elements at the top of stackb. 
 * Do nothing if thereis only one or no elements).
 * 
 * @param lists 
 */
void ft_swap_b(t_swap *lists)
{
	t_list2 *b_nnext;
	t_list2 *b_next;

	if (!lists->b)
		return ;
	if (!lists->b->next)
		return ;	
	b_next = lists->b->next;
	b_nnext = lists->b->next->next;
	if (lists->b_end == b_next)
		lists->b_end = lists->b;
	b_next->next = lists->b;
	b_next->previous = 0;
	lists->b->next = b_nnext;
	lists->b->previous = b_next;
	lists->b = b_next;
	if (lists->b_end == b_nnext)
		lists->b_end = b_next;
}

/**
 * @brief sa and sb at the same time.
 * 
 * @param lists 
 */
void ft_swap_ss(t_swap *lists)
{
	ft_swap_a(lists);
	ft_swap_a(lists);
}
