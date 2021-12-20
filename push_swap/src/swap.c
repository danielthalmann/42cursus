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
 * @brief swap the first 2 elements at the top of stacka. Do nothing if thereis
 * only one or no elements
 * 
 * @param lists 
 */
void ft_swap_a(t_swap *lists)
{
	ft_swap_list(&(lists->a));
}

/**
 * @brief swap b- swap the first 2 elements at the top of stackb. 
 * Do nothing if thereis only one or no elements).
 * 
 * @param lists 
 */
void ft_swap_b(t_swap *lists)
{
	ft_swap_list(&(lists->b));
}

/**
 * @brief sa and sb at the same time.
 * 
 * @param lists 
 */
void ft_swap_ss(t_swap *lists)
{
	ft_swap_a(lists);
	ft_swap_b(lists);
}

/**
 * @brief swap the first 2 elements at the top of stack. 
 * Do nothing if there is only one or no elements.
 * 
 * @param lists 
 */
void ft_swap_list(t_stack *stack)
{
	t_list2 *list_nnext;
	t_list2 *list_next;
	t_list2 *list;

	if (!stack->list)
		return ;
	if (!stack->list->next)
		return ;
	list = stack->list;
	list_next = stack->list->next;
	list_nnext = stack->list->next->next;
	stack->list = list_next;
	stack->list->previous = 0;
	stack->list->next = list;
	stack->list->next->previous = stack->list;
	stack->list->next->next = list_nnext;
	if (stack->end == list_next)
		stack->end = stack->list;
}

