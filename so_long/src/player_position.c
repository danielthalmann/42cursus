/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/30 06:57:02 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"
#include "render.h"
#include "map.h"
#include "libft.h"
#include "mlx.h"

void	ft_update_player_pos(t_player *player, t_game *game)
{
	char	c;

	ft_update_player_pos_horizontal(player, game);
	ft_update_player_pos_vertical(player, game);
	if (ft_is_same_pos(&player->position, &player->destination))
	{
		player->walk = 0;
		player->current_state = player->end_state;
		player->map_position = player->map_destination;
		c = ft_get_map_pos(&game->map, player->map_position.x, player->map_position.y);
		if(c == 'C')
		{
			game->map.nb_collect--;
			ft_set_map_pos('0', &game->map, player->map_position.x, player->map_position.y);
		}
		if (c == 'E')
			ft_end_game();
		ft_update_player(player, game, player->anim_last_time);
	}
}

void	ft_update_player_pos_horizontal(t_player *player, t_game *game)
{
	if (player->position.x < player->destination.x)
	{
		player->position.x += player->speed;
		if (player->position.x > player->destination.x)
			player->position.x = player->destination.x;
	}
	if (player->position.x > player->destination.x)
	{
		player->position.x -= player->speed;
		if (player->position.x < player->destination.x)
			player->position.x = player->destination.x;
	}
}

void	ft_update_player_pos_vertical(t_player *player, t_game *game)
{
	if (player->position.y < player->destination.y)
	{
		player->position.y += player->speed;
		if (player->position.y > player->destination.y)
			player->position.y = player->destination.y;
	}
	if (player->position.y > player->destination.y)
	{
		player->position.y -= player->speed;
		if (player->position.y < player->destination.y)
			player->position.y = player->destination.y;
	}
}
