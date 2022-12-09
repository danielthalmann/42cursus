/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/03 13:50:40 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "utils.h"

typedef struct s_image_info
{
	int	bpp;
	int	sl;
	int	endian;
	int	bytes;
}	t_image_info;
int		ft_init_render(t_gl *gl, int width, int height);
void	ft_draw_image(void *i_ptr, t_gl *gl, t_translation tr);
void	ft_draw_color(unsigned int clr, t_gl *gl, t_translation tr);

#endif
