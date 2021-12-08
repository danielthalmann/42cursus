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
 * @brief rotate a- shift up all elements of stackaby 1. The first element 
 * becomes the last one.
 * 
 * @param lists 
 */
void ft_rotate_a(t_swap *lists)
{
	t_list2 *a_next;

	if (!lists->a)
		return ;
	if (!lists->a->next)
		return ;
	a_next = lists->a->next;
	lists->a->next = 0;
	ft_lst2add_back(&(lists->a_end), lists->a);
	lists->a_end = lists->a;
	lists->a = a_next;
	lists->a->previous = 0;
}

/**
 * @brief rotate b- shift up all elements of stackbby 1. The first element 
 * becomes the last one.
 * 
 * @param lists 
 */
void ft_rotate_b(t_swap *lists)
{
	t_list2 *b_next;

	if (!lists->b)
		return ;
	if (!lists->b->next)
		return ;
	b_next = lists->b->next;
	lists->b->next = 0;
	ft_lst2add_back(&(lists->b_end), lists->b);
	lists->b_end = lists->b;
	lists->b = b_next;
	lists->b->previous = 0;
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
