#include "./../include/so_long.h"

int side_wall(char *str)
{
   int i;

   i = ft_strlen(str);
   if (*str != '1' && *(str + (i - 1)) != '1')
       return (0);
   else
       return (1);
}

char all_one(char *str)
{
    while (*str && *str == '1')
        str++;
    return (*str);
}

bool continuous_wall(t_list *list)
{
    t_list *first_row;

    first_row = list;
    while (list)
    {
        if (list == first_row || list->next == NULL)
        {
            if (all_one((char *)list->content) != '1')
                return (false);
        }
        else
            if (!side_wall((char *)list->content))
                return (false);
        list = list->next;
    }
    return (true);
}