/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:01:57 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/13 01:42:12 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (i--)
	{
		if (s[i] == c)
			return ((char *)(s + i));
	}
	return (NULL);
}
