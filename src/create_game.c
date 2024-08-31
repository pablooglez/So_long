/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:48:34 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/31 15:00:35 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_init(t_so_long *game)
{
	mlx_set_setting (MLX_STRETCH_IMAGE, true);
	game->init = mlx_init(game->width * PIXEL, game->height * PIXEL, "so_long", true);
	if (!game->init)
		ft_error("Error: No se pudo inicializar la MLX");

	game->txt_coin = mlx_load_png("./images/coin.png");
	game->txt_door = mlx_load_png("./images/door.png");
	game->txt_exit = mlx_load_png("./images/exit.png");
	game->txt_floor = mlx_load_png("./images/floor.png");
	game->txt_player = mlx_load_png("./images/player.png");
	game->txt_wall = mlx_load_png("./images/wall.png");
	if (!game->txt_coin || !game->txt_door || !game->txt_exit || 
	!game->txt_floor || !game->txt_player || !game->txt_wall)
		ft_error("Error: No se pudieron cargar las imágenes");

	ft_print_static_images(game);
	ft_print_images(game);
}

void	ft_print_static_images(t_so_long *game)
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
			if (game->map[y][x] == 'C')
			{
				img = mlx_texture_to_image(game->init, game->txt_coin);
				mlx_image_to_window(game->init, img, x * 64, y * 64);
			}
			else if (game->map[y][x] == 'E')
			{
				img = mlx_texture_to_image(game->init, game->txt_exit);
				mlx_image_to_window(game->init, img, x * 64, y * 64);
			}
			else if (game->map[y][x] == '1')
			{
				img = mlx_texture_to_image(game->init, game->txt_wall);
				mlx_image_to_window(game->init, img, x * 64, y * 64);
			}
			else
			{
				x++;
				continue;
			}
			x++;
		}
		y++;
	}
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
			{
				img = mlx_texture_to_image(game->init, game->txt_player);
				mlx_image_to_window(game->init, img, x * 64, y * 64);
			}
			else if (game->map[y][x] == '0')
			{
				img = mlx_texture_to_image(game->init, game->txt_floor);
				mlx_image_to_window(game->init, img, x * 64, y * 64);
			}
			else
			{
				x++;
				continue;
			}
			x++;
		}
		y++;
	}
}

void	ft_move_player(t_so_long *game, int position_x, int position_y)
{
	if (game->map[position_y][position_x] != '1')
	{
		if (game->map[position_y][position_x] == 'C')
		{
			game->coin++;
			game->map[position_y][position_x] = '0';
			ft_print_images(game);
		}
		if (game->map[position_y][position_x] == 'E')
		{
			if ((game->map[position_y][position_x] == 'E') && (game->coin == game->total_coins))
			{
				game->x = position_x;
				game->y = position_y;
				ft_print_images(game);
				ft_win(game);	
			}
			else
			{
				game->map[game->y][game->x] = '0';
				game->map[position_y][position_x] = 'E';
				ft_print_images(game);
			}
		}
		else
		{
			game->map[game->y][game->x] = '0';
			game->map[position_y][position_x] = 'P';
			game->x = position_x;
			game->y = position_y;
			ft_print_images(game);
		}
	}
}

void	ft_keymoves(mlx_key_data_t keydata, void *param)
{
	t_so_long	*game;
	int	position_x;
	int	position_y;
	
	game =(t_so_long *)param;
	position_x = game->x;
	position_y = game->y;
	game = (t_so_long *)param;
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
	ft_move_player(game, position_x, position_y);
}
