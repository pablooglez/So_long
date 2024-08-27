/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:14:05 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/27 22:04:28 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line_bonus.h"
#define WIDTH 256
#define HEIGHT 256
# define PIXEL 64

typedef struct s_images
{
	mlx_image_t	*img_coin;
	mlx_image_t	*img_door;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_player;
	mlx_image_t	*img_wall;
}t_images;

typedef struct s_so_long
{
	int			width;
	int			height;
	int			player;
	int			coin;
	int			exit;
	int			position_x;
	int			position_y;
	char		**map;
	char		**dup;
	mlx_t		*init;
	t_images	images;
}t_so_long;

//--------------------MAIN FUCTIONS------------//
int					ft_check_map_size(char *str);
int					ft_check_file(char *str);

//--------------------ERROR--------------------//
void				ft_error(char *msg);
void				ft_error_mlx(void);

//--------------------MAP----------------------//
void				ft_load_map(t_so_long *game, char *filename);
int					ft_check_items_game(t_so_long *game);
void	ft_init_game(t_so_long *game)
//--------------------UTILS--------------------//
int					ft_strlen_so_long(char *str);
void				ft_hook(void *param);


#endif