/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:48:17 by pablogon          #+#    #+#             */
/*   Updated: 2024/09/02 18:36:30 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_keymoves(mlx_key_data_t keydata, void *param)
{
	t_so_long	*game;
	int			new_x;
	int			new_y;

	game = (t_so_long *)param;
	new_x = game->x;
	new_y = game->y;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->init);
	ft_keymove_w(keydata, param);
	ft_keymove_a(keydata, param);
	ft_keymove_s(keydata, param);
	ft_keymove_d(keydata, param);
	ft_move_player(game);
}

void	ft_keymove_w(mlx_key_data_t keydata, void *param)
{
	t_so_long	*game;
	int			new_x;
	int			new_y;

	game = (t_so_long *)param;
	new_x = game->x;
	new_y = game->y;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& passable_box(game, new_x, new_y - 1))
	{
		game->img_player->instances[0].y -= 64;
		game->count++;
		printf("Move count: %d\n", game->count);
	}
}

void	ft_keymove_a(mlx_key_data_t keydata, void *param)
{
	t_so_long	*game;
	int			new_x;
	int			new_y;

	game = (t_so_long *)param;
	new_x = game->x;
	new_y = game->y;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& passable_box(game, new_x - 1, new_y))
	{
		game->img_player->instances[0].x -= 64;
		game->count++;
		printf("Move count: %d\n", game->count);
	}
}

void	ft_keymove_s(mlx_key_data_t keydata, void *param)
{
	t_so_long	*game;
	int			new_x;
	int			new_y;

	game = (t_so_long *)param;
	new_x = game->x;
	new_y = game->y;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& passable_box(game, new_x, new_y + 1))
	{
		game->img_player->instances[0].y += 64;
		game->count++;
		printf("Move count: %d\n", game->count);
	}
}

void	ft_keymove_d(mlx_key_data_t keydata, void *param)
{
	t_so_long	*game;
	int			new_x;
	int			new_y;

	game = (t_so_long *)param;
	new_x = game->x;
	new_y = game->y;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& passable_box(game, new_x + 1, new_y))
	{
		game->img_player->instances[0].x += 64;
		game->count++;
		printf("Move count: %d\n", game->count);
	}
}
