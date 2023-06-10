#include "./../include/minishell.h"

int main()
{
    t_shell shell;
    pid_t   pid;
    int     p_status;
    char  *cmd[] = {"/bin/ls", "-l", 0};

    ft_memset(&shell, 0, sizeof(t_shell)); //------make init struct functions
    shell.path = ft_split(getenv("PATH"), ':');
    while (STATUS)
    {
        if(get_cmd(&shell, readline(" > ")) == FALSE)
            error("Error!\ncommand not found ¯\\(°_o)/¯\n");
        pid = fork();
        if (pid < 0)
            printf("forking error\n");
        if (pid == 0)
        {
            if (execve("/bin/ls", cmd, environ) == -1)
                exit(EXIT_FAILURE);
            exit(EXIT_SUCCESS);
        }
        if (pid > 0)
        {
            while(!WIFEXITED(p_status))
                waitpid(pid, &p_status, WUNTRACED);
        }
        printf("process nbr: %d\n", pid);
        printf("exit status: %d\n", WEXITSTATUS(p_status));
    }
}