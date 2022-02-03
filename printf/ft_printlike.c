/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlike.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 03:22:24 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/03 06:19:54 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printstr(t_flag *flag)
{
	char *str;
	char *paddstr;
	
	str = va_arg(flag->args, char *);
	if (flag->point)
		str = ft_substr(str, 0, flag->prcsn);
	if (flag->wdt > ft_strlen(str))
	{
		paddstr = ft_memset(str, " ", (flag->wdt - ft_strlen(str)));
		if (flag->dash)
			str = ft_strjoin(paddstr, str);
		else
			str = ft_strjoin(str, paddstr);
	}
	ft_print(str, flag);
	free (str);
}
void	ft_printlike(char *str, int i, t_flag *flag)
{
	if (str[i] == 's')
		ft_printstr(flag);
	else if (str[i] == 'c')
		ft_printchr(flag);
	else if (str[i] == 'd')

	else if (str[i] == 'p')

	else if (str[i] == 'i')

	else if (str[i] == 'u')

	else if (str[i] == 'x')

	else if (str[i] == 'X')
	
	else if (str[i]) == '%')
		ft_printchr('%');
}