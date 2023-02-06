#include "./../include/so_long.h"

/*void    copy_pixel(int *full_img, t_img *tile, int tile_size)
{
    int i;

    i = 0;
    while (*(tile->pixels))
    {
        full_img[i] = (char)tile->pixels[i];
        i++;
    }
}*/

t_img   *read_map_and_find_right_img(t_img *img, char **map, int y, int x)
{
    if (map[y][x] == '1')
        return (&(img[1]));
    else if (map[y][x] == 'E')
        return (&(img[2]));
    else if (map[y][x] == 'C')
        return (&(img[3]));
    else if (map[y][x] == 'P')
        return (&(img[5]));
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
}