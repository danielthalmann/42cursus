/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:20:02 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/12 13:20:02 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "mlx.h"
# include "map.h"
# include "libft.h"
# include "utils.h"
# include "input.h"
# include "player.h"
# include "sprite.h"
# define MLX_EVT_KEYDN 2
# define MLX_EVT_KEYUP 3

typedef struct s_game
{
	int			is_init;
	t_gl		gl;
	t_map		map;
	t_player	player;
}	t_game;
int		ft_game_loop(void);
int		ft_init_game(void);
void	ft_end_game(void);
t_game	*ft_game(void);
#endif