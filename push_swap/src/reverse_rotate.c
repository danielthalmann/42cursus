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
 * @brief reverse rotate a- shift down all elements of stackaby 1. The last 
 * element becomes the first one.7
 * 
 * @param lists 
 */
void ft_reverse_rotate_a(t_swap *lists)
{
	ft_reverse_rotate_list(&(lists->a));
}

/**
 * @brief reverse rotate b- shift down all elements of stackbby 1. The last 
 * element becomes the first one.
 * 
 * @param lists 
 */
void ft_reverse_rotate_b(t_swap *lists)
{
	ft_reverse_rotate_list(&(lists->b));
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


/**
 * @brief shift down all elements of stack by 1. The last 
 * element becomes the first one.
 * 
 * @param stack 
 */
void ft_reverse_rotate_list(t_stack *stack)
{
	t_list2 *new;

	if (!stack->list)
		return ;
	if (!stack->list->next)
		return ;
	new = stack->end;
	new->previous->next = 0;
	stack->end = new->previous;
	ft_lst2add_front(&(stack->list), new);
}