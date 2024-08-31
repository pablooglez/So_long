/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:39:18 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/31 23:35:22 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_game(t_so_long *game, char *file)
{
	if (!ft_check_file(file))
		ft_error_cleanup(game, "Error: Invalid file extension");
	ft_init_game(game);
	if (!ft_check_map_size(game, file))
		ft_error_cleanup(game, "Error: Invalid map size");
	ft_load_map(game, file);
	if (!ft_check_correct_characters(game))
		ft_error_cleanup(game, "Error: Characters not allowed");
	if (!ft_check_walls(game))
		ft_error_cleanup(game, "Error: It's not surrounded by walls");
	ft_duplicate_map(game);
	ft_get_player_position(game);
	if (game->x == -1 && game->y == -1)
		ft_error_cleanup(game, "Error: Player position not found");
	flood_fill(game, game->x, game->y);
	if (!ft_check_access(game))
		ft_error_cleanup(game, "Error: No access");
}

void	ft_run_mlx(t_so_long *game)
{
	ft_mlx_init(game);
	mlx_key_hook(game->init, ft_keymoves, &game);
	mlx_loop(game->init);
}

int	main(int argc, char **argv)
{
	t_so_long	game;

	if (argc == 2)
	{
		ft_check_game(&game, argv[1]);
		ft_run_mlx(&game);
		ft_cleanup(&game);
	}
	else
		ft_error_cleanup(&game, "ERROR: Invalid number of arguments");
	return (0);
}
