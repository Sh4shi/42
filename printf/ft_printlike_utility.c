/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlike_utility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:07:14 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/24 04:23:42 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printpointer2(size_t ptr)
{
	write(1, "0x", 2);
	ft_putnbr_base(ptr, "0123456789abcdef");
}

void	ft_str_utility(t_flag *flag, char *str, int i)
{
	int	spaces;

	spaces = flag->wdt - ft_strlen(str);
	if (flag->dash == 1)
	{
		while (str[++i])
			flag->len += write(1, &str[i], 1);
		while (spaces)
		{
			flag->len += write(1, " ", 1);
			spaces--;
		}
	}
	else
	{
		while (spaces)
		{
			flag->len += write(1, " ", 1);
			spaces--;
		}
		while (str[++i])
			flag->len += write(1, &str[i], 1);
	}
}

void	ft_char_utility(t_flag *flag, char c)
{
	if (flag->dash == 1)
	{
		flag->len += write(1, &c, 1);
		while (flag->wdt - 1)
		{
			flag->len += write(1, " ", 1);
			flag->wdt--;
		}
	}
	else
	{
		while (flag->wdt - 1)
		{
			flag->len += write(1, " ", 1);
			flag->wdt--;
		}
		flag->len += write(1, &c, 1);
	}
}
