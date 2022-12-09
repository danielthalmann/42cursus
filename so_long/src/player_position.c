/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/03 13:10:42 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"
#include "render.h"
#include "map.h"
#include "libft.h"
#include "mlx.h"
#include "score.h"

void	ft_update_player_pos(t_player *player, t_game *game)
{
	char	c;

	ft_update_player_pos_horizontal(player);
	ft_update_player_pos_vertical(player);
	if (ft_is_same_pos(&player->position, &player->destination))
	{
		player->walk = 0;
		game->nb_move++;
		ft_printf("%d\n", game->nb_move);
		player->current_state = player->end_state;
		player->map_position = player->map_destination;
		c = ft_get_map_pos2(&game->map, &player->map_position);
		if (c == 'C')
		{
			game->map.nb_collect--;
			ft_set_map_pos2('0', &game->map, &player->map_position);
		}
		if (c == 'E')
			ft_end_game(0);
		if (c == 'M')
			ft_end_game(0);
		ft_update_player(player, game, player->anim_last_time);
		ft_draw_monster();
	}
}

void	ft_update_player_pos_horizontal(t_player *player)
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

void	ft_update_player_pos_vertical(t_player *player)
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
