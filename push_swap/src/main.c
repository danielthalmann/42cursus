/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 07:43:01 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/12 17:10:58 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list2.h"
#include "push_swap.h"
#include "libft.h"
#include "main.h"

void	ft_error(char *str)
{
	ft_fprintf(2, str);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_swap	lists;

	if (argc < 2)
		ft_error("Error\n");
	ft_load_swap_list(&lists, ++argv, argc - 1);
	if (ft_is_list_valid(&lists))
		ft_push_swap_resolv(&lists);
	else
		ft_fprintf(2, "Error\n");
	ft_free_swap_list(&lists);
	return (0);
}
