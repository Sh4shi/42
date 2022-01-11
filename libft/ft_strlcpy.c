/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:29:29 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/10 23:09:50 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t strlcpy(char *dst, const char *src, size_t dstsize)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (dstsize != 0)
	{
		while ( j != dstsize - 1)
		{
			src[i] = dst[j];
			i++;
			j++;
		}
		return (dst)
	}
	return (0);
}
