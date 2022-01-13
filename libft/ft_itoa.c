/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:54:16 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/13 01:27:51 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_len(int n)
{
	unsigned int nbr;
	int len;
	int	m;

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
char *ft_itoa(int n)
{
	int m;
	unsigned int nbr;
	char *str;
	int i;
	int len;

	i = 0;
	m = 1;
	len = ft_len(n);
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	if (n < 0)
		len -= 3;
	else
		len -= 2;
	while(len > 0)
	{
		m *= 10;
		len--;
	}
	if (n < 0)
	{
		nbr = n * -1;
		str[i] = 45;
		i++;
	}
	else
		nbr = n;
	while (m > 0)
	{
		str[i] = ((nbr / m) % 10) + '0';
		m /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}