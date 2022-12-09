/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_position2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 08:58:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/03 13:34:35 by dthalman         ###   ########.fr       */
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
t_uint	ft_get_map_pos2(t_map *map, t_pos *pos)
{
	t_uint	c;

	c = ft_get_map_pos(map, pos->x, pos->y);
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
void	ft_set_map_pos2(t_uint v, t_map *map, t_pos *pos)
{
	ft_set_map_pos(v, map, pos->x, pos->y);
}

void	ft_draw_map_pos_xy(t_map *map, t_gl *gl, t_uint x, t_uint y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	ft_draw_map_pos(map, gl, pos);
}
