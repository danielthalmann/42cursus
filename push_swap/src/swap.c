/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:12:32 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/09 12:09:08 by dthalman         ###   ########.fr       */
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
void	ft_swap_a(t_swap *lists)
{
	ft_swap_list(&(lists->a));
}

/**
 * @brief swap b- swap the first 2 elements at the top of stackb. 
 * Do nothing if thereis only one or no elements).
 * 
 * @param lists 
 */
void	ft_swap_b(t_swap *lists)
{
	ft_swap_list(&(lists->b));
}

/**
 * @brief sa and sb at the same time.
 * 
 * @param lists 
 */
void	ft_swap_ss(t_swap *lists)
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
void	ft_swap_list(t_stack *stack)
{
	t_list2	*new;
	t_list2	*new_next;

	if (!stack->list)
		return ;
	if (!stack->list->next)
		return ;
	new = stack->list->next;
	new_next = stack->list->next->next;
	ft_lst2add_front(&(stack->list), new);
	stack->list->next->next = new_next;
	if (new_next)
		new_next->previous = stack->list->next;
	if (stack->end == new)
		stack->end = stack->list->next;
}
