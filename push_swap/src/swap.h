/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:03:54 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/04 18:57:16 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# include <list2.h>
typedef unsigned int t_uint;
typedef struct s_swap
{
	t_list2	*a;
	t_list2	*a_last;
	t_list2	*b;
	t_list2	*b_last;
	t_uint	length;
}	t_swap;

ft_swap_a(t_swap lists);
ft_swap_b(t_swap lists);
ft_swap_ss(t_swap lists);
ft_swap_pa(t_swap lists);
ft_swap_pb(t_swap lists);
ft_swap_ra(t_swap lists);
ft_swap_rb(t_swap lists);
ft_swap_rr(t_swap lists);
ft_swap_rra(t_swap lists);
ft_swap_rrb(t_swap lists);
ft_swap_rrr(t_swap lists);
#endif