
#include "./../include/so_long.h"

void    start_render(t_game *game)
{
    void *ptr;

    init_ptr(game);
    ptr = new_img(game);
    mlx_put_image_to_window(game->mlx, game->win_ptr, ptr, 0, 0);
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

