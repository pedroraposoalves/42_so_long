/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:04:32 by pemirand          #+#    #+#             */
/*   Updated: 2024/10/07 16:16:13 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_filename(char *name)
{
	size_t	len;
	char	*tmp;
	int		res;

	len = ft_strlen(name);
	if (len < 4)
		return (1);
	tmp = ft_substr(name, (unsigned int)(len - 4), 4);
	res = ft_strncmp(tmp, ".ber", 4);
	free(tmp);
	return (res);
}

int	valid_map_size(int fd, t_map **map)
{
	unsigned int	len;
	char			*s;

	s = get_next_line(fd);
	(*map)->n_rows = 0;
	while (s)
	{
		len = (unsigned int) ft_strlen(s);
		if ((*map)->n_rows == 0)
		{
			if (s[len - 1] != '\n')
				return (free(s), 0);
			(*map)->n_cols = len - 1;
		}
		else if (!((len - 1 == (*map)->n_cols && s[len - 1] == '\n')
				|| (len == (*map)->n_cols && s[len - 1] != '\n')))
			return (free(s), 0);
		free(s);
		s = get_next_line(fd);
		(*map)->n_rows++;
	}
	return (1);
}

char	**clone_map_matrix(t_map *map)
{
	char				**matrix;
	unsigned int		row;
	unsigned int		col;

	matrix = (char **) malloc(sizeof(char *) * map->n_rows);
	if (!matrix)
		return (NULL);
	row = 0;
	while (row < map->n_rows)
	{
		col = 0;
		matrix[row] = (char *) malloc(sizeof(char) * map->n_cols + 1);
		if (!matrix[row])
			return (destroy_matrix(matrix, row), NULL);
		matrix[row][map->n_cols] = '\0';
		while (col++ < map->n_cols)
			matrix[row][col - 1] = map->map_matrix[row][col - 1];
		row++;
	}
	return (matrix);
}

int	valid_path(t_map *map, t_position *pos, char **matrix)
{
	static unsigned int	collectibles = 0;
	static int			exit_founded = 0;

	if (!map || !map->map_matrix)
		return (0);
	if (matrix[pos->y][pos->x] == WALL)
		return (0);
	else if (matrix[pos->y][pos->x] == COLLECTIBLE)
		collectibles++;
	else if (matrix[pos->y][pos->x] == EXIT)
		exit_founded = 1;
	matrix[pos->y][pos->x] = WALL;
	valid_path(map, &(t_position){pos->x + 1, pos->y}, matrix);
	valid_path(map, &(t_position){pos->x - 1, pos->y}, matrix);
	valid_path(map, &(t_position){pos->x, pos->y + 1}, matrix);
	valid_path(map, &(t_position){pos->x, pos->y - 1}, matrix);
	return (collectibles == map->n_collectibles && exit_founded);
}

void	valid_textures(void)
{
	if (open(EMPTY_SPACE_IMG, O_RDONLY) == -1)
		error_message(NULL, "Invalid textures\n");
	if (open(WALL_IMG, O_RDONLY) == -1)
		error_message(NULL, "Invalid textures\n");
	if (open(COLLECTIBLE_IMG, O_RDONLY) == -1)
		error_message(NULL, "Invalid textures\n");
	if (open(PLAYER_IMG, O_RDONLY) == -1)
		error_message(NULL, "Invalid textures\n");
	if (open(EXIT_IMG, O_RDONLY) == -1)
		error_message(NULL, "Invalid textures\n");
}

// void	print_map_matrix(t_map *map)
// {
// 	unsigned int	x;
// 	unsigned int	y;

// 	x = 0;
// 	while (x < map->n_rows)
// 	{
// 		y = 0;
// 		while (y <= map->n_cols)
// 			ft_printf("%c", map->map_matrix[x][y++]);
// 		x++;
// 		ft_printf("\n");
// 	}
// 	ft_printf("Rows: %d\n", map->n_rows);
// 	ft_printf("Cols: %d\n", map->n_cols);
// 	ft_printf("Players: %d\n", map->n_players);
// 	ft_printf("Collectibles: %d\n", map->n_collectibles);
// 	ft_printf("Exits: %d\n", map->n_exits);
// 	ft_printf("P Position: x -> %d y -> %d\n", map->p_pos->x, map->p_pos->y);
// }
