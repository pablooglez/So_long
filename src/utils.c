/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:41:21 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/27 17:43:31 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen_so_long(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void ft_hook(void *param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}