
#include "so_long.h"

t_layout ft_init_lay(t_game *game)
{
	t_layout layout;
	layout.nbr_row = 0;
	layout.nbr_col = 0;
	layout.nbr_collect = 0;
	layout.nbr_player = 0;
	layout.nbr_enemy = 0;
	layout.nbr_exit = 0;
}

int main(int arg_c, char **arg_v)
{
	char	**map;
	t_game	*game;
	void	*mlx;
	void	*new_wnd;

	map = ft_file_check(arg_c, arg_v, game);
	mlx = mlx_init();
	new_wnd = mlx_new_window(mlx, );
}