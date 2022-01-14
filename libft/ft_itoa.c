/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:54:16 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/14 05:24:38 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	unsigned int	nbr;
	int				len;
	int				m;

	m = 1;
	if (n < 0)
	{
		nbr = n * -1;
		len = 2;
	}
	else
	{
		len = 1;
		nbr = n;
	}
	while ((nbr / m) > 9)
	{
		m *= 10;
		len++;
	}
	return (len + 1);
}

int	ft_re_m(int len, int n)
{
	int	m;

	m = 1;
	if (n < 0)
		len -= 3;
	else
		len -= 2;
	while (len > 0)
	{
		m *= 10;
		len--;
	}
	return (m);
}

unsigned int	ft_nbr(int n)
{	
	unsigned int	nbr;

	if (n < 0)
		nbr = n * -1;
	else
		nbr = n;
	return (nbr);
}

char	*ft_itoa(int n)
{
	int				m;
	unsigned int	nbr;
	char			*str;
	int				i;
	int				len;

	i = -1;
	m = 1;
	len = ft_len(n);
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	m = ft_re_m(len, n);
	if (n < 0)
		str[++i] = 45;
	nbr = ft_nbr(n);
	while (m > 0)
	{
		str[++i] = ((nbr / m) % 10) + '0';
		m /= 10;
	}
	str[++i] = '\0';
	return (str);
}
