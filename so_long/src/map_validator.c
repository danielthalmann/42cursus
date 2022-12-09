/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:21:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/01 12:03:06 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map.h"
#include "render.h"
#include "libft.h"

int	ft_valid_map(t_map *map)
{
	if (!map->nb_collect)
		return (2);
	if (!map->has_exit)
		return (3);
	if (map->size.w < 3 || map->size.h < 3)
		return (4);
	if (map->player_pos.x == 0 && map->player_pos.y == 0)
		return (5);
	if (!ft_valid_map_caracter(map))
		return (6);
	if (!ft_valid_map_isclosed_h(map))
		return (7);
	if (!ft_valid_map_isclosed_v(map))
		return (8);
	return (0);
}

int	ft_valid_map_caracter(t_map *map)
{
	t_uint	x;
	t_uint	y;
	char	c;

	x = 0;
	while (x < map->size.w)
	{
		y = 0;
		while (y < map->size.h)
		{
			c = ft_get_map_pos(map, x, y);
			if (!ft_strchr("CEM10P", c))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	ft_valid_map_isclosed_h(t_map *map)
{
	t_uint	x;

	x = 0;
	while (x < map->size.w)
	{
		if (ft_get_map_pos(map, x, 0) != '1')
			return (0);
		x++;
	}
	x = 0;
	while (x < map->size.w)
	{
		if (ft_get_map_pos(map, x, map->size.h - 1) != '1')
			return (0);
		x++;
	}
	return (1);
}

int	ft_valid_map_isclosed_v(t_map *map)
{
	t_uint	y;

	y = 0;
	while (y < map->size.h)
	{
		if (ft_get_map_pos(map, 0, y) != '1')
			return (0);
		y++;
	}
	y = 0;
	while (y < map->size.h)
	{
		if (ft_get_map_pos(map, map->size.w - 1, y) != '1')
			return (0);
		y++;
	}
	return (1);
}
