/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:33:08 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/10 18:45:53 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	const size_t srclen;
	const size_t dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst, dstsize);
	while (
