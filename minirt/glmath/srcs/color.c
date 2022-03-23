/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:33:13 by dthalman          #+#    #+#             */
/*   Updated: 2022/03/05 10:26:28 by dthalman         ###   ########.fr       */
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

/**
 * @brief Création d'une couleur avec un entier
 * 
 * @param color 
 * @return t_color* 
 */
t_color	*color_create_int(int color)
{
	t_color	*c;

	c = malloc(sizeof(t_color));
	c->b = (color & 0xFF) / 255.0;
	c->g = ((color >> 8) & 0xFF) / 255.0;
	c->r = ((color >> 16) & 0xFF) / 255.0;
	c->a = ((color >> 24) & 0xFF) / 255.0;
	return (c);
}

/**
 * @brief retourne la valeur représenté par la couleur
 * en entier
 * 
 * @param color 
 * @return int 
 */
int	color_int(t_color *color)
{
	int	c;

	c = 0;
	c += (int)(color->a * 255.0) & 0xFF;
	c = c << 8;
	c += (int)(color->r * 255.0) & 0xFF;
	c = c << 8;
	c += (int)(color->g * 255.0) & 0xFF;
	c = c << 8;
	c += (int)(color->b * 255.0) & 0xFF;
	return (c);
}

/**
 * @brief converti un vecteur en couleur
 * 
 * @param color 
 * @param v 
 */
void	cpy_vector_to_color(t_color *color, t_v3f *v)
{
	color->r = v->x;
	color->g = v->y;
	color->b = v->z;
	color->a = v->w;
}
