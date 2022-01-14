/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:51:02 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/14 05:15:44 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void ft_putnbr_fd(int n, int fd)
{
	int m;
	unsigned int nbr;

	m = 1;
	if (n < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	while((n / m) > m)
	{
		nbr =  ((n / m) % 10) + '0';
		m *= 10;
		write(fd, &nbr, 1);
	}
	nbr += '0';
	write(fd, &nbr, 1);no
}*/
