/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:11:39 by sdell-un          #+#    #+#             */
/*   Updated: 2022/02/03 06:27:57 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_reset_flag(t_flag *flag)
{
	flag->wdt = 0;
	flag->prcsn = 0;
	flag->zero_padd = 0;
	flag->point = 0;
	flag->dash = 0;  
	flag->sign = 0;
	flag->perc = 0;
	flag->space = 0;
	flag->hash = 0;
}
              
void	ft_init_flag(t_flag *flag)
{
	flag->wdt = 0;
	flag->prcsn = 0;
	flag->zero_padd = 0;
	flag->point = 0;
	flag->dash = 0;
	flag->sign = 0;
	flag->len = 0;
	flag->perc = 0;
	flag->space = 0;
	flag->hash = 0;
}

int	ft_readflag(char *str, int i, t_flag *flag)
{
	while (!ft_strchr("dsc%piuxX", str[i]))
	{
		if (str[i] == '.')
		{
			flag->point = 1;
			if (str[i + 1] == '*')
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
				while (ft_isdigit(str[i + 1]))
				{
					flag->prcsn = (flag->prcsn * 10) + (str[i + 1] - 48);
					i++;		
				}
			}
		}
		else if (str[i] == '0' && !ft_isdigit(str[i - 1]))
			flag->zero_padd = 1;
		else if (ft_isdigit(str[i]) || str[i] == '*')
		{
			if (str[i + 1] == '*')
			{
				flag->wdt = va_args(flag->args, int);
				if (flag->wdt < 0)
				{
					flag->dash = 1;
					flag->wdt *= -1;
				}
			}
			else
			{
				while (ft_isdigit(str[i + 1]))
				{
					flag->prcsn = (flag->prcsn * 10) + (str[i + 1] - 48); 
					i++;		
				}
			}  
		}
		else if (str[i] == '-')
			flag->dash = 1;
		else if (str[i] == '+')
			flag->sign = 1;
		else if (str[i] == ' ')
			flag->space = 1;
		else if (str[i] == '#')
			flag->hash = 1;
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
			i =	ft_readflag(str, (i + 1), flag);
			ft_printlike(str, i, flag);
			ft_reset_flag(flag);
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
