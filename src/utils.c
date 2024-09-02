/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:41:21 by pablogon          #+#    #+#             */
/*   Updated: 2024/09/02 18:36:22 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_so_long(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	ft_win(t_so_long *game)
{
	printf("You win!\n");
	mlx_terminate(game->init);
	exit(0);
}

void	ft_free_map(t_so_long *game)
{
	int	i;

	if (game->map)
	{
		i = game->height;
		while (i > 0)
		{
			free(game->map[--i]);
		}
		free(game->map);
		game->map = NULL;
	}
}

void	ft_init_game(t_so_long *game)
{
	game->width = 0;
	game->height = 0;
	game->player = 0;
	game->coin = 0;
	game->total_coins = 0;
	game->exit = 0;
	game->count = 0;
	game->x = -1;
	game->y = -1;
	game->map = NULL;
	game->init = NULL;
	game->img_floor = NULL;
	game->img_wall = NULL;
	game->img_coin = NULL;
	game->img_exit = NULL;
	game->img_player = NULL;
}

void	ft_cleanup(t_so_long *game)
{
	if (game->map)
		ft_free_map(game);
	if (game->dup)
		ft_free_duplicate_map(game);
	mlx_delete_texture(game->txt_coin);
	mlx_delete_texture(game->txt_exit);
	mlx_delete_texture(game->txt_wall);
	mlx_delete_texture(game->txt_player);
	mlx_delete_texture(game->txt_floor);
	mlx_terminate(game->init);
}
