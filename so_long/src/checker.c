#include "./../include/so_long.h"

#define CHECK_WALL 1

 void check_layout(t_game *game)
 {
    t_list  *list;

    list = game->map->list_map;
    game->map->n_col = ft_strlen((char *)list->content);
    while (list)
    {
        if (ft_strlen((char *)list->content) != game->map->n_col)
            error("Error\n map's layout is not regular\n");
        else if (game->map->n_col == game->map->n_row)
            error("Error\n map MUST be rectangular!\n");
#ifdef CHECK_WALL
        if (continuous_wall(list) == false)
            error("Error\n map's perimeter is not continuous!\n");
#endif

        list = list->next;
    }
 }

 void read_file(char *map, t_game *game)
 {
    int fd;

    fd = open(map, O_RDONLY);
     if ((fd) < 0)
         error("Error\n file opening error\n");
     while (fd && game->map->n_row++)
         ft_lstadd_back(&game->map->list_map,
                        ft_lstnew(
                                get_next_line(fd)));
 }

 void   check_map(char *map, t_game *game)
{
    read_file(map, game);
    check_layout(game);
}

void    check_file(int ac, char **av, t_game *game)
{
    if (ac != 2)
        error("Error\n invalid argument\n");
    else if (!ft_strrchr(av[1], '.ber'))
        error("Error\n file extension not .ber\n");
    check_map(av[1], game);

    return (true);
}