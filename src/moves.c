/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:24:06 by pablogon          #+#    #+#             */
/*   Updated: 2024/09/02 18:21:03 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_so_long *game)
{
	char	actual_p;

	actual_p = game->map[game->y][game->x];
	if (actual_p == 'C')
	{
		game->coin++;
		game->map[game->y][game->x] = '0';
		mlx_image_to_window(game->init, game->img_floor,
			game->x * 64, game->y * 64);
		mlx_delete_image(game->init, game->img_player);
		game->img_player = mlx_texture_to_image(game->init, game->txt_player);
		mlx_image_to_window(game->init, game->img_player,
			game->x * 64, game->y * 64);
	}
	if (actual_p == 'E')
	{
		if (game->coin == game->total_coins)
			ft_win(game);
		else
			game->map[game->y][game->x] = 'E';
	}
	else
		game->map[game->y][game->x] = 'P';
}
