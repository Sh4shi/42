/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:28:44 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/14 05:34:11 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	int		i;
	int		j;

	news = (char *)malloc(ft_strlen(s1) + (ft_strlen(s2) + 1));
	if (!news)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		news[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[i])
	{
		news[i] = s2[j];
		i++;
		j++;
	}
	news[i] = '\0';
	return (news);
}
