/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 08:58:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/03 08:24:39 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map.h"
#include "utils.h"
#include "render.h"

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
	t_uint	c;

	c = 0;
	if (x < map->size.w && y < map->size.h)
		c = map->coord[(map->size.w * y) + x];
	return (c);
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
	}
}

void	ft_set_map_pos_init(t_uint v, t_map *map, t_uint x, t_uint y)
{
	if (x < map->size.w && y < map->size.h)
	{
		ft_set_map_pos(v, map, x, y);
		if ((char)v == 'P')
		{
			map->player_pos.x = x;
			map->player_pos.y = y;
		}
		if ((char)v == 'C')
			map->nb_collect++;
		if ((char)v == 'C')
			map->has_exit = 1;
		if ((char)v == 'M')
		{
			map->has_monster = 1;
			map->monster_pos.x = x;
			map->monster_pos.y = y;
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

void	ft_draw_map_pos(t_map *map, t_gl *gl, t_pos pos)
{
	t_translation	tr;
	char			c;

	ft_memset((void *)&tr, 0, sizeof(tr));
	tr.size.x = MAP_SPRITE_WIDTH;
	tr.size.y = MAP_SPRITE_HEIGHT;
	c = (char)ft_get_map_pos(map, pos.x, pos.y);
	if (ft_strchr("0P", c))
		tr.src.x = 0;
	else if (c == 'E')
		tr.src.x = MAP_SPRITE_WIDTH * 3;
	else if (c == 'C')
		tr.src.x = MAP_SPRITE_WIDTH * 2;
	else if (c == 'M')
		tr.src.x = MAP_SPRITE_WIDTH * 4;
	else
		tr.src.x = MAP_SPRITE_WIDTH;
	tr.dest.x = MAP_SPRITE_WIDTH * pos.x;
	tr.dest.y = MAP_SPRITE_HEIGHT * pos.y;
	ft_draw_image(map->img_ptr, gl, tr);
}
