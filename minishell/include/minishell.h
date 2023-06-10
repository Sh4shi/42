
#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>

#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>

#include "./../libft/libft.h"

extern char **environ;

#define STATUS 1

#define BUILDIN 1
#define BASHCMD 0

typedef struct s_command_list
{
    char                    **cmd;
    int                     type;
    struct s_command_list   *next_cmd;
}               t_command_list;

typedef struct s_shell
{
    char            *cmd_line;
    t_command_list  *commands;
    char            **path;
}               t_shell;

//------------------------------------------- init.c
bool    get_cmd(t_shell *shell, char *cmd_str);
int     find_command(char *file_name, char *cmd);

//--------------------------------------------error.c
void    error(char *str);

#endif