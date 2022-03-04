/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:42:10 by dthalman          #+#    #+#             */
/*   Updated: 2022/02/28 10:42:10 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glmath.h"

/**
 * @brief Création d'un nouveau vecteur
 * 
 * @param copy 
 * @return t_v3f* 
 */
t_v3f	*v3f_create(t_v3f *copy)
{
	t_v3f	*v;

	v = malloc(sizeof(t_v3f));
	if (copy != NULL)
	{
		v->x = copy->x;
		v->y = copy->y;
		v->z = copy->z;
	}
	else
	{
		v->x = 0;
		v->y = 0;
		v->z = 0;
	}
	return (v);
}

/**
 * @brief Addition de deux vecteurs
 * 
 * @param vector 
 * @param add 
 */
void	v3f_add(t_v3f *vector, t_v3f *add)
{
	vector->x += add->x;
	vector->y += add->y;
	vector->z += add->z;
}

/**
 * @brief Soustraction de deux vecteurs
 * 
 * @param vector 
 * @param sub 
 */
void	v3f_sub(t_v3f *vector, t_v3f *sub)
{
	vector->x -= sub->x;
	vector->y -= sub->y;
	vector->z -= sub->z;
}

/**
 * @brief Retourne un vecteur à partir du point (0,0,0) d'une valeur de 1
 *  exemple, avec le vecteur (2,0,0) on obtiendra (1,0,0)
 *
 * @param v 
 */
void	v3f_normalize(t_v3f *vector)
{
	float	magnitude;

	magnitude = sqrt((vector->x * vector->x)
			+ (vector->y * vector->y) + (vector->z * vector->z));
	vector->x /= magnitude;
	vector->y /= magnitude;
	vector->z /= magnitude;
}

/**
 * @brief Mutliplication de deux vecteurs
 * 
 * @param vector 
 * @param add 
 */
void	v3f_multi(t_v3f *vector, t_v3f *multi)
{
	vector->x *= multi->x;
	vector->y *= multi->y;
	vector->z *= multi->z;
}

/**
 * @brief Mutliplication d'un vecteurs par une valeur
 * 
 * @param vector 
 * @param v 
 */
void	v3f_multi_v(t_v3f *vector, float value)
{
	vector->x *= value;
	vector->y *= value;
	vector->z *= value;
}
