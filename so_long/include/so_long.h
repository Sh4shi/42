
#ifndef SO_LONG_H
#define SO_LONG_H

#include "./../lib/libft/libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>

// tile's image path
#define WALL "./image/wall/wall.xpm"


//index for images' storage array
#define I 0 /*complete image*/
#define W 1 /*wall*/
#define E 2 /*exit*/
#define C 3 /*collectible*/
#define P 4 /*player*/

typedef struct s_vector
{
    int x;
    int y;
}               t_vector;

typedef struct s_img         //type definition for all the img utility
{
    void        *img_ptr;
    t_vector    size;
    char        *path;
    char        *pixels;     //an array that store all the image's pixels
    int         line_size;   //size of an image's line
    int         pixel_bits;  //nbr of bite for one pixel
    int         endian;
}               t_img;

typedef struct s_map
{
    t_list  *list_map;
    char    **map_matrix;
    int     n_row;
    int     n_col;
}               t_map;

typedef struct s_game
{
    void    *mlx;
    void    *win_ptr;
    t_map   map;
    t_img   img;
}               t_game;



//---------------------------------------------------- CHECK INPUT FILE

//checker.c

void    check_file(int ac, char **av, t_game *game);
void    check_map(char *map, t_game *game);
void    read_file(char *map, t_game *game);
void    check_layout(t_game *game);

//check utility.c

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
void    new_img(t_game *game);

# endif