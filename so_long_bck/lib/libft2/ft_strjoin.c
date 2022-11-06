/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:34:40 by mpatrini          #+#    #+#             */
/*   Updated: 2022/02/17 20:26:38 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*r;

	if (!s1 || !s2)
		return (NULL);
	r = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!r)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
	{
		r[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2[++i])
	{
		r[j] = s2[i];
		j++;
	}
	r[j] = 0;
	return (r);
}
