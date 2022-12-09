/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/03 13:50:31 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "game.h"
#include "mlx.h"

/**
 * @brief initialise la librairie graphique
 * 
 * @param gl 
 * @param width 
 * @param height 
 * @return int 
 */
int	ft_init_render(t_gl *gl, int width, int height)
{
	gl->mlx_ptr = mlx_init();
	if (!gl->mlx_ptr)
		return (0);
	gl->win_ptr = mlx_new_window(gl->mlx_ptr, width, height, "so_long");
	if (!gl->win_ptr)
		return (0);
	return (1);
}

/**
 * @brief Dessine une partie d'une image sur l'écran
 * une couleur 0xFF000000 est une couleur transparente
 * 
 * @param i_ptr pointeur sur l'image
 * @param gl 	pointeur sur la librairie graphique
 * @param tr 	structure de la translation
 */
void	ft_draw_image(void *i_ptr, t_gl *gl, t_translation tr)
{
	t_uint			*ptr;
	t_image_info	ii;
	unsigned int	clr;
	t_pos			p;
	t_pos			put;

	ptr = (t_uint *)mlx_get_data_addr(i_ptr, &(ii.bpp), &(ii.sl), &(ii.endian));
	ii.bytes = ii.bpp / 8;
	p.y = 0;
	while (p.y < tr.size.y)
	{
		p.x = 0;
		while (p.x < tr.size.x)
		{
			put.x = tr.src.x + p.x;
			put.y = tr.src.y + p.y;
			clr = ptr[((put.y) * ii.sl / ii.bytes) + (put.x)];
			put.x = tr.dest.x + p.x;
			put.y = tr.dest.y + p.y;
			if (clr != 0xFF000000)
				mlx_pixel_put(gl->mlx_ptr, gl->win_ptr, put.x, put.y, clr);
			p.x++;
		}
		p.y++;
	}
}

void	ft_draw_color(unsigned int clr, t_gl *gl, t_translation tr)
{
	t_pos			p;
	t_pos			put;

	p.y = 0;
	while (p.y < tr.size.y)
	{
		p.x = 0;
		while (p.x < tr.size.x)
		{
			put.x = tr.dest.x + p.x;
			put.y = tr.dest.y + p.y;
			if (clr != 0xFF000000)
				mlx_pixel_put(gl->mlx_ptr, gl->win_ptr, put.x, put.y, clr);
			p.x++;
		}
		p.y++;
	}
}
