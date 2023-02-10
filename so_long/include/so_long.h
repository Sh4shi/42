
#ifndef SO_LONG_H
#define SO_LONG_H

#include "./../lib/libft/libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <mlx.h>



#define SIZE(x) (x * 32)

//full image's nbr of byte
#define FULL_IMG_SIZE (SIZE(game->map.n_row) * SIZE(game->map.n_col))

//full image's nbr of byte
#define TILE_SIZE (SIZE(game->img[1].line_size / 8))

//nbr of img_ptr in my img* storage
#define MAX_IMG 14



// macro for tile's image path
#define WALL "./image/wall/wall.xpm"
#define EXIT "./image/exit/exit.xpm"
#define COLL1 "./image/collectible/collectible1.xpm"
#define COLL2 "./image/collectible/collectible2.xpm" //!!!
#define PF1 "./image/player/playerfront1.xpm"
#define PF2 "./image/player/playerfront2.xpm"   //!!! 
#define PB1 "./image/player/playerback1.xpm"    //!!!
#define PB2 "./image/player/playerback2.xpm"    //!!!
#define PR1 "./image/player/playerright1.xpm"   //!!!
#define PR2 "./image/player/playerright2.xpm"   //!!!
#define PL1 "./image/player/playerleft1.xpm"    //!!!
#define PL2 "./image/player/playerleft2.xpm"    //!!! 
#define FLOOR "./image/tiffany.xpm"

/**** INDEX FOR IMAGE'S STORAGE ARRAY ****\
*       ( used also x the path arr )      *
*                                         *
*       0 = complete image                *
*       1 = wall                          *
*       2 = exit                          *
*       3 = collectible 1                 *
*       4 = collectible 2                 *
*       5 = player front 1                *
*       6 = player front 2                *
*       7 =   *   back 1                  *
*       8 =   *   back 2                  *
*       9 =   *   right 1                 *
*       10 =  *   right 2                 *
*       11 =  *   left 1                  *
*       12 =  *   left 2                  *
*       13 = floor                        *
*                                         *
******************************************/



typedef struct s_vector
{
    int x;
    int y;
}               t_vector;

typedef struct s_img //struct for all the img utility
{
    void            *img_ptr;
    t_vector        size;
    char            *path;
    char            *pixels;     //an array that store all the image's pixels
    int             line_size;   //size of an image's line (in bit)
    int             pixel_bits;  //nbr of bit for one pixel
    int             endian;
}               t_img;

typedef struct s_map
{
    t_list      *list_map;
    char        **map_matrix;
    t_vector    pos;
    int         n_row;
    int         n_col;
}               t_map;

typedef struct s_game
{
    void    *mlx;
    void    *win_ptr;
    t_map   map;
    t_img   img[MAX_IMG];
}               t_game;



//---------------------------------------------------- CHECK INPUT FILE

//checker.c

void    check_file(int ac, char **av, t_game *game);
void    check_map(char *map, t_game *game);
void    read_file(char *map, t_game *game);
void    check_layout(t_game *game);

//check_utility.c

bool continuous_wall(t_list *list);
bool all_one(char *str);
bool side_wall(char *str);
void check_char(t_game *game);
void add_char(char *str, char *arr);


//---------------------------------------------------- UTILITY

//error.c
int error(char *str);

//map_utility.c
void   alloc_map(t_game *game);


//---------------------------------------------------- START RENDER

//main.c
void    start_render(t_game *game);


//render.c
void    init_ptr(t_game *game);
void    fill_image_storage(t_game *game);
void    *new_img(t_game *game);
void    draw_new_image(t_game *game);

//render_utility.c
void    define_path(t_img *img);
t_img   *read_map_and_find_right_img(t_game *game, char tile_type);
int     get_pixel(t_img *img, int y, int x);
int     copy_tile(uint32_t *full_img, uint32_t *tile, int tile_size);

# endif