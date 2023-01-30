#include "./../include/so_long.h"

void    draw_new_image(t_game *game)
{
    char    *tile;
    int     i;

    game->map.pos.y = 0;
    game->map.pos.x = 0;
    i = INDEX;
    while (i <= game->img[0]->line_size * game->map.n_row)
    {
        game->map.pos.x = 0;
        while (game->map.pos.x <= game->map.n_col)
        {
            copy_pixel(&(game->img[0]->pixels[i]),
                       read_map_and_find_right_img(game->img,game->map.map_matrix,
                                                   game->map.pos.y, game->map.pos.x));
            game->map.pos.x += 1;
            i = INDEX;
        }
        game->map.pos.y += 1;
    }
}

void    *new_img(t_game *game)
{
    game->img[0]->img_ptr = mlx_new_image(game->mlx, game->map.n_row * 32, game->map.n_col * 32);
    if (!game->img[0]->img_ptr)
        error("Error\nimage issue\n");
    game->img[0]->pixels = mlx_get_data_addr(game->img[0]->img_ptr, &game->img[0]->pixel_bits, &game->img[0]->line_size, &game->img[0]->endian);
    draw_new_image(game);
    return (game->img[0]->img_ptr);
}

void      fill_image_storage(t_game *game)
{
    int i;

    i = 1;  /* skip for now index 0 because after get all the tiles data I can make the full image */
    define_path(game->img);
    while (i <= 12)
    {
        game->img[i]->img_ptr = mlx_xpm_file_to_image(game->mlx, game->img[i]->path, &game->img[i]->size.x, &game->img[i]->size.y);
        if (!game->img[i]->img_ptr)
            error("Error\nimage issue\n");
        game->img[i]->pixels = mlx_get_data_addr(game->img[i]->img_ptr, &game->img[i]->pixel_bits, &game->img[i]->line_size, &game->img[i]->endian);
        i++;
    }
}

void    init_ptr(t_game *game)
{
    game->mlx = mlx_init();
    game->win_ptr = mlx_new_window(game->mlx, game->map.n_row * 32, game->map.n_col * 32, "So_long");
    game->img = ft_calloc(13, sizeof(t_img *));
    fill_image_storage(game);
}