/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:33:34 by pemirand          #+#    #+#             */
/*   Updated: 2024/10/07 12:12:14 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*init_game(t_map *map)
{
	t_game	*game;
	char	**matrix;
	int		valid;

	if (!map)
		return (NULL);
	matrix = clone_map_matrix(map);
	valid = valid_path(map, map->p_pos, matrix);
	destroy_matrix(matrix, map->n_rows);
	if (valid == 0)
	{
		destroy_map(map);
		error_message(NULL, "Map without a valid path\n");
	}
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (destroy_map(map), NULL);
	game->map = map;
	game->n_movements = 0;
	return (game);
}

void	init_mlx_textures(t_game *game)
{
	int	img_width;
	int	img_height;

	img_width = IMG_SIZE;
	img_height = IMG_SIZE;
	game->textures[EMPTY_SPACE_ID] = mlx_xpm_file_to_image(game->mlx, \
									EMPTY_SPACE_IMG, &img_width, &img_height);
	game->textures[WALL_ID] = mlx_xpm_file_to_image(game->mlx, \
									WALL_IMG, &img_width, &img_height);
	game->textures[COLLECTIBLE_ID] = mlx_xpm_file_to_image(game->mlx, \
									COLLECTIBLE_IMG, &img_width, &img_height);
	game->textures[PLAYER_ID] = mlx_xpm_file_to_image(game->mlx, \
									PLAYER_IMG, &img_width, &img_height);
	game->textures[EXIT_ID] = mlx_xpm_file_to_image(game->mlx, \
									EXIT_IMG, &img_width, &img_height);
}

void	init_mlx_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_message(game, "Problem initing MLX");
	game->win = mlx_new_window (game->mlx, game->map->n_cols * IMG_SIZE, \
								game->map->n_rows * IMG_SIZE, WIN_NAME);
	if (!game->win)
		error_message(game, "Problem initing WIN");
	init_mlx_textures(game);
	mlx_loop_hook(game->mlx, &render_game, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, &on_keypress, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &exit_sucess, game);
	mlx_loop(game->mlx);
}

void	render_icon(t_game *game, int x, int y, char c)
{
	if (c == WALL)
		mlx_put_image_to_window (game->mlx, game->win, \
					game->textures[WALL_ID], x * IMG_SIZE, y * IMG_SIZE);
	else if (c == EMPTY_SPACE)
		mlx_put_image_to_window (game->mlx, game->win, \
					game->textures[EMPTY_SPACE_ID], x * IMG_SIZE, y * IMG_SIZE);
	else if (c == COLLECTIBLE)
		mlx_put_image_to_window (game->mlx, game->win, \
					game->textures[COLLECTIBLE_ID], x * IMG_SIZE, y * IMG_SIZE);
	else if (c == EXIT)
		mlx_put_image_to_window (game->mlx, game->win, \
					game->textures[EXIT_ID], x * IMG_SIZE, y * IMG_SIZE);
	else if (c == PLAYER)
		mlx_put_image_to_window (game->mlx, game->win, \
					game->textures[PLAYER_ID], x * IMG_SIZE, y * IMG_SIZE);
}

int	render_game(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < game->map->n_rows)
	{
		x = 0;
		while (x < game->map->n_cols)
		{
			render_icon(game, x, y, game->map->map_matrix[y][x]);
			x++;
		}
		y++;
	}
	return (0);
}
