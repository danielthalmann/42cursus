/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:12:32 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/14 14:48:48 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

int	ft_exec_swap(t_push_swap_cmd cmd, t_swap *lists)
{
	if (cmd == sa)
	{
		ft_swap_a(lists);
		return (ft_printf("sa\n"));
	}
	else if (cmd == sb)
	{
		ft_swap_b(lists);
		return (ft_printf("sb\n"));
	}
	else if (cmd == ss)
	{
		ft_swap_ss(lists);
		return (ft_printf("ss\n"));
	}
	return (0);
}

int	ft_exec_push(t_push_swap_cmd cmd, t_swap *lists)
{
	if (cmd == pa)
	{
		ft_push_a(lists);
		return (ft_printf("pa\n"));
	}
	else if (cmd == pb)
	{
		ft_push_b(lists);
		return (ft_printf("pb\n"));
	}
	return (0);
}

int	ft_exec_rotate(t_push_swap_cmd cmd, t_swap *lists)
{
	if (cmd == ra)
	{
		ft_rotate_a(lists);
		return (ft_printf("ra\n"));
	}
	else if (cmd == rb)
	{
		ft_rotate_b(lists);
		return (ft_printf("rb\n"));
	}
	else if (cmd == rr)
	{
		ft_rotate_rr(lists);
		return (ft_printf("rb\n"));
	}
	return (0);
}

int	ft_exec_rev_rotate(t_push_swap_cmd cmd, t_swap *lists)
{
	if (cmd == rra)
	{
		ft_reverse_rotate_a(lists);
		return (ft_printf("rra\n"));
	}
	else if (cmd == rrb)
	{
		ft_reverse_rotate_b(lists);
		return (ft_printf("rrb\n"));
	}
	else if (cmd == rrr)
	{
		ft_reverse_rotate_rr(lists);
		return (ft_printf("rrr\n"));
	}
	return (0);
}

void ft_debug(t_swap *lists)
{
	if (0)
	{
		ft_print_swap(lists);
		sleep(1);		
	}
}

/**
 * @brief Execute a command on lists
 * 
 * @param cmd 
 * @param lists 
 */
void	ft_exec(t_push_swap_cmd cmd, t_swap *lists)
{
	if (ft_exec_swap(cmd, lists))
		return (ft_debug(lists));
	if (ft_exec_push(cmd, lists))
		return (ft_debug(lists));
	if (ft_exec_rotate(cmd, lists))
		return (ft_debug(lists));
	if (ft_exec_rev_rotate(cmd, lists))
		return (ft_debug(lists));
}
