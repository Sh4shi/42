/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:33:08 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/10 22:44:28 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	j;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	j = dstlen;
	i = 0;

	if (dstsize > 0 && dstlen <= dstsize - 1)
	{
		while (src[i] != '\0')
		{
			dst[j] = src[i];
			j++;
			i++;
		}
	}
	return ((destlen - 1) + srclen);
}
