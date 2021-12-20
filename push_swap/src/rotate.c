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
 * @brief rotate a- shift up all elements of stackaby 1. The first element 
 * becomes the last one.
 * 
 * @param lists 
 */
void ft_rotate_a(t_swap *lists)
{
	ft_rotate_list(&(lists->a));
}

/**
 * @brief rotate b- shift up all elements of stackbby 1. The first element 
 * becomes the last one.
 * 
 * @param lists 
 */
void ft_rotate_b(t_swap *lists)
{
	ft_rotate_list(&(lists->b));
}

/**
 * @brief ra and rb at the same time.
 * 
 * @param lists 
 */
void ft_rotate_rr(t_swap *lists)
{
	ft_rotate_a(lists);
	ft_rotate_b(lists);
}

/**
 * @brief shift up all elements of stackbby 1. The first element 
 * becomes the last one.
 * 
 * @param stack 
 */
void ft_rotate_list(t_stack *stack)
{
	t_list2 *new;
	t_list2 *new_next;

	if (!stack->list)
		return ;
	if (!stack->list->next)
		return ;
	new = stack->list;
	new_next = stack->list->next;
	stack->end->next = new;
	new->previous = stack->end;
	new->next = 0;
	stack->end = new;
	new_next->previous = 0;
	stack->list = new_next;
}
