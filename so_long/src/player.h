/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/17 18:11:46 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "utils.h"
# define PLAYER_SPRITE_WIDTH 60
# define PLAYER_SPRITE_HEIGHT 76

typedef struct s_player
{
	int		state;
	t_pos	position;
	void	*img_ptr;
}	t_player;
void	ft_player_load_sprite(char *f);
void	ft_draw_player_pos(t_player *player, t_gl *gl);
#endif