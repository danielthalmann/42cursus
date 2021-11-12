/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 06:39:26 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/12 07:07:37 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

void    ft_load_image(char *filename)
{
    t_game  *game;
    t_size  size;
    void    *img;

    size.width = 0;
    size.height = 0;
    game = ft_game();
    img = mlx_png_file_to_image(game->gl.mlx_ptr, filename, (int *)&(size.width), (int *)&(size.height));
    mlx_put_image_to_window  (game->gl.mlx_ptr, game->gl.win_ptr, img, 2, 2);
}