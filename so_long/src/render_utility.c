#include "./../include/so_long.h"

int    copy_tile(uint32_t *full_img, uint32_t *tile, int tile_size)
{
    int i;

    i = 0;
    while (i <= tile_size)
    {
        full_img[i] = tile[i];
        i++;
    }
    return (i);
}

t_img   *read_map_and_find_right_img(t_img *img, char tile_type)
{
    if (tile_type == '1')
        return (&(img[1]));
    else if (tile_type == 'E')
        return (&(img[2]));
    else if (tile_type == 'C')
        return (&(img[3]));
    else if (tile_type == 'P')
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