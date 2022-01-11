/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 03:52:59 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/11 05:34:33 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			while (heystack[i] = needle)
			{
				if (needle == '\0')
					return (*heystack[i - j]);
				i++;
				j++;
			}
			i++;
			return (0);
		}
		return (heystack);
	}
}
