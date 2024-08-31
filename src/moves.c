/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:24:06 by pablogon          #+#    #+#             */
/*   Updated: 2024/09/01 00:02:08 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_so_long *game, int position_x, int position_y)
{
	if (game->map[position_y][position_x] != '1')
	{
		if (game->map[position_y][position_x] == 'C')
		{
			game->coin++;
			game->map[position_y][position_x] = '0';
			create_images(game);
		}
		if (game->map[position_y][position_x] == 'E')
		{
			if ((game->map[position_y][position_x] == 'E') && (game->coin == game->total_coins))
			{
				game->x = position_x;
				game->y = position_y;
				create_images(game);
				ft_win(game);	
			}
			else
			{
				game->map[game->y][game->x] = '0';
				game->map[position_y][position_x] = 'E';
				create_images(game);
			}
		}
		else
		{
			game->map[game->y][game->x] = '0';
			game->map[position_y][position_x] = 'P';
			game->x = position_x;
			game->y = position_y;
			create_images(game);
		}
	}
}

void	ft_keymoves(mlx_key_data_t keydata, void *param)
{
	t_so_long	*game;
	int	position_x;
	int	position_y;

	game = (t_so_long *)param;
	position_x = game->x;
	position_y = game->y;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->init);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		position_y--;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		position_x--;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		position_y++;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		position_x++;
}
