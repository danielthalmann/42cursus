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
# include "utils.h"
# include "game.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
typedef struct s_map
{
	t_size	size;
	t_uint	*coord;
}	t_map;

int ft_load_map(char *filename, t_map *map);
#endif