
#include "./../include/so_long.h"

int main(int ac, char **av)
{
    t_game game;

    ft_bzero(&game, sizeof(t_game));
    check_file(ac, av, &game);
    alloc_map(&game);
    game.mlx = mlx_init();
    game.win_ptr = mlx_new_window(game.mlx, 200, 200, "So_long");
    mlx_loop(game.mlx);
    return (0);
}

