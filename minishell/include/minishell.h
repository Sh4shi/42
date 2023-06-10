
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

#define BUILDIN 0
#define BASHCMD 1

typedef struct s_command
{
    char               **cmd;
    int                 type;
    struct s_command   *next;
    struct s_command   *prev;
}               t_command;

typedef struct s_cmd_list
{
    t_command   *head;
    t_command   *tail;
}              t_cmd_list;

typedef struct s_shell
{
    char        *cmd_line;
    t_cmd_list  commands;
    char        **path;
}               t_shell;

//------------------------------------------- init.c
bool    get_cmd(t_shell *shell, char *cmd_str);
int     find_command(t_shell *shell, char **cmd);

//--------------------------------------------error.c
void    error(char *str);

//-------------------------------------------utility.c
void    init_cmd_list(t_shell *shell, char **cmd, int type);
void    add_cmd_in_list(t_shell *shell, char **cmd, int type);
#endif