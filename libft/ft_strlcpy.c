/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:29:29 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/10 18:32:53 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	char *d;
	char *s;

	*d = dst;
	*s = src;
	if (dstsize != 0)
	{
		while ( src != '\0' && *d = dstsize - 1)
		{
			*d++ = *s++;
			return (dst);
		}
	}
	return (0);
}
