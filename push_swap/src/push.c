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
 * @brief push a take the first element at the top ofband put it at the top ofa.
 * Do nothing if bis empty.
 * 
 * @param lists 
 */
void ft_push_a(t_swap *lists)
{
	t_list2 *a_next;

	if (!lists->a)
		return;

	a_next = lists->a->next;
	ft_lst2add_front(&(lists->b), lists->a);
	if (!lists->b_end)
		lists->b_end = lists->b;
	lists->a->previous = 0;
	lists->a = a_next;
	if(a_next)
		a_next->previous = 0;
	else
		lists->a_end = 0;
	lists->a_length--;
	lists->b_length++;
}

/**
 * @brief pb :push b- take the first element at the top ofaand put it at the
 * top of b. Donothing ifais empty.
 * 
 * @param lists 
 */
void ft_push_b(t_swap *lists)
{
	t_list2 *b_next;

	if (!lists->b)
		return;
	b_next = lists->b->next;
	ft_lst2add_front(&(lists->a), lists->b);
	if (!lists->a_end)
		lists->a_end = lists->a;
	lists->b->previous = 0;
	lists->b = b_next;
	if(b_next)
		b_next->previous = 0;
	else
		lists->b_end = 0;
	lists->a_length++;
	lists->b_length--;
}
