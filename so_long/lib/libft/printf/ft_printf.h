/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 09:05:54 by sdell-un          #+#    #+#             */
/*   Updated: 2022/03/14 22:02:19 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
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
	int		minus;
	int		sign;
	int		len;
	int		perc;
	int		hash;
	int		casex;
}				t_flag;

int		ft_printf(const char *str, ...);
void	ft_init_flag(t_flag *flag);
int		ft_readflag(char *str, int i, t_flag *flag);
int		ft_check_precision(char *str, int i, t_flag *flag);
int		ft_check_wdt(char *str, int i, t_flag *flag);
void	ft_find_format(char *str, int i, t_flag *flag);
void	ft_printchr(t_flag *flag);
void	ft_char_utility(t_flag *flag, char c);
void	ft_printstr(t_flag *flag);
void	ft_str_utility(t_flag *flag, char *str, int i);
void	ft_printpointer(t_flag *flag);
void	ft_printpointer2(size_t ptr);
int		ft_count_len(long long ptr, int base, t_flag *flag);
void	ft_putnbr_base(unsigned long long ptr, char *base);
void	ft_put_stuff(int i, char c, t_flag *flag);
void	ft_printx(t_flag *flag);
void	ft_printx_dash(unsigned int nbr, int len, t_flag *flag);
void	ft_printx_off_dash(unsigned int nbr, int len, t_flag *flag);
void	ft_printu(t_flag *flag);
void	ft_printdi(t_flag *flag);
void	ft_printdi_dash(long long nbr, int len, t_flag *flag);
void	ft_printdi_off_dash(long long nbr, int len, t_flag *flag);
void	ft_reset_flag(t_flag *flag);
int		ft_count_len2(unsigned long long ptr, int base, t_flag *flag);
void	ft_printx_utils(t_flag *flag);

#endif
