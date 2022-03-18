/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:44:45 by sdell-un          #+#    #+#             */
/*   Updated: 2022/03/16 03:59:26 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send(int pid, char *txt)
{
	int		i;
	int		bit;
	char	c;

	i = 0;
	while (txt[i])
	{
		bit = 0;
		c = txt[i];
		while (bit < 8)
		{
			if (c & 0x80)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit += 1;
			c <<= 1;
			usleep(200);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc > 1 && argc <= 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid > 0)
		{
			ft_putstr_fd(SNDINGM, 1);
			ft_putchar_fd('\n', 1);
			send(pid, argv[2]);
			usleep(500);
			ft_putstr_fd(ARRIVED, 1);
			ft_putchar_fd('\n', 1);
			exit(EXIT_SUCCESS);
		}
		else
		{
			ft_putstr_fd(SOP_ERR, 1);
			exit(EXIT_FAILURE);
		}
	}
	else
		ft_putstr_fd(ARG_ERR, 1);
}
