/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:09:20 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/13 05:49:06 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalnum(int argmnt)
{
	unsigned char arg;

	arg = (unsigned char)argmnt;
	if (ft_isalpha(arg) == 1 || ft_isdigit(arg) == 1)
		return (argmnt);
	return (0);
}