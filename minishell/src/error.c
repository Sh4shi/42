
#include "./../include/minishell.h"

void    error(char *str)
{
    printf("%s", str);
    exit(EXIT_FAILURE);
}