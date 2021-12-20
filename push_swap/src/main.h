/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 07:43:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/17 07:43:01 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "push_swap.h"

int		main(int argc, char **argv);
t_uint	ft_next_height(t_list2 *c);
t_uint	ft_height_value(t_list2 *c);
void	ft_push_swap_test(t_swap *lists);
void	ft_push_swap_resolv_3(t_swap *lists);
void	ft_push_swap_resolv(t_swap *lists);
#endif
