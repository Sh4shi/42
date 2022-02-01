/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:11:39 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/01 07:00:14 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_parsflag(char *s, int i, t_flag *flag)
{
		
}

void	ft_reset_flag(t_flag *args)
{
	args->wdt = 0;
	args->prcsn = 0;
	args->prcsn = 0;
	args->zero_padd = 0;
	args->point = 0;
	args->dash = 0;
	args->sign = 0;
	args->perc = 0;
	args->space = 0;
}
              
void	ft_init_flag(t_flag *args)
{
	args->wdt = 0;
	args->prcsn = 0;
	args->prcsn = 0;
	args->zero_padd = 0;
	args->point = 0;
	args->dash = 0;
	args->sign = 0;
	args->len = 0;
	args->perc = 0;
	args->space = 0;
}

int	ft_readflag(char *s, int i, t_flag *flag)
{
	while (!ft_strchr("dsc%piuxX", s[i]))
	{
		if (s[i] == '.')
		{
			flag->point = 1;
			if (s[i + 1] == '*')
			{
				flag->prcsn = va_args(flag->args, int);
				if (flag->prcsn < 0)
				{
					flag->prcsn = 0;
					flag->point = 0;
				}
			}
			else
			{
				
			}
		}
		else if (s[i] == '0' && !ft_isdigit(s[i - 1]))
			flag->zero_padd = 1;
		else if (ft_isdigit(s[i]) && s[i] == '*')
		{
			flag->wdt = 1;
		}
		else if (s[i] == '-')
			flag->dash = 1;
		else if (s[i] == '+')
			flag->sign = 1;
		else if (s[i] == ' ')
			flag->space = 1;
		i++;
	}	
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		printed;
	t_flag	*flag;
	int		i;

	flag = (t_flag *)malloc(sizeof(t_flag));
	if (!flag)
		return (0);
	ft_init_flag(flag);
	va_start(flag->args, str);
	i = 0;
	while (str[i])
	{	
		if (str[i] == '%')
		{
			ft_reset_flag(flag);
			i =	ft_readflag(str, (i + 1), flag);
			i = ft_printlike(str, i, flag);
		}
		else
			printed += write(1, str[i], 1);
		i++;
	}
	va_end(flag->args);
	printed += flag->len;
	free (flag);
	return (printed);
}
