/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:37:23 by pemirand          #+#    #+#             */
/*   Updated: 2024/10/07 12:20:32 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	*map;

	if (argc != 2 || valid_filename(argv[1]))
		error_message(NULL, "Invalid Args\n");
	valid_textures();
	map = upload_map(argv[1]);
	game = init_game(map);
	if (!game)
		error_message(game, "Initing game problem!\n");
	init_mlx_game(game);
}
