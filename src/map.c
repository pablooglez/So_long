/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:53:21 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/30 19:31:54 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_map(t_so_long *game, char *filename)
{
	int		fd;
	char	*line;
	int		x;
	int		y;
	x = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error: Couldn't open the map file");
	
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		ft_error("Error: Couldn't allocate memory to the map.");
	
	line = get_next_line(fd);
	while (line)
	{
		game->map[x] = line;
		game->width = ft_strlen_so_long(line);
		y = 0;
		while (line[y])
		{
			if (line[y] == 'P')
				game->player++;
			else if (line[y] == 'C')
				game->total_coins++;
			else if (line[y] == 'E')
					game->exit++;
			y++;
		}
		line = get_next_line(fd);
		x++;
	}
	game->map[x] = NULL;
	close(fd);
}

void	ft_init_game(t_so_long *game)
{
	game->width = 0;
	game->height = 0;
	game->player = 0;
	game->coin = 0;
	game->total_coins = 0;
	game->exit = 0;
	game->map = NULL;
	game->dup = NULL;
	game->x = -1;
	game->y= -1;
}

