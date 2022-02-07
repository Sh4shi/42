/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:07:23 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/04 19:18:18 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_check_precision(char *str, int i, t_flag *flag)
{
	flag->point = 1;
	if (str[i + 1] == '*')
	{
		flag->prcsn = va_args(flag->args, int);
		if (flag->prcsn < 0)
		{
			flag->prcsn = 0;
			flag->point = 0;
		}
	}
	else
	{
		while (ft_isdigit(str[i + 1]))
		{
			flag->prcsn = (flag->prcsn * 10) + (str[i + 1] - 48);
			i++;		
		}
	}
	return (i);
}

int	ft_check_wdt(char *str, int i, t_flag *flag)
{
	if (str[i + 1] == '*')
	{
		flag->wdt = va_args(flag->args, int);
		if (flag->wdt < 0)
		{
			flag->dash = 1;
			flag->wdt *= -1;
		}
	}
	else
	{
		while (ft_isdigit(str[i + 1]))
		{
			flag->prcsn = (flag->prcsn * 10) + (str[i + 1] - 48); 
			i++;		
		}
	}
	return (i);
}