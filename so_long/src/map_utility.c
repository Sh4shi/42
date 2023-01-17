#include "./../include/so_long.h"

void    alloc_map(t_game *game)
{
    t_list  *node;
    char    matrix[game->map.n_row][game->map.n_col + 1];
    int     i;
    int     x;

    x = 0;
    i = 0;
    node = game->map.list_map;
    ft_bzero(matrix, (game->map.n_row * game->map.n_col) + game->map.n_row);
    game->map.map_matrix = &(*matrix);
    while (i < game->map.n_row)
    {
        ft_memcpy(&(matrix[i]), node->content, game->map.n_col + 1);
        node = node->next;
        i++;
    }
    while (x < game->map.n_row)
    {
        printf("%s\n", matrix[x]);
        x++;
    }
}