/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 03:52:59 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/14 08:06:45 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = 0;
	j = 0;
	a = 0;
	if (*n == 0)
		return ((char *)h);
	while (h[i] && i < len)
	{
		while (h[i] == n[j] && n[j] && h[i] && i < len)
		{
			i++;
			j++;
			if (n[j] == 0)
				return ((char *)(h + (i - j)));
		}
		j = 0;
		a++;
		i = a;
	}
	return (NULL);
}
