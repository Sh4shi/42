#include "./../include/minishell.h"

int find_command(char *file_name, char *cmd)
{

}

bool    get_cmd(t_shell *shell, char *cmd_str)
{
    char    **cmd;
    int     nbr_arg;
    char    **cmd_struct;

    nbr_arg = 0;
    cmd = ft_split(cmd_str, ' ');
    while (cmd && cmd[nbr_arg])
        nbr_arg++;
    cmd_struct = malloc(sizeof(char *) * (nbr_arg + 2));
    if (!cmd_struct)
        error("Error!\nsomething went wrong with Malloc\n");
    if (!find_command(&(*cmd_struct[0]), cmd[0]))
        return (FALSE);
}