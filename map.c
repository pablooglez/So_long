/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:53:21 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/27 21:38:53 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_load_map(t_so_long *game, char *filename)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	i = 0;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error: No se pudo abrir el archivo del mapa");
	
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		ft_error("Error: No se pudo asignar memoria al mapa");
	
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = line;
		game->width = ft_strlen_so_long(fd);
		j = 0;
		while (line[j])
		{
			if (line[j] == 'P')
				game->player++;
			else if (line[j] == 'C')
				game->coin++;
			else if (line[j] == 'E')
					game->exit++;
		}
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = '\0';
	close(fd);
}


int	ft_check_items_game(t_so_long *game)
{
	if (game->coin >= 1 && game->player == 1 && game->exit == 1)
		return (1);
	else
		ft_error("Error: El mapa no contiene el items especificado");
}

int	ft_check_correct_characters(t_so_long *game)
{
	
}




void	ft_init_game(t_so_long *game)
{
	game->width = 0;
	game->height = 0;
	game->player = 0;
	game->coin = 0;
	game->exit = 0;
	game->position_x = 0;
	game->position_y = 0;
	game->map = NULL;
	game->dup = NULL;
	game->init = NULL;
}

