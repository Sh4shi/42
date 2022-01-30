/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 09:06:29 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/30 11:13:42 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_readstr(const char *s, char c, t_flag *flag)
{
	size_t			size_substr;
	unsigned int	start_substr;
	int				i;
	char			*substr;
	
	i = 0;
	size_substr = 0;
	while (s[i] && s[i] != c)
		i++;
	start_substr = i;
	if (s[i] == c || s[i + 1] != '\0')
	{
		while (s[i] != 'd' || s[i] != 's' || s[i] != 'c' || s[i] != '%' || s[i] != 'p' 
			|| s[i] != 'i' || s[i] != 'u' || s[i] != 'x' || s[i] != 'X' || s[i] != '\0')
		{
			if (s[i] == '.')
				flag->point = 1;
			if (s[i] == '0')
				flag->zero_padd = 1;
			if (s[i] == '-')
				flag->dash = 1;
			if (s[i] == '+')
				flag->sign = 1;
			if (s[i] == ' ')
				flag->space = 1;
			if (s[i] == '*')
				flag->wdt = 1;
			if (s[i] == '.')
				flag->prcsn = 1;
			ft_putstr_fd("entro 1\n", 1);
			size_substr++;
			i++;
		}
	}
	ft_putstr_fd("sono qui \n", 1);
	substr = ft_substr(s, start_substr, size_substr);
	if (s[start_substr] == (char)c)
		return ((char *)s);
	return (NULL);
}

void	ft_init_flag(t_flag *args)
{
	args->wdt = 0;
	args->prcsn = 0;
	args->wdt = 0;
	args->prcsn = 0;
	args->zero_padd = 0;
	args->point = 0;
	args->dash = 0;
	args->sign = 0;
	args->len = 0;
	args->zeronbr = 0;
	args->perc = 0;
	args->space = 0;
}

int	ft_printf(const char *str, ...)
{
	char	*format;
	int		printed;
	va_list	args;
	t_flag	*flag;

	va_start(args, str);
	printf("prima: %s \n", str);
	format = ft_readstr(str, '%', flag);
	printf("dopo: %s \n", format);
	printed = 2;
	return (printed);
}

int main()
{
	char *str = "un cazzo";
	
	ft_printf("sharon %scosasalvi", str);
}
