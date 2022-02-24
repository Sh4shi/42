/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlike.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 03:22:24 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/24 06:01:06 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printx(t_flag *flag)
{
	unsigned int	nbr;
	int				len;

	nbr = va_arg(flag->args, unsigned int);
	len = 2 + ft_count_len(nbr, 16);
	flag->len += len;
	if (flag->dash == 1 || len >= flag->wdt || flag->wdt == 0)
	{
		if (flag->hash == 1)
			write(1, "0x", 2);
		else
			len -= 2;
		if (flag->prcsn == 1)
		{
			ft_put_stuff(flag->prcsn - len, "0", flag);
		}
		ft_putnbr_base(nbr, "0123456789abcdef");
		if (flag->wdt)
		{
			if (flag->zero_padd)
				ft_put_stuff(flag->wdt - flag->len, "0", flag);
			else
				ft_put_stuff(flag->wdt - flag->len, " ", flag);
		}
	}
	else
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
				write(1, "0X", 2)
		}
		else
			len -= 2;
		if (flag->prcsn == 1)
		{
			ft_put_stuff(flag->prcsn - len, "0", flag);
		}
		ft_putnbr_base(nbr, "0123456789abcdef");
	}
}

void	ft_printpointer(t_flag *flag)
{
	size_t	ptr;
	int		len;

	ptr = va_arg(flag->args, size_t);
	len = 2 + ft_count_len(ptr, 16);
	flag->len += len;
	if (len >= flag->wdt)
	{
		write(1, "0x", 2);
		ft_putnbr_base(ptr, "0123456789abcdef");
	}
	else
	{
		if (flag->dash == 1)
		{
			ft_printpointer2(ptr);
			ft_put_stuff(flag->wdt - len, " ", flag);
		}
		else
		{
			ft_put_stuff(flag->wdt - len, " ", flag);
			write(1, "0x", 2);
			ft_putnbr_base(ptr, "0123456789abcdef");
		}
	}
}

void	ft_printchr(t_flag *flag)
{
	int		spaces;
	char	c;

	c = va_arg(flag->args, int);
	if (flag->wdt > 1)
	{
		spaces = flag->wdt - 1;
		ft_char_utility(flag, c);
	}
	else
		flag->len += write(1, &c, 1);
}

void	ft_printstr(t_flag *flag)
{
	char	*str;
	char	*new;
	int		i;

	str = va_arg(flag->args, char *);
	if (!str)
		str = "(null)";
	i = -1;
	if (flag->point == 1)
	{
		new = ft_substr(str, 0, flag->prcsn);
		if (flag->wdt > (int)ft_strlen(new))
			ft_str_utility(flag, new, i);
		else
			while (str[++i])
				flag->len += write(1, &new[i], 1);
		free(new);
	}
	else if (flag->wdt - (int)ft_strlen(str) > 0)
		ft_str_utility(flag, str, i);
	else
		while (str[++i])
			flag->len += write(1, &str[i], 1);
}
