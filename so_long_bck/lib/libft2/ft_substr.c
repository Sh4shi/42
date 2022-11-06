/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:26:44 by mpatrini          #+#    #+#             */
/*   Updated: 2022/02/17 20:27:25 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		j;
	size_t	a;
	char	*r;

	if (!s)
		return (NULL);
	if (ft_strlen(s) > len)
		a = len;
	else
		a = ft_strlen(s);
	r = ft_calloc(a + 1, sizeof(char));
	if (!r)
		return (NULL);
	i = -1;
	j = -1;
	while (s[++i])
		if (i >= (int)start && ++j < (int)len)
			r[j] = s[i];
	r[j + 1] = 0;
	return (r);
}
