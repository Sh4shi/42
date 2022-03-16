/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlike_utility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:07:14 by sdell-un          #+#    #+#             */
/*   Updated: 2022/03/14 22:04:09 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printx_off_dash(unsigned int nbr, int len, t_flag *flag)
{
	int	len2;

	if (len < flag->prcsn)
		len2 = flag->prcsn;
	if (flag->hash == 1)
		len2 += 2;
	if (flag->zero_padd && flag->wdt - len2 > 0)
		ft_put_stuff(flag->wdt - len2, 48, flag);
	else if (flag->wdt - len2 > 0)
		ft_put_stuff(flag->wdt - len2, 32, flag);
	if (flag->hash == 1)
		ft_printx_utils(flag);
	if (flag->point == 1 && flag->prcsn - len > 0)
		ft_put_stuff(flag->prcsn - len, 48, flag);
	if (flag->hash && flag->casex)
		ft_putnbr_base(nbr, "0123456789abcdef");
	else if (flag->hash)
		ft_putnbr_base(nbr, "0123456789ABCDEF");
	else
		ft_putnbr_base(nbr, "0123456789");
}

void	ft_printx_dash(unsigned int nbr, int len, t_flag *flag)
{
	if (flag->hash == 1)
	{
		if (flag->casex)
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		flag->len += 2;
	}
	if (flag->point == 1 && flag->prcsn - len > 0)
	{
		ft_put_stuff(flag->prcsn - len, 48, flag);
	}
	if (flag->hash && flag->casex)
		ft_putnbr_base(nbr, "0123456789abcdef");
	else if (flag->hash)
		ft_putnbr_base(nbr, "0123456789ABCDEF");
	else
		ft_putnbr_base(nbr, "0123456789");
	if (flag->wdt)
	{
		if (flag->zero_padd && flag->wdt - len > 0)
			ft_put_stuff(flag->wdt - flag->len, 48, flag);
		else if (flag->wdt - len > 0)
			ft_put_stuff(flag->wdt - flag->len, 32, flag);
	}
}

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
