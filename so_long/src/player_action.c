/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/03 14:18:36 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"
#include "render.h"
#include "map.h"
#include "libft.h"
#include "mlx.h"

void	ft_update_player_action(t_player *player, t_game *game, t_state *s)
{
	int	x;
	int	y;
	int	not_allowed;
	int	c;

	if (player->walk)
		return ;
	ft_update_player_action_h(player, game, s);
	ft_update_player_action_v(player, game, s);
	if (player->walk == 1)
	{
		x = player->map_destination.x;
		y = player->map_destination.y;
		c = ft_get_map_pos(&(game->map), x, y);
		not_allowed = ((c == '1') || (c == 'E' && game->map.nb_collect > 0));
		if (not_allowed)
			player->walk = 0;
		else
		{
			player->current_state = s->on_walk;
			player->end_state = s->on_stay;
			player->destination = ft_map_pos_to_screen(player->map_destination);
		}
	}
}

void	ft_update_player_action_h(t_player *player, t_game *game, t_state *s)
{
	if (ft_keys_state()[s->key] && s->key == KEY_LEFT)
	{
		player->map_destination = player->map_position;
		if (player->map_destination.x > 0)
			player->map_destination.x--;
		player->walk = 1;
	}
	if (ft_keys_state()[s->key] && s->key == KEY_RIGHT)
	{
		player->map_destination = player->map_position;
		if (player->map_destination.x < game->map.size.w - 1)
			player->map_destination.x++;
		player->walk = 1;
	}
}

void	ft_update_player_action_v(t_player *player, t_game *game, t_state *s)
{
	if (ft_keys_state()[s->key] && s->key == KEY_UP)
	{
		player->map_destination = player->map_position;
		if (player->map_destination.y > 0)
			player->map_destination.y--;
		player->walk = 1;
	}
	if (ft_keys_state()[s->key] && s->key == KEY_DOWN)
	{
		player->map_destination = player->map_position;
		if (player->map_destination.y < game->map.size.h - 1)
			player->map_destination.y++;
		player->walk = 1;
	}
}
