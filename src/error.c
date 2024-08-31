/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:13:29 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/31 23:12:08 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_so_long *game, char *msg)
{
	write (2, msg, ft_strlen(msg));
	write (2, "\n", 1);
	ft_cleanup(game);
	exit (EXIT_FAILURE);
}

void	ft_error_cleanup(t_so_long *game, char *msg)
{
	ft_cleanup(game);
	ft_error(game, msg);
}