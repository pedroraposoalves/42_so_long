/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:06:36 by pemirand          #+#    #+#             */
/*   Updated: 2024/10/02 12:07:50 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_keypress(int keysym, t_game *game)
{
	if (keysym == ESC_KEY)
		exit_sucess(game);
	else if (keysym == W_KEY || keysym == UP_KEY)
		movement(game, 0, -1);
	else if (keysym == S_KEY || keysym == DOWN_KEY)
		movement(game, 0, 1);
	else if (keysym == A_KEY || keysym == LEFT_KEY)
		movement(game, -1, 0);
	else if (keysym == D_KEY || keysym == RIGHT_KEY)
		movement(game, 1, 0);
	return (0);
}

int	valid_movement(t_map *map, int x, int y)
{
	if (map->map_matrix[y][x] == EMPTY_SPACE)
		return (1);
	else if (map->map_matrix[y][x] == COLLECTIBLE)
		return (2);
	else if (map->map_matrix[y][x] == EXIT && map->n_collectibles != 0)
		return (8);
	else if (map->map_matrix[y][x] == EXIT && map->n_collectibles == 0)
		return (9);
	return (0);
}

void	movement(t_game *game, int move_x, int move_y)
{
	unsigned int	x;
	unsigned int	y;
	int				movement;

	x = game->map->p_pos->x;
	y = game->map->p_pos->y;
	movement = valid_movement(game->map, x + move_x, y + move_y);
	if (movement == 1 || movement == 2 || movement == 8 || movement == 9)
	{
		if (game->map->e_pos->x == x && game->map->e_pos->y == y)
			game->map->map_matrix[y][x] = EXIT;
		else
			game->map->map_matrix[y][x] = EMPTY_SPACE;
		game->map->p_pos->x = x + move_x;
		game->map->p_pos->y = y + move_y;
		game->map->map_matrix[game->map->p_pos->y] \
							[game->map->p_pos->x] = PLAYER;
		game->n_movements++;
		ft_printf("Number os movements: %d\n", game->n_movements);
		if (movement == 2)
			game->map->n_collectibles--;
		else if (movement == 9)
			exit_sucess(game);
	}
}
