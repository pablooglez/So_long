/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:48:34 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/29 22:29:27 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_init(t_so_long *game)
{
	game->init = mlx_init(game->width * WIDTH, game->height * HEIGHT, "so_long", true);
	if (!game->init)
		ft_error("Error: No se pudo inicializar la MLX");

	game->txt_coin = mlx_load_png("coin.png");
	game->txt_door = mlx_load_png("door.png");
	game->txt_exit = mlx_load_png("exit.png");
	game->txt_floor = mlx_load_png("floor.png");
	game->txt_player = mlx_load_png("player.png");
	game->txt_wall = mlx_load_png("wall.png");
	if (!game->txt_coin || !game->txt_door || !game->txt_exit || 
	!game->txt_floor || !game->txt_player || game->txt_wall)
		ft_error("Error: No se pudieron cargar las imágenes");
}

void	ft_hook(t_so_long *game, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		game->img_player->instances[0].y -= 64;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		game->img_player->instances[0].y += 64;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		game->img_player->instances[0].x -= 64;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		game->img_player->instances[0].x += 64;
}

void	ft_print_images(t_so_long *game)
{
	int	y;
	int	x;
	mlx_image_t* img;
	
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
				img = mlx_texture_to_image(game->init, game->txt_player);
			else if (game->map[y][x] == 'C')
				img = mlx_texture_to_image(game->init, game->txt_coin);
			else if (game->map[y][x] == 'E')
				img = mlx_texture_to_image(game->init, game->txt_exit);
			else if (game->map[y][x] == '0')
				img = mlx_texture_to_image(game->init, game->txt_floor);
			else if (game->map[y][x] == '1')
				img = mlx_texture_to_image(game->init, game->txt_wall);
			mlx_image_to_window(game->init, img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

