/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:30:44 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/27 16:47:28 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_stuff(int i, char c, t_flag *flag)
{
	flag->len += i;
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

void	ft_putnbr_base(unsigned long long ptr, char *base)
{
	unsigned int	len;

	len = ft_strlen(base);
	if (ptr < len)
		write(1, &base[ptr], 1);
	else
	{
		ft_putnbr_base(ptr / len, base);
		ft_putnbr_base(ptr % len, base);
	}
}

int	ft_count_len(long long ptr, int base, t_flag *flag)
{
	int			len;
	long long	nbr;

	len = 1;
	nbr = 1;
	if (ptr < 0)
	{
		flag->minus = 1;
		flag->len += 1;
		ptr *= -1;
	}
	while (ptr / nbr >= base)
	{
		len++;
		nbr *= base;
	}
	return (len);
}

int	ft_count_len2(unsigned long long ptr, int base, t_flag *flag)
{
	int			len;
	unsigned long long	nbr;

	len = 1;
	nbr = 1;
	if (ptr < 0)
	{
		flag->minus = 1;
		flag->len += 1;
		ptr *= -1;
	}
	while (ptr / nbr >= (unsigned long long)base)
	{
		len++;
		nbr *= base;
	}
	return (len);
}