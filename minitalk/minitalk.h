/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:10 by sdell-un          #+#    #+#             */
/*   Updated: 2022/03/16 03:27:08 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define CHR_BIT 8
# define SNDINGM "Sending message... 📤"
# define ARRIVED "Delivered message! ✅"
// # define PID_ERR "Invalid PID\nUsage: ./client [PID] ...\n"
# define ARG_ERR "Invalid arguments\n"
# define SOP_ERR "PID error or maybe server isn't running 🤯"
// # define WRT_MESS "Write a message to send:\nUsage: ./client [PID] [MSG]"

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void		check(int num, siginfo_t *inf, void *p);
// static void	reset(int cur_pid, int cli_pid, int i, char bite);
// static void	send(int pid, char *txt);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_atoi(const char *str);

#endif