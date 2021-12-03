/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:26:14 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/12 13:26:14 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/**
 * @brief retourne l'etat de toutes les touches du clavier
 * si la clé a la valeur 1, la touche est pressée
 * 
 * @return t_uint* 
 */
int	*ft_keys_state(void)
{
	static int	state[KEY_SIZE];

	return (state);
}

int	ft_in_key_down(int keycode, void *param)
{
	int	*keys;

	(void)param;
	keys = ft_keys_state();
	keys[keycode] = 1;
	if (keycode == KEY_A)
		keys[KEY_LEFT] = 1;
	if (keycode == KEY_D)
		keys[KEY_RIGHT] = 1;
	if (keycode == KEY_W)
		keys[KEY_UP] = 1;
	if (keycode == KEY_S)
		keys[KEY_DOWN] = 1;
	ft_input_keys(keys);
	return (1);
}

int	ft_in_key_up(int keycode, void *param)
{
	int	*keys;

	(void)param;
	keys = ft_keys_state();
	keys[keycode] = 0;
	if (keycode == KEY_A)
		keys[KEY_LEFT] = 0;
	if (keycode == KEY_D)
		keys[KEY_RIGHT] = 0;
	if (keycode == KEY_W)
		keys[KEY_UP] = 0;
	if (keycode == KEY_S)
		keys[KEY_DOWN] = 0;
	ft_input_keys(keys);
	return (1);
}

int	ft_input_keys(int *keys)
{
	t_game	*game;
	char	*msg;

	game = ft_game();
	if (keys[KEY_ESC])
	{
		mlx_destroy_window(game->gl.mlx_ptr, game->gl.win_ptr);
		ft_end_game(0);
	}
	if (keys[KEY_ENTER])
	{
		msg = "ENTER";
		mlx_clear_window(game->gl.mlx_ptr, game->gl.win_ptr);
		mlx_string_put(game->gl.mlx_ptr, game->gl.win_ptr, 10, 10, 255, msg);
	}
	return (1);
}
