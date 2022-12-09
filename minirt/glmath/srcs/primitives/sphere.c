/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:26:45 by dthalman          #+#    #+#             */
/*   Updated: 2022/03/23 08:10:44 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glmath.h"

int	sphere_intersect(t_ray *ray, t_sphere *sphere)
{
	t_v3f	dist;
	float	D;
	float	R;

	v3f_copy(&dist, &(sphere->origin));
	v3f_sub(&dist, &ray->origin);
	v3f_multi(&dist, &ray->direction);
	D = dist.x * dist.x + dist.y * dist.y + dist.z * dist.z;
	R = sphere->rayon * sphere->rayon * sphere->rayon; 
	if (R - D < 0.0f) 
    	return (1); 
	return (0);
}
 
void	computeColorNormal(t_ray *ray, float dist, t_color *c, t_v3f *normal)
{
	(void)ray;
	(void)dist;
	(void)c;
	(void)normal;
	return ;
}
