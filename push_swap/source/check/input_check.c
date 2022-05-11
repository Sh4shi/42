/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:15:04 by sdell-un          #+#    #+#             */
/*   Updated: 2022/05/11 18:29:29 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	next_is_nbr(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i] < '0' && av[i] > '9') || (av[i] != '+' && av[i] != '-'))
			return (false);
		i++;
	}
	return (true);
}

bool	are_numbers(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (((av[i][j] != '+' && av[i][j] != '-') && av[i][j] != ' ') \
			|| (av[i][j] < '0' && av[i][j] > '9'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_string(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == ' ')
		{
			if (next_is_nbr(&av[i + 1]))
				return (true);
		}
		i++;
	}
	return (false);
}
