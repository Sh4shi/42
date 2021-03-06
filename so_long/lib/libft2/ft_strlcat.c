/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:34:29 by mpatrini          #+#    #+#             */
/*   Updated: 2022/02/17 20:26:42 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	k = dest_len;
	i = 0;
	if (dest_len < size - 1 && size > 0)
	{
		while (src[i] && dest_len + i < size -1)
		{
			dst[k] = src[i];
			k++;
			i++;
		}
		dst[k] = 0;
	}
	if (dest_len >= size)
		dest_len = size;
	return (dest_len + src_len);
}
