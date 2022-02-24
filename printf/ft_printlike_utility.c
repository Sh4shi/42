/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlike_utility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:07:14 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/24 06:23:13 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printx_off_dash(unsigned int nbr, int len, t_flag *flag)
{
	if (flag->zero_padd)
		ft_put_stuff(flag->wdt - flag->len, "0", flag);
	else
		ft_put_stuff(flag->wdt - flag->len, " ", flag);
	if (flag->hash == 1)
	{
		if (flag->casex)
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
	}
	else
		len -= 2;
	if (flag->prcsn == 1)
	{
		ft_put_stuff(flag->prcsn - len, "0", flag);
	}
	if (flag->casex)
		ft_putnbr_base(nbr, "0123456789abcdef");
	else
		ft_putnbr_base(nbr, "0123456789ABCDEF");
}

void	ft_printx_dash(unsigned int nbr, int len, t_flag *flag)
{
	if (flag->hash == 1)
	{
		if (flag->casex)
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
	}
	else
		len -= 2;
	if (flag->prcsn == 1)
	{
		ft_put_stuff(flag->prcsn - len, "0", flag);
	}
	if (flag->casex)
		ft_putnbr_base(nbr, "0123456789abcdef");
	else
		ft_putnbr_base(nbr, "0123456789ABCDEF");
	if (flag->wdt)
	{
		if (flag->zero_padd)
			ft_put_stuff(flag->wdt - flag->len, "0", flag);
		else
			ft_put_stuff(flag->wdt - flag->len, " ", flag);
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
