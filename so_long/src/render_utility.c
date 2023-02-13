#include "./../include/so_long.h"

int	get_pixel(t_img *img, int y, int x)
{
	uint32_t    *pixel;

    pixel = (uint32_t *)(img->pixels + (y * img->line_size + x * (img->pixel_bits / 8)));
	return *pixel;
}

t_img   *read_map_and_find_right_img(t_game *game, char **matrix, int y, int x, int animation)
{
    if (matrix[y][x] == 'P')
    {
        game->p_pos.x = x;
        game->p_pos.y = y;
    }
    if (matrix[y][x] == '1')
        return (&(game->img[1]));
    else if (matrix[y][x] == 'E')
        return (&(game->img[2]));
    else if (matrix[y][x] == 'C' && animation == 0)
        return (&(game->img[3]));
    else if (matrix[y][x] == 'C' && animation == 1)
        return (&(game->img[4]));
    else if (matrix[y][x] == 'P' && animation == 0)
        return (&(game->img[5]));
    else if (matrix[y][x] == 'P' && animation == 1)
        return (&(game->img[6]));
    else if (matrix[y][x] == '0')
        return (&(game->img[13]));
    return 0;
}

void    define_path(t_img *img)
{
    img[1].path = WALL;
    img[2].path = EXIT;
    img[3].path = COLL1;
    img[4].path = COLL2;
    img[5].path = PF1;
    img[6].path = PF2;
    img[7].path = PB1;
    img[8].path = PB2;
    img[9].path = PR1;
    img[10].path = PR2;
    img[11].path = PL1;
    img[12].path = PL2;
    img[13].path = FLOOR;
}