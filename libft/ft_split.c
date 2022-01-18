/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:53:01 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/18 00:12:59 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			word++;
			i++;
		}
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	
}
