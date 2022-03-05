/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:42:10 by dthalman          #+#    #+#             */
/*   Updated: 2022/03/05 10:49:55 by dthalman         ###   ########.fr       */
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
		v3f_copy(v, copy);
	else
		v3f_clear(v);
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

/**
 * @brief met à zéro toute les valeurs d'un vecteur
 * 
 * @param vector 
 */
void	v3f_clear(t_v3f *vector)
{
	vector->x = 0;
	vector->y = 0;
	vector->z = 0;
}

/**
 * @brief copie les valeurs d'un vecteur dans un autre
 * 
 * @param to 
 * @param copy 
 */
void	v3f_copy(t_v3f *to, t_v3f *copy)
{
	to->x = copy->x;
	to->y = copy->y;
	to->z = copy->z;
}
