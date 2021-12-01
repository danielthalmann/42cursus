/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/01 15:55:08 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"
#include "render.h"
#include "map.h"
#include "libft.h"
#include "mlx.h"

/**
 * @brief met à jour l'etat du joueur
 * 
 * @param player 
 * @param time 
 */
void	ft_update_player(t_player *player, t_game *game, int time)
{
	if (player->anim_last_time + player->speed_anim < time)
	{
		player->anim_index++;
		if (player->anim_index >= 10)
			player->anim_index = 0;
		player->anim_last_time = time;
	}
	if (!player->walk)
	{
		ft_update_player_horizontal(player, game);
		ft_update_player_vertical(player, game);
	}
	else
	{
		ft_update_player_pos(player, game);
	}
}

void	ft_update_player_horizontal(t_player *player, t_game *game)
{
	t_state	state;

	state.on_walk = PLAYER_ANIM_WALK_L;
	state.on_stay = PLAYER_ANIM_WAIT_L;
	state.key = KEY_LEFT;
	ft_update_player_action(player, game, &state);
	state.on_walk = PLAYER_ANIM_WALK_R;
	state.on_stay = PLAYER_ANIM_WAIT_R;
	state.key = KEY_RIGHT;
	ft_update_player_action(player, game, &state);
}

void	ft_update_player_vertical(t_player *player, t_game *game)
{
	t_state	state;

	state.on_walk = PLAYER_ANIM_WALK_B;
	state.on_stay = PLAYER_ANIM_WAIT_B;
	state.key = KEY_UP;
	ft_update_player_action(player, game, &state);
	state.on_walk = PLAYER_ANIM_WALK_F;
	state.on_stay = PLAYER_ANIM_WAIT_F;
	state.key = KEY_DOWN;
	ft_update_player_action(player, game, &state);
}

void	ft_draw_monster()
{
	t_game	*game;
	t_pos	dest;

	game = ft_game();
	if (!game->map.has_monster)
		return ;
	dest = game->map.monster_pos;
	if (game->map.monster_direction == 0)
	{
		dest.x++;
		if (ft_get_map_pos2(&game->map, &dest) == '0')
		{
			ft_set_map_pos2('0', &game->map, &dest);
			ft_draw_map_pos(&game->map, &game->gl, player->map_position);
		}
		else
			game->map.monster_direction = 1;
	}
	else if(game->map.monster_direction == 0)
	
	ft_draw_map_pos(&game->map, &game->gl, player->map_position);
	ft_draw_map_pos(&game->map, &game->gl, player->map_destination);
}
