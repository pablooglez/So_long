/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:10:43 by pablogon          #+#    #+#             */
/*   Updated: 2024/09/02 14:05:10 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_duplicate_map(t_so_long *game)
{
	int	y;

	y = 0;
	game->dup = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->dup)
		ft_error("Error: Could not allocate memory to map duplicate");
	while (y < game->height)
	{
		game->dup[y] = ft_strdup(game->map[y]);
		if (!game->dup[y])
			ft_error ("Error: Could not duplicate a row on the map");
		y++;
	}
	game->dup[y] = NULL;
}

void	ft_free_duplicate_map(t_so_long *game)
{
	int	i;

	if (game->dup)
	{
		i = game->height;
		while (i > 0)
		{
			free(game->dup[--i]);
		}
		free(game->dup);
		game->dup = NULL;
	}
}

void	ft_get_player_position(t_so_long *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->x = x;
				game->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	game->x = -1;
	game->y = -1;
}

void	flood_fill(t_so_long *game, int x, int y)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game->height
		|| game->dup[y][x] == '1')
		return ;
	game->dup[y][x] = '1';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y -1);
}

int	ft_check_access(t_so_long *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->dup[y][x] == 'C' || game->dup[y][x] == 'E'
			|| game->dup[y][x] == 'P')
			{
				ft_error("Error: No valid path");
			}
			x++;
		}
		y++;
	}
	return (1);
}
