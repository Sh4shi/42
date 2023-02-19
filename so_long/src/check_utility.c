#include "./../include/so_long.h"

void    add_char(char *str, char *arr)
{
    while (*str)
    {
       arr[(unsigned char)(*str)]++;
       ++str;
    }
}

void    check_char(t_game *game)
{
    t_list *node;
    char arr[256];
    int i;

    i = 0;
    ft_bzero(arr, 256);
    node = game->map.list_map;
    while (node)
    {
        add_char(node->content, arr);
        node = node->next;
    }
    if (!(arr['P'] == 1 && arr['E'] == 1 && arr['C'] >= 1))
        error("Error\nMust be one P, one E and at least one C\n");
    while (i < 256)
    {
        if (arr[i] != 0 && i != 'P' && i != 'E' && i != 'C' &&
                i != '\n' && i != '0' && i != '1')
            error("Error\nFound invalid character!\n");
        i++;
    }
    game->nbr_colls = arr['C'];
}

bool side_wall(char *str)
{
   int i;

   i = ft_strlen(str);
   if (*str != '1' && str[i - 1] != '1')
       return (false);
   else
       return (true);
}

bool all_one(char *str)
{
    while (*str)
    {
        if (*str != '1')
            return false;
        ++str;
    }
    return (true);
}

bool continuous_wall(t_list *list)
{
    t_list *first_row;

    first_row = list;
    while (list)
    {
        if (list == first_row || list->next == NULL)
        {
            if (!all_one((char *)list->content))
                return (false);
        }
        else
            if (!side_wall((char *)list->content))
                return (false);
        list = list->next;
    }
    return (true);
}