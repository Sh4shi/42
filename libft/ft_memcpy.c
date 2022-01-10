/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:16:49 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/10 18:54:22 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	*d = dst;
	*s = src;
	while (n--)
		*d++ = *s++;
	return dst;
}
