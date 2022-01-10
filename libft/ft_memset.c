/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:59:42 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/10 17:08:04 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memset(void *str, int c, size_t len)
{
	unsigned char *ptr = str;
	while (len-- > 0)
		*ptr++ = c;
	return (str);
}
