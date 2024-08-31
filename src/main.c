/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:39:18 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/31 14:58:00 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_so_long	game;
	

	if (argc == 2)
	
	{
		if (!ft_check_file(argv[1]))
			ft_error("Error: Invalid file extension");
		
		ft_init_game(&game);
		
		if (!ft_check_map_size(&game,argv[1]))
			ft_error("Error: Invalid map size");
		
		ft_load_map(&game, argv[1]);
		
		if (!ft_check_correct_characters(&game))
			ft_error("Error: El mapa contiene caracteres no permitidos");
		
		if (!ft_check_walls(&game))
			ft_error("Error: El mapa no esta rodeado de paredes");
		
		ft_duplicate_map(&game);
		ft_get_player_position(&game);
		if (game.x == -1 && game.y == -1)
			ft_error("Error: No se encontro la posicion del jugador");

		flood_fill(&game, game.x, game.y);
		/*while (game.dup[i])
		{
			write (1, game.dup[i], ft_strlen(game.dup[i]));
			i++;
		}*/
		if (!ft_check_access(&game))
			ft_error("Error: No son accesibles todas las monedas y salidas");

		ft_mlx_init(&game);
		mlx_key_hook(game.init, ft_keymoves, &game);
		mlx_loop(game.init);
		ft_cleanup(&game);
	}
	else
		ft_error("ERROR: Invalid number of arguments");
	return (0);
}
