/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlike.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 03:22:24 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/22 03:23:29 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printpointer(t_flag *flag)
{
	
}

void	ft_printchr(t_flag *flag)
{
	int		spaces;
	char 	c;
	
	c = va_arg(flag->args, int);
	if (flag->wdt > 1)
	{
		spaces = flag->wdt - 1;
		ft_char_utility(flag, c);
	}
	else
		flag->len += write(1, &c, 1);
}

void	ft_printstr(t_flag *flag)
{
	char	*str;
	char	*new;
	int		i;

	str = va_arg(flag->args, char *);
	if (!str)
		str = "(null)";
	i = 0;
	if (flag->point == 1)
	{
		new = ft_substr(str, 0, (size_t *)flag->prcsn);
		if (flag->wdt > ft_strlen(new))
			ft_str_utility(flag, new, i);
		else
		{
			while (str)
			{
				flag->len += write(1, &new[i], 1);
				i++;
			}
		}
		free (new);
	}
	else
		ft_str_utility(flag, str, i);
}