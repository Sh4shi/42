#include "./../include/so_long.h"

void    alloc_map(t_game *game)
{
    t_list  *node;
    int     i;

    i = 0;
    node = game->map.list_map;
    game->map.map_matrix = ft_calloc(sizeof(char *), game->map.n_row);
    while(node)
    {
        game->map.map_matrix[i] = node->content;
        node = node->next;
        i++;
    }
}