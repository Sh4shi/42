/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prova.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:12:06 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/21 21:19:33 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *x, ...)
{
	va_list	arg;
	int		n;
	char	c;

	va_start(arg, x);
	n = va_arg(arg, int);
	c = va_arg(arg, int);
	printf("%d\n%c\n", n, c);
	va_end(arg);
}

int	main(void)
{
	ft_printf("ciao", 20, 'c');
}
