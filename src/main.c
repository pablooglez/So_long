/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:39:18 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/27 17:56:23 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_map_size(char *str)
{
	int	fd;
	char	*line;
	int	len;
	
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
		
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return(0);
	}
	
	len = ft_strlen_so_long(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && len != ft_strlen_so_long(line))
			return (0);
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

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("correct extension -> %d\n", ft_check_file(argv[1]));
		printf("correct map size -> %d\n", ft_check_map_size(argv[1]));
		/*if (ft_check_file(argv[1]) == 1 && ft_check_map_size(argv[1]) == 1)
			create_game(argv[1]);
		else
			ft_error("Incorrect Map");*/
	}
	else
		ft_error("ERROR");
	return (0);
}
