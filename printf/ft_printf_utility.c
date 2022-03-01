/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:07:23 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/27 09:55:38 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_find_format(char *str, int i, t_flag *flag)
{
	if (str[i] == 's')
		ft_printstr(flag);
	else if (str[i] == 'c')
		ft_printchr(flag);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_printdi(flag);
	else if (str[i] == 'p')
		ft_printpointer(flag);
	else if (str[i] == 'u')
		ft_printu(flag);
	else if (str[i] == 'x')
	{
		flag->casex = 1;
		ft_printx(flag);
	}	
	else if (str[i] == 'X')
		ft_printx(flag);
	else if (str[i] == '%')
		flag->len += write(1, "%", 1);
	ft_reset_flag(flag);
}

int	ft_check_precision(char *str, int i, t_flag *flag)
{
	flag->point = 1;
	if (str[i] == '*')
	{
		flag->prcsn = va_arg(flag->args, int);
		if (flag->prcsn < 0)
		{
			flag->prcsn = 0;
			flag->point = 0;
		}
	}
	else
	{
		while (ft_isdigit(str[i]))
		{
			flag->prcsn = (flag->prcsn * 10) + (str[i] - '0');
			i++;
		}
	}
	return (i - 1);
}

int	ft_check_wdt(char *str, int i, t_flag *flag)
{
	if (str[i] == '*')
	{
		flag->wdt = va_arg(flag->args, int);
		if (flag->wdt < 0)
		{
			flag->dash = 1;
			flag->wdt *= -1;
		}
	}
	else
		flag->wdt = (flag->wdt * 10) + (str[i] - 48);
	return (i);
}
