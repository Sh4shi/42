
#include "./../include/so_long.h"

void    start_render(t_game *game)
{
    init_ptr(game);
}

int main(int ac, char **av)
{
    t_game game;

    ft_bzero(&game, sizeof(t_game));
    check_file(ac, av, &game);
    alloc_map(&game);
    start_render(&game);
    mlx_loop(game.mlx);
    return (0);
}

