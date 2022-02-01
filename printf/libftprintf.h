/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 09:05:54 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/01 05:35:54 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flag
{
	va_list	args;
	int		wdt;
	int		prcsn;
	int		zero_padd;
	int		point;
	int		dash;
	int		sign;
	int		len;
	int		perc;
	int		space;
}				t_flag;

int		ft_printf(const char *str, ...);
void	ft_init_flag(t_flag *args);
int		ft_readflag(char *s, int i, t_flag *flag);
int		ft_printlike(char *s, int i, t_flag *flag);
int		ft_printstr(char *s, int i, t_flag *flag);
void	ft_reset_flag(t_flag *args);

#endif