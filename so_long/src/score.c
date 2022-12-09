/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/03 14:01:33 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"
#include "render.h"
#include "map.h"
#include "libft.h"
#include "mlx.h"
#include "score.h"

/**
 * @brief initialise le score
 * 
 * @param game 
 * @return int 
 */
int	ft_init_score(t_game *game)
{
	game->score.position.x = 85;
	game->score.position.y = 10;
	if (!ft_score_load_sprite("media/number.xpm", game))
		ft_end_game("Le sprite du score n'a pas pu être chargé.");
	return (1);
}

/**
 * @brief Charge le sprite pour le joueur
 * 
 * @param f 
 */
void	*ft_score_load_sprite(char *f, t_game *game)
{
	t_size	s;
	void	*(*fn)();
	int		*w;
	int		*h;

	w = (int *)&(s.w);
	h = (int *)&(s.h);
	fn = &mlx_xpm_file_to_image;
	game->score.img_ptr = (*fn)(game->gl.mlx_ptr, f, w, h);
	return (game->score.img_ptr);
}

void	ft_free_score(t_score *score)
{
	t_game	*game;

	game = ft_game();
	if (score->img_ptr)
		mlx_destroy_image(game->gl.mlx_ptr, score->img_ptr);
}
