/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/20 09:00:47 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# define PLAYER_SPRITE_WIDTH 60
# define PLAYER_SPRITE_HEIGHT 65
# define PLAYER_ANIM_WAIT_F 0
# define PLAYER_ANIM_WAIT_L 1
# define PLAYER_ANIM_WAIT_B 2
# define PLAYER_ANIM_WAIT_R 3
# define PLAYER_ANIM_WALK_F 4
# define PLAYER_ANIM_WALK_L 5
# define PLAYER_ANIM_WALK_B 6
# define PLAYER_ANIM_WALK_R 7
# include "utils.h"
# include "game.h"

void	ft_draw_player_pos(t_player *player, t_gl *gl);
int		ft_init_player(t_game *game);
void	ft_player_load_sprite(char *f, t_game *game);
void	ft_update_player(t_player *player, t_game *game, int time);
#endif