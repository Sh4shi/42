/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:16:49 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/17 20:18:37 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tdst;
	char	*tsrc;
	size_t	i;

	i = 0;
	tdst = (char *) dst;
	tsrc = (char *) src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		tdst[i] = tsrc[i];
		i++;
	}
	return (tdst);
}
