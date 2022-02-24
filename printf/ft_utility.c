/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:30:44 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/24 05:10:15 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_put_stuff(int i, char c, t_flag *flag)
{
	flag->len += i;
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

void	ft_putnbr_base(long long ptr, char *base)
{
	int	len;
	int	count;

	len = ft_strlen(base);
	if (ptr < len)
		write(1, &base[ptr], 1);
	else
	{
		ft_putnbr_base(ptr / len, base);
		ft_putnbr_base(ptr % len, base);
	}
}

int	ft_count_len(long long ptr, int base)
{
	int			len;
	long long	nbr;

	len = 1;
	nbr = 1;
	if (ptr < 0)
	{
		len++;
		ptr *= -1;
	}
	while (ptr / nbr >= base)
	{
		len++;
		nbr *= base;
	}
	return (len);
}
