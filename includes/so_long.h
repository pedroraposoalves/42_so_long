/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:31:05 by pemirand          #+#    #+#             */
/*   Updated: 2024/10/07 16:16:46 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "../libs/mlx/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define IMG_SIZE 32
# define N_TEXTURES 5
# define WIN_NAME "so_long"

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_KEY 65362
# define LEFT_KEY 65361
# define DOWN_KEY 65364
# define RIGHT_KEY 65363
# define ESC_KEY 65307

# define EMPTY_SPACE_IMG "./textures/back.xpm"
# define WALL_IMG "./textures/honey.xpm"
# define COLLECTIBLE_IMG "./textures/flower.xpm"
# define PLAYER_IMG "./textures/bee.xpm"
# define EXIT_IMG "./textures/exit.xpm"
# define EMPTY_SPACE_ID 0
# define WALL_ID 1
# define COLLECTIBLE_ID 2
# define PLAYER_ID 3
# define EXIT_ID 4

typedef struct s_position
{
	unsigned int	x;
	unsigned int	y;
}	t_position;

typedef struct s_map
{
	char			**map_matrix;
	unsigned int	n_cols;
	unsigned int	n_rows;
	unsigned int	n_collectibles;
	unsigned int	n_exits;
	unsigned int	n_players;
	t_position		*p_pos;
	t_position		*e_pos;
}	t_map;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*textures[N_TEXTURES];
	unsigned int	n_movements;
	t_map			*map;
}	t_game;

int		valid_filename(char *name);
int		valid_map_size(int fd, t_map **map);
t_map	*init_map_without_size(void);
int		init_map_matrix(t_map **map, int n_rows, int n_cols);
// void	print_map_matrix(t_map *map);
int		updload_map_matrix(t_map **map, int fd);
int		upload_map_pos(t_map **map, unsigned int x, unsigned int y, char c);
t_map	*upload_map(char *file_name);
t_game	*init_game(t_map *map);
void	destroy_game(t_game *game);
void	destroy_map(t_map *map);
void	destroy_matrix(char **matrix, unsigned int n_rows);
void	error_message(t_game *game, char *message);
int		exit_sucess(t_game *game);
void	init_mlx_textures(t_game *game);
void	init_mlx_game(t_game *game);
int		on_keypress(int keysym, t_game *game);
void	render_icon(t_game *game, int x, int y, char c);
int		render_game(t_game *game);
int		valid_movement(t_map *map, int x, int y);
void	movement(t_game *game, int move_x, int move_y);
char	**clone_map_matrix(t_map *map);
int		valid_path(t_map *map, t_position *pos, char **matrix);
void	valid_textures(void);

#endif
