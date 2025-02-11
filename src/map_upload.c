/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_upload.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:19:31 by pemirand          #+#    #+#             */
/*   Updated: 2024/10/02 12:19:43 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	updload_map_matrix(t_map **map, int fd)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	n_rows;
	unsigned int	n_cols;
	char			*s;

	y = 0;
	n_rows = (*map)->n_rows;
	n_cols = (*map)->n_cols;
	s = get_next_line(fd);
	while (s && y++ < n_rows)
	{
		x = 0;
		while (x++ < n_cols)
		{
			if (upload_map_pos(map, x - 1, y - 1, s[x - 1]) == 0)
				return (free(s), 0);
		}
		free(s);
		s = get_next_line(fd);
	}
	if ((*map)->n_players > 0 && (*map)->n_exits > 0
		&& (*map)->n_collectibles > 0)
		return (1);
	return (0);
}

void	update_position(t_position *position, unsigned int x, unsigned int y)
{
	if (position)
	{
		position->x = x;
		position->y = y;
	}
}

int	upload_map_pos(t_map **map, unsigned int x, unsigned int y, char c)
{
	if (ft_strrchr("10CPE", (int) c) != NULL)
	{
		if (c != '1' && (y == 0 || y == (*map)->n_rows - 1 \
						|| x == 0 || x == (*map)->n_cols - 1))
			return (0);
		if ((c == 'P' && (*map)->n_players > 0) \
			|| (c == 'E' && (*map)->n_exits > 0))
			return (0);
		else if (c == 'P')
		{
			update_position((*map)->p_pos, x, y);
			(*map)->n_players++;
		}
		else if (c == 'E')
		{
			update_position((*map)->e_pos, x, y);
			(*map)->n_exits++;
		}
		else if (c == 'C')
			(*map)->n_collectibles++;
		(*map)->map_matrix[y][x] = c;
	}
	else
		return (0);
	return (1);
}

t_map	*upload_map(char *file_name)
{
	int		fd;
	t_map	*map;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_message(NULL, "Error opening map\n");
	map = init_map_without_size();
	if (valid_map_size(fd, &map) != 1)
	{
		destroy_map(map);
		error_message(NULL, "Invalid map\n");
	}
	if (init_map_matrix(&map, map->n_rows, map->n_cols) != 1)
	{
		destroy_map(map);
		error_message(NULL, "Error initing map matrix\n");
	}
	fd = open(file_name, O_RDONLY);
	if (updload_map_matrix(&map, fd) != 1)
	{
		destroy_map(map);
		error_message(NULL, "Invalid map\n");
	}
	return (map);
}
