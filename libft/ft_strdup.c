/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:12:21 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/11 20:50:31 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *s1)
{
	char *s2;
	int i;
	int len;
	
	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof (*s2) * len);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (*s2);
}
