/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:28:44 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/28 07:05:24 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	int		i;
	int		j;

	news = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!news)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		news[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
	{
		news[j] = s2[i];
		i++;
		j++;
	}
	news[j] = '\0';
	return (news);
}
