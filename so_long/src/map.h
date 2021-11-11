/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:21:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/11 23:51:46 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "utils.h"

typedef struct s_map
{
	t_size	size;
	t_uint	**coord;
}	t_map;
#endif