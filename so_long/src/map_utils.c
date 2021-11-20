/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 08:58:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/20 12:32:09 by dthalman         ###   ########.fr       */
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
	if (x < map->size.w && y < map->size.h)
		return (map->coord[(map->size.w * y) + x]);
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
	if (x < map->size.w && y < map->size.h)
	{
		map->coord[(map->size.w * y) + x] = v;
		if ((char)v == 'P')
		{
			map->player_pos.x = x;
			map->player_pos.y = y;
			ft_printf("map x %d, z %d/n", map->player_pos.x, map->player_pos.y);
		}
	}
}

/**
 * @brief convertie une position de la carte en position
 * 
 * 
 * @param m_pos 
 * @param s_pos 
 * @return t_pos 
 */
t_pos	ft_map_pos_to_screen(t_pos m_pos)
{
	t_pos	s_pos;

	s_pos.x = MAP_SPRITE_WIDTH * m_pos.x;
	s_pos.y = MAP_SPRITE_HEIGHT * m_pos.y;
	return (s_pos);
}
