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
# include "list2.h"
# ifndef ASDF
#  define LOG(s) ft_printf(s);
# else
#  define LOG(s)
# endif
typedef unsigned int t_uint;
typedef struct s_swap
{
	t_list2	*a;
	t_list2	*a_last;
	t_list2	*b;
	t_list2	*b_last;
	t_uint	length;
}	t_swap;
typedef struct s_number
{
	int		n;
	char	*s;
}	t_number;
void ft_swap_a(t_swap *lists);
void ft_swap_b(t_swap *lists);
void ft_swap_ss(t_swap *lists);
void ft_push_a(t_swap *lists);
void ft_push_b(t_swap *lists);
void ft_rotate_a(t_swap *lists);
void ft_rotate_b(t_swap *lists);
void ft_rotate_rr(t_swap *lists);
void ft_swap_rra(t_swap *lists);
void ft_swap_rrb(t_swap *lists);
void ft_swap_rrr(t_swap *lists);
void ft_print_swap(t_swap *lists);
#endif