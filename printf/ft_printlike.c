/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlike.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 03:22:24 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/02 02:30:53 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printlike(char *s, int i, t_flag *flag)
{
	if (s[i] == 's')
		ft_printstr(s, flag);
	else if (s[i] == 'c')
		ft_printchr(s);
	else if (s[i] == 'd')

	else if (s[i] == 'p')

	else if (s[i] == 'i')

	else if (s[i] == 'u')

	else if (s[i] == 'x')

	else if (s[i] == 'X')
	
	else if (s[i]) == '%')
		ft_printchr('%');
}