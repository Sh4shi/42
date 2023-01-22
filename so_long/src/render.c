#include "./../include/so_long.h"

void    new_img(t_game *game)
{
    game->img.img_ptr = mlx_xpm_file_to_image(game->mlx, WALL, &game->img.size.x, &game->img.size.y);
    if (!game->img.img_ptr)
        return ;
    game->img.pixels = mlx_get_data_addr(game->img.img_ptr, &game->img.pixel_bits, &game->img.line_size, &game->img.endian);
}

void    init_ptr(t_game *game)
{
    ft_bzero(&game->img, sizeof(t_img));
    game->mlx = mlx_init();
    game->win_ptr = mlx_new_window(game->mlx, game->map.n_row * 32, game->map.n_col * 32, "So_long");
}