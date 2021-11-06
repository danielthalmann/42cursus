/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:20:46 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 09:54:46 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line_bonus.h"

/**
 * @brief déplace le contenu de la chaine de from dans to
 * pour une longueur de chaine donnée par len
 * from est avancé de 1 au début
 * 
 * @param to 
 * @param from 
 * @param len longueur à copier
 */
void	ft_strmov(char *to, char *from, int len)
{
	int	i;

	from++;
	len = ft_strlen2(from, "");
	i = 0;
	while (i < len)
	{
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
}

/**
 * @brief Compte la longueur de la chaine se terminant par '\0' ou 
 * par l'un des caractères contenu dans la chaine eos.
 * le caractère contenu dans eos est compté dans le retour
 * 
 * @param s 
 * @param eos 
 * @return int len of string
 */
unsigned int	ft_strlen2(char *s, char *eos)
{
	unsigned int	c;
	int				i;
	int				p;

	c = 0;
	p = 0;
	while (*s && !p)
	{
		i = 0;
		while (eos[i])
		{
			if (eos[i] == *s)
			{
				p = 1;
				break ;
			}
			i++;
		}
		c++;
		s++;
	}
	return (c);
}

char	*fd_load_buffer(int fd, t_buffer **list)
{
	t_buffer	*c_list;

	c_list = *list;
	if (!c_list)
	{
		c_list = malloc(sizeof(t_buffer));
		c_list->fd = fd;
		c_list->buf[0] = 0;
		c_list->next = 0;
		*list = c_list;
		return (c_list->buf);
	}
	if (c_list->fd == fd)
		return (c_list->buf);
	while (c_list->next)
	{
		if (c_list->next->fd == fd)
			return (c_list->next->buf);
		c_list = c_list->next;
	}
	c_list->next = malloc(sizeof(t_buffer));
	c_list->next->fd = fd;
	c_list->next->buf[0] = 0;
	c_list->next->next = 0;
	return (c_list->next->buf);
}

long	fd_release_buffer(int fd, t_buffer **list)
{
	t_buffer		*c_list;
	t_buffer		*c_last;

	c_list = *list;
	c_last = 0;
	while (c_list)
	{
		if (c_list->fd == fd)
		{
			if (c_last)
				c_last->next = c_list->next;
			else
				*list = c_list->next;
			free(c_list);
			break ;
		}
		else
		{
			c_last = c_list;
			c_list = c_list->next;
		}
	}
	return (0);
}
