/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:37:46 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/19 07:19:38 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*snew;

	if (!s)
		return (NULL);
	i = 0;
	snew = ft_strdup(s);
	if (!snew)
		return (NULL);
	while (s[i])
	{
		snew[i] = (*f)(i, s[i]);
		i++;
	}
	return (snew);
}
