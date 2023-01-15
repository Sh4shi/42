#include "./../include/so_long.h"

 void check_layout(t_game *game)
 {
    t_list  *list;

    list = game->map.list_map;
    game->map.n_col = ft_strlen((char *)list->content);
    while (list)
    {
        if (ft_strlen((char *)list->content) != game->map.n_col)
            error("Error\nmap's layout is not regular\n");
        else if (game->map.n_col == game->map.n_row)
            error("Error\nmap MUST be rectangular!\n");
        list = list->next;
    }
     if (continuous_wall(game->map.list_map) == false)
         error("Error\nmap's perimeter is not continuous!\n");
 }

 void read_file(char *map, t_game *game)
 {
    int fd;
    char *str;

    fd = open(map, O_RDONLY);
     if (fd < 0)
         error("Error\nfile opening error\n");
     str = get_next_line(fd);
     while (str)
     {
         ft_lstadd_back(&game->map.list_map,ft_lstnew(str));
         str = get_next_line(fd);
     }
}

 void   check_map(char *map, t_game *game)
{
    read_file(map, game);
    check_layout(game);
   // print_shell_map(game);
}

void    check_file(int ac, char **av, t_game *game)
{
    if (ac != 2)
        error("Error\ninvalid argument\n");
    else if (!ft_strrchr(av[1], '.ber'))
        error("Error\nfile extension not .ber\n");
    check_map(av[1], game);
}