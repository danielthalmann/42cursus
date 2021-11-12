/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:21:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/12 06:44:31 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "utils.h"
# include "game.h"
typedef struct s_map
{
	t_size	size;
	t_uint	**coord;
}	t_map;
#endif