/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:07:54 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/11 20:51:58 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char*) dst;
	s2 = (unsigned char*) src;
	if ((s1 - s2) < 0)
	{
		while (len > 0)
		{
			*s1++ = *s2++;
			len--;
		}
	}
	else
		while (len > 0)
		{
			s1[len - 1] = s2[len - 2];
			len--;
		}
	return (dst);
}
