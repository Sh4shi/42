/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlike_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:53:44 by sdell-un          #+#    #+#             */
/*   Updated: 2022/03/01 19:53:48 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdi_off_dash(long long nbr, int len, t_flag *flag)
{
	int sp;
	int dif;

	dif = flag->prcsn - len;
	if (dif < 0)
		dif = 0;
	sp = flag->wdt - (dif + len);
	if (flag->minus || flag->sign)
		sp -= 1;
	if (flag->wdt && flag->wdt > dif + len)
	{
		if (flag->zero_padd)
			ft_put_stuff(sp, 48, flag);
		else
			ft_put_stuff(sp, 32, flag);
	}
	if (flag->minus)
		write(1, "-", 1);
	else if (flag->sign)
		flag->len += write(1, "+", 1);
	if (dif > 0 && flag->prcsn != 0 && nbr != 0)
		ft_put_stuff(flag->prcsn - len, 48, flag);
	ft_putnbr_base(nbr, "0123456789");
}

void	ft_printdi_dash(long long nbr, int len, t_flag *flag)
{
	int dif;
	int sp;

	if (!(flag->prcsn && flag->point))
		dif = 0;
	else
		dif = flag->prcsn - len;
	sp = flag->wdt - (dif + len);
	if (flag->minus)
		write(1, "-", 1);
	else if (flag->sign)
		flag->len += write(1, "+", 1);
	if (flag->minus || flag->sign)
		sp -= 1;
	if (dif > 0 && flag->prcsn != 0 && nbr != 0)
		ft_put_stuff(dif, 48, flag);
	ft_putnbr_base(nbr, "0123456789");
	if (dif < 0)
		dif = 0;
	if (flag->wdt && flag->wdt > dif + len)
	{
		if (flag->zero_padd)
			ft_put_stuff(sp, 48, flag);
		else
			ft_put_stuff(sp, 32, flag);
	}
}

void	ft_printdi(t_flag *flag)
{
	long long nbr;
	int	len;

	nbr = va_arg(flag->args, int);
	len = ft_count_len(nbr, 10, flag);
	flag->len += len;
	if (nbr < 0)
		nbr *= -1;
	if (flag->dash == 1 && (flag->wdt || flag->point))
		ft_printdi_dash(nbr, len, flag);
	else if (flag->wdt || flag->point)
		ft_printdi_off_dash(nbr, len, flag);
	else if (flag->minus || flag->sign)
	{
		if (flag->minus)
			write(1, "-", 1);
		if (flag->sign)
			flag->len += write(1, "+", 1);
		ft_putnbr_base(nbr, "0123456789");
	}
	else
		ft_putnbr_base(nbr, "0123456789");
}
