/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:21:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/20 12:31:55 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map.h"
#include "render.h"
#include "map_utils.h"

/**
 * @brief Charge un fichier contenant les données d'une carte
 * 
 * @param filename 
 * @param map 
 * @return int 
 */
int	ft_load_map(char *filename, t_map *map)
{
	int		fd;
	char	*l;
	t_list	*lines;
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	else
	{
		lines = 0;
		l = get_next_line(fd);
		while (l)
		{
			ft_lstadd_back(&lines, ft_lstnew(l));
			l = get_next_line(fd);
		}
	}
	close(fd);
	ret = ft_load_list_map(lines, map);
	ft_free_list_map(lines);
	return (ret);
}

/**
 * @brief Charge dans la structure de la carte les lignes du fichier
 * 
 * @param list 
 * @param map 
 * @return int 
 */
int	ft_load_list_map(t_list *list, t_map *map)
{
	t_uint	x;
	t_uint	y;

	if (!list)
		return (0);
	map->size.h = ft_lstsize(list);
	map->size.w = ft_map_count_width(list->content);
	map->coord = ft_calloc(map->size.h * map->size.w, sizeof(t_uint));
	map->img_ptr = 0;
	y = -1;
	while (++y < map->size.h)
	{
		x = -1;
		if (ft_map_count_width(list->content) != map->size.w)
			return (0);
		while (++x < map->size.w)
			ft_set_map_pos(((char *)(list->content))[x], map, x, y);
		list = list->next;
	}
	return (1);
}

/**
 * @brief libère la mémoire de toute la liste
 * 
 * @param list 
 */
void	ft_free_list_map(t_list *list)
{
	t_list	*to_free;

	while (list)
	{
		free(list->content);
		to_free = list;
		list = list->next;
		free(to_free);
	}
}

/**
 * @brief Libere de la memoire la carte
 * 
 * @param map 
 */
void	ft_free_map(t_map *map)
{
	t_game	*game;

	free(map->coord);
	if (map->img_ptr)
	{
		game = ft_game();
		mlx_destroy_image(game->gl.mlx_ptr, map->img_ptr);
	}
}

/**
 * @brief compte la lagueur de la carte
 * 
 * @param s 
 * @return t_uint 
 */
t_uint	ft_map_count_width(char *s)
{
	unsigned int	c;

	c = 0;
	while (*s && *s != '\n')
	{
		c++;
		s++;
	}
	return (c);
}

/**
 * @brief Charge dans la map le sprite pour la map
 * 
 * @param f 
 */
void	ft_map_load_sprite(char *f)
{
	t_game	*game;
	void	*(*fn)();
	int		w;
	int		h;

	fn = &mlx_png_file_to_image;
	game = ft_game();
	game->map.img_ptr = (*fn)(game->gl.mlx_ptr, f, &w, &h);
}

/**
 * @brief Dessine a l'écran la carte
 * 
 * @param map 
 */
void	ft_draw_map(t_map *map)
{
	t_game	*game;
	t_uint	x;
	t_uint	y;

	game = ft_game();
	y = -1;
	while (++y < map->size.h)
	{
		x = -1;
		while (++x < map->size.w)
		{
			ft_draw_map_pos(map, &(game->gl), x, y);
		}
	}
}

void	ft_draw_map_pos(t_map *map, t_gl *gl, t_uint x, t_uint y)
{
	t_translation	tr;
	char			c;

	tr.dest.x = 0;
	tr.dest.y = 0;
	tr.src.x = 0;
	tr.src.y = 0;
	tr.size.x = MAP_SPRITE_WIDTH;
	tr.size.y = MAP_SPRITE_HEIGHT;
	c = (char)ft_get_map_pos(map, x, y);
	if (ft_strchr("0PEC", c))
		tr.src.x = 0;
	else
		tr.src.x = MAP_SPRITE_WIDTH;
	tr.dest.x = MAP_SPRITE_WIDTH * x;
	tr.dest.y = MAP_SPRITE_HEIGHT * y;
	ft_draw_image(map->img_ptr, gl, tr);
}
