/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlike_utility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:07:14 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/22 03:12:44 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_str_utility(t_flag *flag, char *str, int i)
{
	int		spaces;
	
	spaces = flag->wdt - ft_strlen(str);
	if (flag->dash == 1)
	{
		while (str)
		{
			flag->len += write(1, &str[i], 1);
			i++;
		}
		while (flag->wdt)
		{
			flag->len += write(1, " ", 1);
			flag->wdt--;
		}
	}
	else
	{
		while (flag->wdt)
		{
			flag->len += write(1, " ", 1);
			flag->wdt--;
		}
		while (str)
		{
			flag->len += write(1, &str[i], 1);
			i++;
		}
	}
}

void	ft_char_utility(t_flag *flag, char c)
{
	if (flag->dash == 1)
	{
		flag->len += write(1, &c, 1);
		while (flag->wdt)
		{
			flag->len += write(1, " ", 1);
			flag->wdt--;
		}
	}
	else
	{
		while (flag->wdt)
		{
			flag->len += write(1, " ", 1);
			flag->wdt--;
		}
		flag->len += write(1, &c, 1);
	}	
}