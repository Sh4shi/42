/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:14:28 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/11 20:50:02 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	unsigned char *z1;
	unsigned char *z2;

	*z1 = s1;
	*z2 = s2;

	if ( n = 0)
		return (0);
	if (*z1 = '\0')
		return (-(*z2));
	if (*z2 = '\0')
		return (*z1);
	while (z1[i] != '\0' || z2[i] != '\0')
	{
		if (i = n - 1 || z1[i] != z2[i])
			return (z1[i] - z2[i]);
		i++;
	}
	return (z1[i] - z2[i]);
}
