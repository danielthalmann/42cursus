/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:21:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/13 15:11:08 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int ft_load_map(char *filename, t_map *map)
{
	int		fd;
	char	*l;
	t_list	*lines;

	fd = open(filename, O_RDONLY);
	ft_printf("%s\n", filename);	
	if(fd == -1)
		return (0);
		//ft_printf("Impossible d'ouvrir le fichier (%s).\n", filename);
	else
	{
		lines = 0;
		l = get_next_line(fd);
		while (l)
		{
			ft_lstadd_back(&lines, ft_lstnew(l));
			l = get_next_line(fd);
		}
	}
	close(fd);
	ft_Load_list_map(lines, map);
	ft_free_list_map(lines);
	return (1);
}

int	ft_Load_list_map(t_list *list, t_map *map)
{
	int	x;
	int y;

	if (!list)
		return (0);
	map->size.height = ft_lstsize(list);
	map->size.width = ft_strlen(list->content);
	map->coord = malloc(sizeof(t_uint) * map->size.height * map->size.width);
	while (y < map->size.height)
	{
		while (x < map->size.width)
		{
			map->coord= malloc(sizeof(t_uint) * map->size.height * map->size.width);
			
		}
	}
}

/**
 * @brief libère de la mémoire toute la liste
 * 
 * @param list 
 */
void	ft_free_list_map(t_list *list)
{
	t_list	*to_free;

	while (list)
	{
		free(list->content);
		to_free = list;
		list = list->next;
		free(to_free);
	}
}
