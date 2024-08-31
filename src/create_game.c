/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:48:34 by pablogon          #+#    #+#             */
/*   Updated: 2024/09/01 00:01:47 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_init(t_so_long *game)
{
	mlx_set_setting (MLX_STRETCH_IMAGE, true);
	game->init = mlx_init(game->width * PIXEL,
			game->height * PIXEL, "so_long", true);
	if (!game->init)
		ft_error(game, "Error: Failed to initialize MLX");
	load_textures(game);
	create_images(game);
	put_textures(game);
}

void	load_textures(t_so_long *game)
{
	game->txt_coin = mlx_load_png("./images/coin.png");
	if (!game->txt_coin)
		ft_error(game, "Error loading texture: coin");
	game->txt_exit = mlx_load_png("./images/exit.png");
	if (!game->txt_exit)
		ft_error(game, "Error loading texture: exit");
	game->txt_floor = mlx_load_png("./images/floor.png");
	if (!game->txt_floor)
		ft_error(game, "Error loading texture: floor");
	game->txt_player = mlx_load_png("./images/player.png");
	if (!game->txt_player)
		ft_error(game, "Error loading texture: player");
	game->txt_wall = mlx_load_png("./images/wall.png");
	if (!game->txt_wall)
		ft_error(game, "Error loading texture: wall");
}

void create_images(t_so_long *game)
{
	game->img_floor = mlx_texture_to_image(game->init, game->txt_floor);
	if (!game->img_floor)
		ft_error(game, "Error creating image: floor");
	game->img_player = mlx_texture_to_image(game->init, game->txt_player);
	if (!game->img_player)
		ft_error(game, "Error creating image: player");
	game->img_wall = mlx_texture_to_image(game->init, game->txt_wall);
	if (!game->img_wall)
		ft_error(game, "Error creating image: wall");
	game->img_coin = mlx_texture_to_image(game->init, game->txt_coin);
	if (!game->img_coin)
		ft_error(game, "Error creating image: coin");
	game->img_exit = mlx_texture_to_image(game->init, game->txt_exit);
	if (!game->img_exit)
		ft_error(game, "Error creating image: exit");
}

void	put_textures(t_so_long *game)
{
	int	y;
	int	x;

	if (!game->map) 
	{
		ft_error(game, "Error: map is NULL");
		return;
	}
	
	y = 0;
	put_floor(game);
	while (game->height > y)
	{
		x = 0;
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->init, game->img_wall,
					x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->init, game->img_coin,
					x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->init, game->img_exit,
					x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->init, game->img_player,
		game->x * PIXEL, game->y * PIXEL);
}

void	put_floor(t_so_long *game)
{
	int	y;
	int	x;

	if (!game->map) 
	{
		ft_error(game, "Error: map is NULL");
		return ;
	}

	y = 0;
	while (game->height > y)
	{
		x = 0;
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			if (!game->img_floor) 
			{
				ft_error(game, "Error: img_floor is NULL");
				return;
			}
			mlx_image_to_window(game->init, game->img_floor,
				x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
}