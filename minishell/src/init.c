#include "./../include/minishell.h"

int find_command(t_shell *shell, char **cmd)
{
    DIR *dir;
    struct dirent *stream;
    bool     cmd_find;

    cmd_find = FALSE;
    while(shell->path && shell->path[i])
    {
        dir = opendir(shell->path[i]);
        if (dir == NULL)
            error("Error\nCould not open dir\n");
        stream = readdir(dir);
        while (stream != NULL)
        {
            if (ft_strnstr(stream->d_name, cmd[0]))
            {
                cmd[0] = stream->d_name;
                if (shell->commands.head == NULL)
                    init_cmd_list(shell, cmd, BASHCMD);
                else
                    add_cmd_in_list(shell, cmd, BASHCMD);
                cmd_find = TRUE;
            }
        }
        closedir(dir);
        i++;
    }
    if (cmd_find == TRUE)
        return (1);
    else
        return (0);
}

bool    get_cmd(t_shell *shell, char *cmd_str)
{
    char **cmd;
    int nbr_arg;
    char *buildin[8];

    buildin = {"echo", "cd", "pwd", "export", "unset", "env", "exit", "\0"};
    nbr_arg = 0;
    cmd = ft_split(cmd_str, ' ');
    if (!ft_strnstr(BUILDEDCOMAND, cmd[0], 33))
    {
        if (!find_command(shell, cmd))
            return (FALSE);
    }
    return (TRUE);
}