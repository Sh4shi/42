#include "./../include/so_long.h"
#undef CHECK_WALL

int side_wall(char *str)
{
   int i;

   i = ft_strlen(str);
   if (*str != '1' && *(str + i) != '1')
       return (0);
   else
       return (1);
}

int all_one(char *str)
{
    while (*str)
    {
        if (*str != '1')
            return (0);
        str++;
    }
    return (1);
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