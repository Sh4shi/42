#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft2/libft.h"

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
}				t_game;

char 		**ft_file_check(int arg_c, char arg_v, t_game *game);
char		ft_error_message(char *msg);
int			ft_extension_check(const char *s1, const char *s2, int n);
t_layout 	ft_init_lay(t_game *game);
int			ft_alloct_lay(int fd, t_game *game);

#endif