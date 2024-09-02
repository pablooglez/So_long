/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:34:43 by pablogon          #+#    #+#             */
/*   Updated: 2024/09/02 14:14:50 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_size(t_so_long *game, char *str)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	len = ft_strlen_so_long(line);
	while (line)
	{
		game->height++;
		free(line);
		line = get_next_line(fd);
		if (line && len != ft_strlen_so_long(line))
			return (free(line), 0);
	}
	return (1);
}

int	ft_check_file(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 4)
	{
		while (str[i])
		{
			if (ft_strncmp(&str[i], ".ber\0", 5) == 0)
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	ft_check_items_game(t_so_long *game)
{
	if (game->total_coins >= 1 && game->player == 1 && game->exit == 1)
		return (1);
	ft_error("Error: The map does not contain the specified items");
	return (0);
}

int	ft_check_correct_characters(t_so_long *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->map[y] && game->map[y][x])
		{
			if (game->map[y][x] != 'P' && game->map[y][x] != 'C'
			&& game->map[y][x] != 'E' && game->map[y][x] != '1'
			&& game->map[y][x] != '0' && game->map[y][x] != '\n')
				ft_error ("Error: Characters not allowed");
			x++;
		}
		y++;
	}
	return (ft_check_items_game(game));
}

int	ft_check_walls(t_so_long *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			ft_error ("Error: The map is not surrounded by walls");
		y++;
	}
	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			ft_error ("Error: The map is not surrounded by walls");
		x++;
	}
	return (1);
}
