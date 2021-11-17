/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 06:39:26 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/17 11:27:08 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H
# include "game.h"

void	ft_load_image(char *filename);
void	ft_draw_image(void *img_ptr, t_gl *gl, t_position src, t_position dest, t_position size);
#endif