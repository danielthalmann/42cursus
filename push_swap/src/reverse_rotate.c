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
 * @brief reverse rotate a- shift down all elements of stackaby 1. The last 
 * element becomes the first one.7
 * 
 * @param lists 
 */
void ft_reverse_rotate_a(t_swap *lists)
{
	t_list2 *a_end;

	if (!lists->a_end)
		return ;
	if (!lists->a_end->previous)
		return ;
	a_end = lists->a_end->previous;
	a_end->next = 0;
	ft_lst2add_front(&(lists->a), lists->a_end);
	lists->a->previous = 0;
	lists->a_end = a_end;
}

/**
 * @brief reverse rotate b- shift down all elements of stackbby 1. The last 
 * element becomes the first one.
 * 
 * @param lists 
 */
void ft_reverse_rotate_b(t_swap *lists)
{
	t_list2 *b_end;

	if (!lists->b_end)
		return ;
	if (!lists->b_end->previous)
		return ;
	b_end = lists->b_end->previous;
	b_end->next = 0;
	ft_lst2add_front(&(lists->b), lists->b_end);
	lists->b->previous = 0;
	lists->b_end = b_end;
}

/**
 * @brief rra and rrb at the same time.
 * 
 * @param lists 
 */
void ft_reverse_rotate_rr(t_swap *lists)
{				
	ft_reverse_rotate_a(lists);
	ft_reverse_rotate_b(lists);
}
