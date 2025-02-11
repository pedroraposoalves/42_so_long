/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:18:07 by pemirand          #+#    #+#             */
/*   Updated: 2024/10/02 11:59:02 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_matrix(char **matrix, unsigned int n_rows)
{
	unsigned int	i;

	if (matrix)
	{
		i = 0;
		while (i++ < n_rows)
			if (matrix[i - 1])
				free(matrix[i - 1]);
		free(matrix);
	}
}

void	destroy_map(t_map *map)
{
	if (map->map_matrix)
		destroy_matrix(map->map_matrix, map->n_rows);
	if (map->p_pos)
		free(map->p_pos);
	if (map->e_pos)
		free(map->e_pos);
	if (map)
		free(map);
}

void	destroy_game(t_game *game)
{
	int	i;

	i = 0;
	if (game)
	{
		if (game->map)
			destroy_map(game->map);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		while (i++ < N_TEXTURES)
			if (game->textures[i - 1])
				mlx_destroy_image(game->mlx, game->textures[i - 1]);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
	}
}

void	error_message(t_game *game, char *message)
{
	destroy_game(game);
	ft_printf("Error\n%s", message);
	exit(EXIT_FAILURE);
}

int	exit_sucess(t_game *game)
{
	destroy_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
