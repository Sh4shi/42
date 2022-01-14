/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:26:03 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/14 02:13:05 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;
	size_t	i;

	r = (void *)malloc(size * count);
	if (!r)
		return (NULL);
	i = 0;
	ft_bzero(r, size);
	return (r);
}
