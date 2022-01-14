/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:00:06 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/14 05:37:10 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	int		start;
	char	*snew;

	end = ft_strlen(s1);
	start = 0;
	i = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	snew = (char *)malloc(end - start + 1);
	if (!snew)
		return (NULL);
	while (start <= end)
	{
		snew[i] = s1[start];
		start++;
		i++;
	}
	snew[i] = 0;
	return (snew);
}
