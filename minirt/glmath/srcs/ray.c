/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 10:25:03 by dthalman          #+#    #+#             */
/*   Updated: 2022/03/05 11:02:59 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glmath.h"

t_ray	*ray_create(t_ray *copy)
{
	t_ray	*r;

	r = malloc(sizeof(t_ray));
	if (copy != NULL)
	{
		v3f_copy(&r->direction, &copy->direction);
		v3f_copy(&r->origin, &copy->origin);
	}
	else
	{
		v3f_clear(&r->direction);
		v3f_clear(&r->origin);
	}
	return (r);
}

/**
 * @brief retourne un nouveau vecteur contenant les coordonnées à la pos du
 * rayon.
 * 
 * @param pos 
 * @param ray 
 * @return t_v3f* 
 */
t_v3f	*ray_at(float pos, t_ray *ray)
{
	t_v3f	*at;
	t_v3f	*multi;

	at = v3f_create(&ray->origin);
	multi = v3f_create(&ray->direction);
	v3f_multi_v(multi, pos);
	v3f_add(at, multi);
	free(multi);
	return (at);
}

t_color	*ray_color(t_ray *r)
{
	(void)r;
	/*
	vec3 unit_direction = unit_vector(r.direction());
	auto t = 0.5*(unit_direction.y() + 1.0);
	return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
	*/
	return (0);
}

/**
 * @brief initialise à zéro les valeurs du rayon
 * 
 * @param r 
 */
void	ray_clear(t_ray *r)
{
	v3f_clear(&r->direction);
	v3f_clear(&r->origin);
}
