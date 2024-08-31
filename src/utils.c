/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:41:21 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/31 20:48:26 by pablogon         ###   ########.fr       */
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
	printf("¡Has ganado!\n");
	mlx_terminate(game->init);
	exit(0);
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