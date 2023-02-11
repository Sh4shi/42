#include "./../include/so_long.h"

/*void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->pixels + (y * img->line_size + x * (img->pixel_bits / 8));
	*(int *)pixel = color;
}

void    draw_new_image(t_game *game)
{
    char    *tile;
    int     i;
    t_img   *tmp;

    game->map.pos.y = 0;
    game->map.pos.x = 0;
    i = 0;
    while (i <= game->img[0].line_size * game->map.n_row)
    {
        game->map.pos.x = 0;
        while (game->map.pos.x <= game->map.n_col)
        {
            tmp = read_map_and_find_right_img(game->img, game->map.map_matrix, game->map.pos.y, game->map.pos.x);
            ft_memcpy(&game->img[0].pixels[i], tmp->pixels, (tmp->line_size * (tmp->size.y * (tmp->pixel_bits / 8))));
            game->map.pos.x += 1;
            i += ((((tmp->size.y * (tmp->pixel_bits / 8))) * tmp->line_size)); (tmp->size.x * tmp->size.y) * (tmp->pixel_bits);
            printf("line size:%d\n", game->img[0].line_size);
            break;
        }
        game->map.pos.y += 1;
    } 
}*/

/* void    draw_new_image(t_game *game)
{
    int         i;
    int         line;
    t_img       *tile;
    t_vector    pos;

    line = 0;
    pos.x = 0;
    pos.y = 0;
    while (pos.y != game->map.n_row && pos.x != game->map.n_col) //finche non scrivo tutta l'immagine
    {
        i = 0;
        if (pos.x == game->map.n_col)
        {
            pos.x = 0;
            pos.y++;
        }
        tile = read_map_and_find_right_img(game, game->map.map_matrix[pos.y][pos.x]);
        i += copy_tile((uint32_t *)&(game->img[0].pixels[i]), (uint32_t *)tile->pixels, TILE_SIZE * 4);
        //line += TILE_SIZE;
        pos.x++;
    }
} */

void    draw_new_image(t_game *game)
{
    int tot_pixel_y = SIZE(game->map.n_row);
    int tot_pixel_x = SIZE(game->map.n_col);
    int *new_img = (int *)game->img[0].pixels;
    int x = 0;
    int y = 0;

    while (y < tot_pixel_y)
    {
        x = 0;
        while (x < tot_pixel_x)
        {
            *new_img = get_pixel(read_map_and_find_right_img(game, game->map.map_matrix[y/32][x/32]),
                y % 32, x % 32);
            new_img++;
            x++;
        }
        y++;
    }
}

void    *new_img(t_game *game)
{
    game->img[0].img_ptr = mlx_new_image(game->mlx, SIZE(game->map.n_col), SIZE(game->map.n_row));//SIZE(game->map.n_row), SIZE(game->map.n_col));
    if (!game->img[0].img_ptr)
        error("Error\nimage issue: can't create new full image\n");
    game->img[0].pixels = mlx_get_data_addr(game->img[0].img_ptr, &game->img[0].pixel_bits, &game->img[0].line_size, &game->img[0].endian);
    draw_new_image(game);
    return (game->img[0].img_ptr);
}

void      fill_image_storage(t_game *game)
{
    int i;

    i = 1;  /* skip for now index 0 because after get all the tiles data I can make the full image */
    define_path(game->img);
    while (i < MAX_IMG)
    {
        game->img[i].img_ptr = mlx_xpm_file_to_image(game->mlx, game->img[i].path, &(game->img[i].size.x), &(game->img[i].size.y));
        if (!game->img[i].img_ptr)
            error("Error\nimage issue: can't get xpm file\n");
        game->img[i].pixels = mlx_get_data_addr(game->img[i].img_ptr, &game->img[i].pixel_bits, &game->img[i].line_size, &game->img[i].endian);
        i++;
    }
}

void    init_ptr(t_game *game)
{
    game->mlx = mlx_init();
    fill_image_storage(game);
    //game->win_ptr = mlx_new_window(game->mlx, SIZE(game->map.n_row), SIZE(game->map.n_col), "So_long");
    game->win_ptr = mlx_new_window(game->mlx,  SIZE(game->map.n_col), SIZE(game->map.n_row), "So_long");
}