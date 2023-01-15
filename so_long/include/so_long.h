
#ifndef SO_LONG_H
#define SO_LONG_H

#include "./../lib/libft/libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>

typedef struct s_map
{
    t_list  *list_map;
    char    **map_matrix;
    int     n_row;
    int     n_col;
    int     nbr_coll;
}               t_map;

typedef struct s_game
{
    void    *mlx;
    void    *windows_p;
    t_map   map;
}               t_game;




//---------------------------------------------------- CHECK INPUT FILE

//checker.c

void    check_file(int ac, char **av, t_game *game);
void    check_map(char *map, t_game *game);
void    read_file(char *map, t_game *game);
void    check_layout(t_game *game);

//check utility.c

bool continuous_wall(t_list *list);
char all_one(char *str);
int side_wall(char *str);

//---------------------------------------------------- UTILITY

//error.c
int error(char *str);

//map_utility.c
void   print_shell_map(t_game *game);

# endif