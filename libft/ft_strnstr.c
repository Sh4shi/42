/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 03:52:59 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/13 11:14:27 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *heystack, const char *needle, size_t len)
{
	int i;
	int j;

	i = 0;
	if (needle != 0 && needle <= heystack)
	{
		while(len--)
		{
			j = 0;
			while (heystack[i] == needle[j])
			{
				if (needle == '\0')
					return (heystack[i - j]);
				i++;
				j++;
			}
			i++;
			return (0);
		}
		return (heystack);
	}
}