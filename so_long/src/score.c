/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/01 15:15:36 by dthalman         ###   ########.fr       */
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
	ft_score_load_sprite("media/number.xpm", game);
	return (1);
}

/**
 * @brief Charge le sprite pour le joueur
 * 
 * @param f 
 */
void	ft_score_load_sprite(char *f, t_game *game)
{
	t_size	s;
	void	*(*fn)();
	int		*w;
	int		*h;

	w = (int *)&(s.w);
	h = (int *)&(s.h);
	fn = &mlx_xpm_file_to_image;
	game->score.img_ptr = (*fn)(game->gl.mlx_ptr, f, w, h);
	if (!game->score.img_ptr)
		ft_end_game();
}

void	ft_free_score(t_score *score)
{
	t_game	*game;

	game = ft_game();
	mlx_destroy_image(game->gl.mlx_ptr, score->img_ptr);
}

void	ft_draw_score_init(t_score *score, t_gl *gl)
{
	t_translation	tr;
	t_uint			n;

	ft_memset((void *)&tr, 0, sizeof(tr));
	tr.dest = score->position;
	tr.size.x = SCORE_SPRITE_WIDTH;
	tr.size.y = SCORE_SPRITE_HEIGHT;
	n = 0;
	while (n < 3)
	{
		ft_draw_image(score->img_ptr, gl, tr);
		tr.dest.x -= SCORE_SPRITE_WIDTH;
		n++;
	}
}

void	ft_draw_score(t_score *score, t_game *game, t_gl *gl)
{
	t_translation	tr;
	t_uint			n;
	t_uint			unit;

	ft_memset((void *)&tr, 0, sizeof(tr));
	n = game->nb_move;
	tr.dest = score->position;
	tr.size.x = SCORE_SPRITE_WIDTH;
	tr.size.y = SCORE_SPRITE_HEIGHT;
	while (n > 0)
	{
		unit = n % 10;
		n = n / 10;
		tr.src.x = (unit + 1) * 25;
		tr.src.y = 0;
		ft_draw_image(score->img_ptr, gl, tr);
		tr.dest.x -= SCORE_SPRITE_WIDTH;
	}
}
