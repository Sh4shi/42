/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:23:49 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/14 00:07:45 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft2/libft.h"

typedef	struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef	struct s_layout
{
	int	nbr_row;
	int	nbr_col;
	int	nbr_collect;
	int	nbr_player;
	int nbr_enemy;
	int	nbr_exit;
}				t_layout;

typedef enum e_type
{
	empty = '0',
	wall = '1',
	collectable = 'C',
	player = 'P',
	exit = 'E',
	enemy = 'M', 
}			t_type;

typedef	enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53,	
}			t_keycode;

typedef struct s_game
{
	t_type		*type;
	t_keycode	*keys;
	t_layout	*layout;
	t_game		*game;
	void		*mlx;
	int			width;
	int			height;
	void		*new_wnd;
	int			map_pointer;
	int			moves;
	t_vector	*vector;
}				t_game;

char 		**ft_file_check(int argc, char **argv, t_game *game);
char		ft_error_message(char *msg);
int			ft_extension_check(const char *s1, const char *s2, int n);
t_layout 	ft_init_lay(t_game *game);
char		**ft_lay_check(t_game *game);
void		ft_type_check(t_game *game, char *buffer);
char		**ft_alloct_map(t_game *game);
void		**ft_map_check(char **map, t_game *game);
void		**ft_map_check_rightdown(char **map, t_game *game, t_layout layout);

#endif