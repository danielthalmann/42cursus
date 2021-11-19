/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/19 06:28:08 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# define PLAYER_SPRITE_WIDTH 60
# define PLAYER_SPRITE_HEIGHT 76
# define PLAYER_ANIM_WAIT 0
# include "utils.h"
# include "game.h"
typedef struct s_player
{
	int		state;
	t_pos	position;
	void	*img_ptr;
	int		speed_anim;
	int		anim_last_time;
	int		anim_index;
	int		speed;
	int		speed_last_time;
	int		anim_limit[5];
}	t_player;
void	ft_draw_player_pos(t_player *player, t_gl *gl);
int		ft_init_player(t_game *game);
void	ft_player_load_sprite(char *f, t_game *game);
void	ft_update_player(t_player *player, t_game *game, int time);
#endif