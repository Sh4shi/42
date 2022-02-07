/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 09:05:54 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/04 19:19:31 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

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
	int		hash;
}				t_flag;

int		ft_printf(const char *str, ...);
void	ft_init_flag(t_flag *flag);
int		ft_readflag(char *str, int i, t_flag *flag);
int		ft_check_precision(char *str, int i, t_flag *flag);
int		ft_check_wdt(char *str, int i, t_flag *flag)
void	ft_printlike(char *str, int i, t_flag *flag);
void	ft_printstr(t_flag *flag);
int		ft_print(char *s, t_flag *flag); //------------next
void	ft_reset_flag(t_flag *flag);

#endif
