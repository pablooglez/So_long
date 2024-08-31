/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:14:05 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/31 15:00:48 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line_bonus.h"
# define PIXEL 64

typedef struct s_so_long
{
	int			width;
	int			height;
	int			player;
	int			coin;
	int			total_coins;
	int			exit;
	int			x;
	int			y;
	char		**map;
	char		**dup;
	void		*win;
	mlx_t		*init;
	mlx_texture_t	*txt_coin;
	mlx_texture_t	*txt_door;
	mlx_texture_t	*txt_exit;
	mlx_texture_t	*txt_floor;
	mlx_texture_t	*txt_player;
	mlx_texture_t	*txt_wall;
	mlx_image_t	*img_coin;
	mlx_image_t	*img_door;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_player;
	mlx_image_t	*img_wall;
}t_so_long;

//--------------------CREATE-GAME--------------//
void	ft_mlx_init(t_so_long *game);
void	ft_init_images(t_so_long *game);
void	ft_print_static_images(t_so_long *game);
void	ft_print_images(t_so_long *game);
void	ft_keymoves(mlx_key_data_t keydata, void *game);
void	ft_move_player(t_so_long *game, int position_x, int position_y);

//--------------------CHECK--------------------//
int					ft_check_map_size(t_so_long *game, char *str);
int					ft_check_file(char *str);
int					ft_check_items_game(t_so_long *game);
int					ft_check_correct_characters(t_so_long *game);
int					ft_check_walls(t_so_long *game);

//--------------------ERROR--------------------//
void				ft_error(char *msg);
void				ft_error_mlx(void);

//--------------------FLOOD_FILL---------------//
void				ft_duplicate_map(t_so_long *game);
void				ft_get_player_position(t_so_long *game);
void				flood_fill(t_so_long *game, int x, int y);
int					ft_check_access(t_so_long *game);

//--------------------MAP----------------------//
void				ft_load_map(t_so_long *game, char *filename);
void				ft_init_game(t_so_long *game);

//--------------------UTILS--------------------//
int					ft_strlen_so_long(char *str);
void				ft_win(t_so_long *game);
void				ft_cleanup(t_so_long *game);


#endif