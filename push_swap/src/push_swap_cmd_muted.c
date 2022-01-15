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

/**
 * @brief Execute a command on lists
 * 
 * @param cmd 
 * @param lists 
 */
void	ft_exec_muted(t_push_swap_cmd cmd, t_swap *lists)
{
	if (ft_exec_swap(cmd, lists, 1))
		return ;
	if (ft_exec_push(cmd, lists, 1))
		return ;
	if (ft_exec_rotate(cmd, lists, 1))
		return ;
	if (ft_exec_rev_rotate(cmd, lists, 1))
		return ;
}
