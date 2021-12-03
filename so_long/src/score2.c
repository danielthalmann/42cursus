/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/03 14:01:12 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"
#include "render.h"
#include "map.h"
#include "libft.h"
#include "mlx.h"
#include "score.h"

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

void	ft_draw_background(t_score *score, t_gl *gl)
{
	t_translation	tr;

	ft_memset((void *)&tr, 0, sizeof(tr));
	tr.dest = score->position;
	tr.dest.x -= 2 * SCORE_SPRITE_WIDTH;
	tr.size.x = 3 * SCORE_SPRITE_WIDTH;
	tr.size.y = SCORE_SPRITE_HEIGHT;
	ft_draw_color(0xEE002222, gl, tr);
}

void	ft_draw_score(t_score *score, t_game *game, t_gl *gl)
{
	t_translation	tr;
	t_uint			n;
	t_uint			unit;

	ft_draw_map_pos_xy(&game->map, &game->gl, 0, 0);
	ft_draw_map_pos_xy(&game->map, &game->gl, 1, 0);
	ft_draw_background(&game->score, &game->gl);
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
