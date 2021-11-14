/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/14 11:33:39 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "game.h"
#include "mlx.h"

int	ft_init_render(t_gl *gl)
{
	t_game	*game;

	game = ft_game();
	game->gl.mlx_ptr = mlx_init();
	if(!game->gl.mlx_ptr)
		return (0);
	game->gl.win_ptr = mlx_new_window(game->gl.mlx_ptr, 500, 500, "so_long");
	if(!game->gl.win_ptr)
		return (0);
	return (1);
}

void	ft_draw_image(void *i_ptr, t_gl *gl, t_pos src, t_pos dest, t_pos size)
{
	unsigned int	*ptr;
	t_image_info	ii;
	unsigned int	clr;
	t_pos			p;
	t_pos			put;

	ptr = mlx_get_data_addr(i_ptr, &(ii.bpp), &(ii.sl), &(ii.endian));
	ii.bytes = ii.bpp / 8;
	p.y = 0;
	while(p.y < size.y)
	{
		p.x = 0;
		while(p.x < size.x)
		{
			clr = ((unsigned int*)ptr)[((p.y + src.y) * 1200) + (p.x + src.x)];
			put.x = dest.x + p.x;
			put.y = dest.y + p.y;
			mlx_pixel_put(gl->mlx_ptr, gl->win_ptr, put.x, put.y, clr);
			p.x++;
		}
		p.y++;	
	}
}
