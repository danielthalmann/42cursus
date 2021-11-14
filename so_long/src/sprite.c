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

void	ft_load_image(char *filename)
{
	t_game	*game;
	t_size	size;
	void	*img_ptr;

	size.width = 0;
	size.height = 0;
	game = ft_game();
	img_ptr = mlx_png_file_to_image(game->gl.mlx_ptr, filename, 
		(int *)&(size.width), (int *)&(size.height));

	t_pos src;
	t_pos dest;
	t_pos isize;

	dest.x = 0;
	dest.y = 0;

	src.x = 0;
	src.y = 0;

	isize.x = 100;
	isize.y = 100;

	ft_draw_image(img_ptr, &(game->gl), src, dest, isize);

}
