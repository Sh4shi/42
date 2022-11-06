/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:23:49 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/21 03:36:03 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./lib/minilibx/mlx.h"
# include "./lib/libft2/libft.h"

# define FLOOR "img/floor.xmp"
# define WALL "img/wall.xmp"
# define DOOR "img/door.xmp"
# define COLL1 "img/coll1.xmp"
# define COLL2 "img/coll2.xmp"
# define ENEMY1 "img/enemy/enemy1.xmp"
# define ENEMY2 "img/enemy/enemy2.xmp"
# define ENEMY3 "img/enemy/enemy3.xmp"
# define PLAYERF1 "img/player/playerf1.xmp"

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

typedef struct s_imgcoll
{
	void	*img_coll1;
	void	*img_coll2;	
}				t_imgcoll;

typedef	struct s_imgenemy
{
	void	*img_enemy1;
	void	*img_enemy2;
	void	*img_enemy3;	
}				t_imgenemy;

typedef struct s_imgpl
{
	void	*imgplf1;
	void	*imgplf2;
	void	*imgplf3;
	void	*imgplb1;
	void	*imgplb2;
	void	*imgplb3;
	void	*imgpll1;
	void	*imgpll2;
	void	*imgplr1;
	void	*imgplr2;
	void	*imgpld;	
}				t_imgpl;

typedef struct s_img
{
	void	*img_floor;
	void	*img_wall;
	void	*img_door;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_game
{
	t_layout	*layout;
	t_game		*game;
	t_img		*img;
	t_imgpl		*imgpl;
	t_imgenemy	*imgenemy;
	t_imgcoll	*imgcoll;
	void		*mlx;
	int			width;
	int			height;
	void		*new_wnd;
	int			map_pointer;
	char		**map;
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
void		ft_init_game(t_game *game);
void		*ft_init_img(t_game *game);
void		*ft_get_img(char *path, t_game *game);
void		*ft_check_img(t_game *game);
void		*ft_put_img(t_game *game, void *img, int j, int i);
void		*ft_iteri_put(t_game *game, int i, int j);
void		ft_game_hook(t_game *game);

#endif