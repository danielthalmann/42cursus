/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 07:43:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/17 07:43:01 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "main.h"

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc < 2)
	{
		ft_fprintf(2, "Error\n");
		return (1);
	}
	list = 0;
	ft_load_list(list, ++argc, ++argv);
	ft_lstclear(&list, free);
	return (0);
}

int	ft_load_list(t_list	*list, int l, char **v)
{
	int			i;
	t_number	*n;

	i = -1;
	while (++i < l)
	{
		n = malloc(sizeof(n));
		if (!n)
		{
			ft_lstclear(&list, free);
			return (0);
		}
		n->s = v[i];
		n->n = ft_atoi(v[i]);
		ft_lstadd_front(&list, ft_lstnew(n));
	}
	return (i + 1);
}
