/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:20:09 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/16 23:20:09 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_split_move_forward(char const **s, char c, int not);
char	**ft_split_allocate(char const *s, char c, int *count);
void	ft_split_cpy(char const *start, char const *end, char *mem);

/**
 * @brief split string, with specified character as delimiter, 
 * 		  into an array	of strings. The array is terminated by a NULL
 * 
 * @param s 
 * @param c 
 * @return char** 
 */
char	**ft_split(char const *s, char c)
{
	char const	*start;
	char const	*end;
	char		**split;
	int			y;
	int			count;	

	split = ft_split_allocate(s, c, &count);
	start = s;
	end = s;
	y = 0;
	while (*end && split && count)
	{
		ft_split_move_forward(&start, c, 0);
		end = start;
		ft_split_move_forward(&end, c, 1);
		if (end - start)
		{
			split[y] = malloc(end - start);
			ft_split_cpy(start, end, split[y++]);
		}
		start = end;
		ft_putnbr_fd((-y), 1);
	}
	split[y] = 0;
	return (split);
}

void	ft_split_move_forward(char const **s, char c, int not)
{
	if (not)
	{
		while (**s && **s != c)
			(*s)++;
	}
	else
	{
		while (**s && **s == c)
			(*s)++;
	}
}

char	**ft_split_allocate(char const *s, char c, int *count)
{
	char const	*str;

	(*count) = 0;
	str = s;
	while (*str)
	{
		ft_split_move_forward(&str, c, 0);
		if (*str)
		{
			(*count)++;
		}
		ft_split_move_forward(&str, c, 1);
	}
	return (malloc(((*count) + 1) * sizeof(char *)));
}

void	ft_split_cpy(char const *start, char const *end, char *mem)
{
	int	x;

	x = 0;
	while (start != end && mem)
	{
		mem[x++] = *start;
		start++;
	}
}
