/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:36:40 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/12 02:17:38 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "map.h"
#include "render.h"

/**
 * @brief depart de mon programme
 * 
 * @param argc nombre de ...
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	t_game	*game;
	int		w;
	int		h;

	if (argc != 2)
	{
		ft_printf("Nombre d'argument incorrect\n");
		return (1);
	}
	game = ft_game();
	if (!ft_load_map(argv[1], &(game->map)))
	{
		ft_printf("Erreur a l'ouverture du fichier (%s).\n", argv[1]);
		return (1);
	}
	w = game->map.size.w * MAP_SPRITE_WIDTH;
	h = game->map.size.h * MAP_SPRITE_HEIGHT;
	if (!ft_init_render(&(game->gl), w, h))
	{
		ft_free_map(&(game->map));
		ft_printf("Erreur lors de l'init du gl.\n");
		return (1);
	}
	ft_init_game();
	return (0);
}
