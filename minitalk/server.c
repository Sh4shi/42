/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:16:26 by sdell-un          #+#    #+#             */
/*   Updated: 2022/03/16 01:07:13 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	reset(int cur_pid, int cli_pid, int i, char bit)
{
	cli_pid = cur_pid;
	i = 0;
	bit = 0;
}

void	check(int num, siginfo_t *inf, void *p)
{
	static int		i;
	static char		bit;
	static int		cli_pid;
	static int		cur_pid;

	(void)p;
	if (!cli_pid)
		cli_pid = inf->si_pid;
	cur_pid = inf->si_pid;
	if (cur_pid != cli_pid)
		reset(&cur_pid, &cli_pid, &i, &bit);
	if (num == SIGUSR2)
	{
		(bit |= (0x80 >> i));
		i++;
	}
	else
		i++;
	if (i == 8)
	{
		write (1, &bit, 1);
		i = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	info;
	int					pid;

	(void)argv;
	pid = getpid;
	info.sa_sigaction = check;
	info.sa_flags = SA_SIGINFO;
	if (argc == 1)
	{
		ft_putstr_fd("PID: ", 1);
		ft_putnbr_fd(pid, 1);
		ft_putchar_fd('\n', 1);
		while (1)
		{
			sigaction(SIGUSR1, &info, 0);
			sigaction(SIGUSR2, &info, 0);
			pause();
		}
	}
	exit(EXIT_FAILURE);
}
