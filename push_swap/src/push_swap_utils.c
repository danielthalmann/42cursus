/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:12:32 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/14 10:30:01 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void	ft_print_content(t_list2 *list)
{
	if (list)
		ft_printf("%8s", ((t_number *)list->content)->s);
	else
		ft_printf("%8s", "");
}

void	ft_print_address(t_list2 *list)
{
	if (list)
		ft_printf(" a %15p p %15p n %15p", list, list->previous, list->next);
	else
		ft_printf("   %15s   %15s   %15s", "", "", "");
}

/**
 * @brief print the content of lists
 * 
 * @param lists 
 */
void	ft_print_swap(t_swap *lists)
{
	t_list2	*list_a;
	t_list2	*list_b;

	list_a = lists->a.list;
	list_b = lists->b.list;
	ft_printf("%8s%8s\n", "list a", "list b");
	while (list_a || list_b)
	{
		ft_print_content(list_a);
		ft_print_content(list_b);
		ft_print_address(list_a);
		ft_print_address(list_b);
		if (list_a)
			list_a = list_a->next;
		if (list_b)
			list_b = list_b->next;
		ft_printf("\n");
	}
	ft_printf("%8s%8s\n", "end a", "end b");
	ft_print_content(lists->a.end);
	ft_print_content(lists->b.end);
	ft_print_address(lists->a.end);
	ft_print_address(lists->b.end);
	ft_printf("\n%8s%8s\n", "len a", "len b");
	ft_printf("%8d%8d\n\n", lists->a.length, lists->b.length);
}

/**
 * @brief libère de la mémoire les listes
 * 
 * @param lists 
 */
void	ft_free_swap_list(t_swap *lists)
{
	ft_lst2clear(&(lists->a.list), free);
	ft_lst2clear(&(lists->b.list), free);
	lists->a.end = 0;
	lists->b.end = 0;
}
