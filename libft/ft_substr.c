/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:55:36 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/28 07:05:16 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	if (ft_strlen(s) > len)
		size = len;
	else
		size = ft_strlen(s);
	subs = (char *)malloc(sizeof(char) * (size + 1));
	if (!subs)
		return (NULL);
	i = -1;
	size = 0;
	while (s[++i])
	{
		if (size < len && i >= start)
		{
			subs[size] = s[i];
			size++;
		}
	}
	subs[size] = '\0';
	return (subs);
}
