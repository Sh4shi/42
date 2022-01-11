/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:29:29 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/11 20:51:33 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t strlcpy(char *dst, const char *src, size_t dstsize)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (dstsize != 0)
	{
		while (j < dstsize)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		return (dst);
	}
	return (0);
}
