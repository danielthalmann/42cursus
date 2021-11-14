/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 06:39:26 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/14 19:31:44 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "utils.h"
#include "render.h"

void	ft_load_image(char *f)
{
	t_game			*game;
	t_size			s;
	t_translation	tr;
	void			*img_ptr;
	void			*(*fn)();

	fn = &mlx_png_file_to_image;
	s.w = 0;
	s.h = 0;
	game = ft_game();
	img_ptr = (*fn)(game->gl.mlx_ptr, f, (int *)&(s.w), (int *)&(s.h));
	tr.dest.x = 0;
	tr.dest.y = 0;
	tr.src.x = 0;
	tr.src.y = 0;
	tr.size.x = 100;
	tr.size.y = 100;
	ft_draw_image(img_ptr, &(game->gl), tr);
}
