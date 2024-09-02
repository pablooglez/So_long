/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:28:11 by pablogon          #+#    #+#             */
/*   Updated: 2024/09/02 18:31:43 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	passable_box(t_so_long *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		game->x = new_x;
		game->y = new_y;
		return (1);
	}
	return (0);
}
