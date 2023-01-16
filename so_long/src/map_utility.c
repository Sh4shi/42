#include "./../include/so_long.h"

void    alloc_map(t_game *game)
{
    t_list  *node;
    char    matrix[game->map.n_row][game->map.n_col];
    int     i;
    int     j;

    i = 0;
    j = 0;
    node = game->map.list_map;
    ft_bzero(matrix, game->map.n_row * game->map.n_col);
    game->map.map_matrix = matrix;
    while (j < game->map.n_row && i < game->map.n_col)
    {

    }
}