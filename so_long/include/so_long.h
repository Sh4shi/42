
#ifndef SO_LONG_H
#define SO_LONG_H

#include "./../lib/libft/libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>

// formula to set the index for the img pixel's array
#define INDEX game->img[0]->pixels + ((game->img[0]->line_size * game->map.pos.y) + ((game->img[0]->pixel_bits / 8) * game->map.pos.x))

// macro for tile's image path
#define WALL "./image/wall/wall.xpm"
#define EXIT "./image/exit/exit.xpm"
#define COLL1 "./image/collectible/collectible1.xpm"
#define COLL2 "./image/"
#define PF1 "./image/player/playerfront1.xpm"
#define PF2 "./image/"
#define PB1 "./image/"
#define PB2 "./image/"
#define PR1 "./image/"
#define PR2 "./image/"
#define PL1 "./image/"
#define PL2 "./image/"

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
    int             line_size;   //size of an image's line (amount of byte)
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
    t_img   *img;
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
t_img   *read_map_and_find_right_img(t_img *img, char **map, int y, int x);
void    copy_pixel(char *full_img, t_img *tile);

# endif