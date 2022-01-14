/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:42:44 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/14 00:43:00 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int carctr)
{
	unsigned char	crt;

	crt = (unsigned char)carctr;
	if (crt >= ' ' && crt <= '~')
		return (carctr);
	return (0);
}
