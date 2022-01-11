/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:55:36 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/11 20:49:11 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *subs;
	unsigned int i;

	if (len > 0)
	{
		subs = (char *)malloc(sizeof (*s) * len);
		i = 0;
		while (s[start] < len)
		{
			subs[i] = s[start];
			start++;
			i++;
		}
			return (subs);
	}
	return (NULL);
}