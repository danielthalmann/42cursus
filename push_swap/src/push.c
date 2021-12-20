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

#include "push_swap.h"
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
	ft_push_a_b(&lists->a, &lists->b);
}

/**
 * @brief pb :push b- take the first element at the top ofaand put it at the
 * top of b. Donothing ifais empty.
 * 
 * @param lists 
 */
void ft_push_b(t_swap *lists)
{
	ft_push_a_b(&lists->b, &lists->a);
}

void ft_push_a_b(t_stack *a, t_stack *b)
{
	t_list2 *new;

	if (!a->list)
		return;
	new = a->list;
	a->list = a->list->next;
	if (new == a->end)
		a->end = 0;
	if (a->list)
		a->list->previous = 0;
	ft_lst2add_front(&(b->list), new);
	if (!b->end)
		b->end = new;
	a->length--;
	b->length++;
}