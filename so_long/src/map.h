/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:21:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/13 15:10:13 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "utils.h"
# include "libft.h"

typedef struct s_map
{
	t_size	size;
	t_uint	*coord;
}	t_map;
int	ft_load_map(char *filename, t_map *map);
int	ft_Load_list_map(t_list *list, t_map *map);
void	ft_free_list_map(t_list *list);

#endif