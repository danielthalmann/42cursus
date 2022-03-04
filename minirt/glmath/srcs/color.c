/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:33:13 by dthalman          #+#    #+#             */
/*   Updated: 2022/02/28 19:33:13 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glmath.h"

/**
 * @brief Création d'un nouveau vecteur
 * 
 * @param copy 
 * @return color* 
 */
t_color	*color_create(t_color *copy)
{
	t_color	*c;

	c = malloc(sizeof(t_color));
	if (copy != NULL)
	{
		c->a = copy->a;
		c->r = copy->r;
		c->g = copy->g;
		c->b = copy->b;
	}
	else
	{
		c->a = 0;
		c->r = 0;
		c->g = 0;
		c->b = 0;
	}
	return (c);
}

t_color	*color_create_int(int color)
{
	t_color	*c;

	c = malloc(sizeof(t_color));
	c->b = color & 0xFF;
	c->g = (color >> 8) & 0xFF;
	c->r = (color >> 16) & 0xFF;
	c->a = (color >> 24) & 0xFF;
	return (c);
}

int	color_int(t_color *color)
{
	int	c;

	c = 0;
	c += (color->a) & 0xFF;
	c = c << 8;
	c += (color->r) & 0xFF;
	c = c << 8;
	c += (color->g) & 0xFF;
	c = c << 8;
	c += (color->b) & 0xFF;
	return (c);
}
