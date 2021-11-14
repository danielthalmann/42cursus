/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 08:58:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/14 09:04:44 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "game.h"
#include "map.h"

/**
 * @brief retourne la valeur contenu de la position de la map
 * 
 * @param map 
 * @param x 
 * @param y 
 * @return t_uint 
 */
t_uint	ft_get_map_pos(t_map *map, t_uint x, t_uint y)
{
	if (x < map->size.width && y < map->size.height)
		return (map->coord[(map->size.height * y) + x]);
	return (0);
}

/**
 * @brief defini une valeur dans la position de la map
 * 
 * @param v 
 * @param map 
 * @param x 
 * @param y 
 */
void	ft_set_map_pos(t_uint v, t_map *map, t_uint x, t_uint y)
{
	if (x < map->size.width && y < map->size.height)
		map->coord[(map->size.height * y) + x] = v;
}