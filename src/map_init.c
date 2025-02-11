/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:19:31 by pemirand          #+#    #+#             */
/*   Updated: 2024/10/07 12:06:59 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*init_map_without_size(void)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		error_message(NULL, "Map Allocation Problem!\n");
	map->p_pos = (t_position *) malloc(sizeof(t_position));
	map->e_pos = (t_position *) malloc(sizeof(t_position));
	if (!map->p_pos || !map->e_pos)
	{
		destroy_map(map);
		error_message(NULL, "Map Player Position Allocation Problem!\n");
	}
	map->map_matrix = NULL;
	map->n_collectibles = 0;
	map->n_cols = 0;
	map->n_exits = 0;
	map->n_players = 0;
	map->n_rows = 0;
	map->p_pos->x = 0;
	map->p_pos->y = 0;
	return (map);
}

int	init_map_matrix(t_map **map, int n_rows, int n_cols)
{
	(*map)->map_matrix = (char **) malloc(sizeof(char *) * n_rows);
	while (n_rows-- > 0)
	{
		(*map)->map_matrix[n_rows] = \
					(char *) malloc(sizeof(char) * (n_cols + 1));
		(*map)->map_matrix[n_rows][n_cols] = '\0';
	}
	if ((*map)->map_matrix)
		return (1);
	return (0);
}
