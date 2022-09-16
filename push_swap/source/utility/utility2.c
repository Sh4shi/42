/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:54:11 by sdell-un          #+#    #+#             */
/*   Updated: 2022/08/29 00:04:18 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	max(int one, int two)
{
	if (one > two)
		return (one);
	else
		return (two);
}

int	min(int one, int two)
{
	if (one < two)
		return (one);
	else
		return (two);
}

int	abs(int one)
{
	if (one > 0)
		return (one);
	else
		return (-one);
}
