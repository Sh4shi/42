/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 00:21:19 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/02 02:27:23 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	printstr(t_flag *flag)
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