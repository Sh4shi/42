/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 09:05:54 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/30 08:35:12 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_param
{
	int nbr_perc;
	char *substr;
}				t_param;

typedef struct s_flag
{
	va_list	args;
	t_param	param;
	int		wdt;
	int		prcsn;
	int		zero_padd;
	int		point;
	int		dash;
	int		sign;
	int		len;
	int		zeronbr;
	int		perc;
	int		space;
}				t_flag;

int		ft_printf(const char *str, ...);
void	ft_init_flag(t_flag *args);
char	*ft_readstr(const char *s, char c, t_flag *flag);

#endif