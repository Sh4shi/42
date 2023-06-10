#include "./../include/minishell.h"

void    add_cmd_in_list(t_shell *shell, char **cmd, int type)
{
    t_command *new_cmd;

    new_cmd = malloc(sizeof(t_command *));
    if (!command)
        error("malloc error: can't allocate cmd list\n");
    new_cmd->cmd = cmd;
    new_cmd->type = BASHCMD;
    new_cmd->prev = shell->commands.tail;
    shell->commands.tail->next = new_cmd;
    shell->commands.tail = new_cmd;
    new_cmd->next = NULL;
}

void    init_cmd_list(t_shell *shell, char **cmd, int type)
{
    t_command *command;

    command = malloc(sizeof(t_command *));
    if (!command)
        error("malloc error: can't allocate cmd list\n");
    command->cmd = cmd;
    command->type = type;
    shell->commands.head = command;
    shell->commands.head->prev = NULL;
    shell->commands.tail = command;
    shell->commands.tail->prev = shell->commands.head;
    shell->commands.head->next = shell->commands.tail
    shell->commands.tail->next = NULL;
    command->prev = NULL;
    command->next = NULL;
}