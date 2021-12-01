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
# include "libft.h"
# include "mlx.h"
# include "map.h"
# include "utils.h"
# include "input.h"
# include "player.h"
# include "sprite.h"
# define MLX_EVT_KEYDN 2
# define MLX_EVT_KEYUP 3
# define MLX_EVT_DESTROY 17

int		ft_game_loop(void);
int		ft_init_game(void);
void	ft_end_game(void);
t_game	*ft_game(void);
#endif
