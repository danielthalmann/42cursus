/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/24 10:37:10 by dthalman         ###   ########.fr       */
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
		ft_update_player_horizontal(player, game, time);
		ft_update_player_vertical(player, game, time);
	}
	else
	{
		ft_update_player_pos(player, game);
	}
}

void	ft_update_player_horizontal(t_player *player, t_game *game, int time)
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

void	ft_update_player_vertical(t_player *player, t_game *game, int time)
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
